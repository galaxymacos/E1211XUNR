// Fill out your copyright notice in the Description page of Project Settings.


#include "EnergyDrink.h"
#include "Components/StaticMeshComponent.h"
#include "E1211XUNRCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"

// Sets default values
AEnergyDrink::AEnergyDrink()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	SetRootComponent(StaticMesh);
	
}

// Called when the game starts or when spawned
void AEnergyDrink::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnergyDrink::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	const FRotator rotator(0, 10.f, 0);
	AddActorLocalRotation(rotator);
}

void AEnergyDrink::NotifyActorBeginOverlap(AActor* OtherActor)
{
	
}

void AEnergyDrink::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp,
	bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	auto mainCharacter = Cast<AE1211XUNRCharacter>(Other);
	if (mainCharacter != nullptr)
	{
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), pickupSound, GetActorLocation(), GetActorRotation());
		mainCharacter->energy += 10;
		mainCharacter->energyDrinkComsumed++;
		if (mainCharacter->energyDrinkComsumed >= 3)
		{
			mainCharacter->ClearExhaust();
		}
		Destroy();
	}
}

