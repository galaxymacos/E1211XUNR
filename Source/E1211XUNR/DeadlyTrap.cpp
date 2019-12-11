// Fill out your copyright notice in the Description page of Project Settings.


#include "DeadlyTrap.h"
#include "Components/StaticMeshComponent.h"
#include "E1211XUNRCharacter.h"
#include "Engine/Engine.h"

// Sets default values
ADeadlyTrap::ADeadlyTrap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>("mesh");
	SetRootComponent(mesh);
	mesh->SetSimulatePhysics(true);

}

// Called when the game starts or when spawned
void ADeadlyTrap::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADeadlyTrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// void ADeadlyTrap::NotifyActorBeginOverlap(AActor* OtherActor)
// {
// 	auto mainCharacter = Cast<AE1211XUNRCharacter>(OtherActor);
// 	if(mainCharacter!=nullptr)
// 	{
// 		mainCharacter->energy -= damage;
// 		Destroy();
// 	}
// 	if (GEngine)
// 	{
// 		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, "overlapping");
// 	}
// }

void ADeadlyTrap::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved,
	FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	auto mainCharacter = Cast<AE1211XUNRCharacter>(Other);
	if (mainCharacter != nullptr)
	{
		FString playerHP = FString::FromInt(mainCharacter->energy);
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, playerHP);
		if (mainCharacter->isExhausted)
		{
			mainCharacter->energy -= damage*2;
		}
		else
		{
			mainCharacter->energy -= damage;
			mainCharacter->isExhausted = true;
		}
		playerHP = FString::FromInt(mainCharacter->energy);
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, playerHP);

		
		Destroy();
	}
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, "hitting");
	}
}

