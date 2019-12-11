// Fill out your copyright notice in the Description page of Project Settings.


#include "GeneratorPod.h"
#include "Components/StaticMeshComponent.h"
#include "E1211XUNRCharacter.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AGeneratorPod::AGeneratorPod()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	SetRootComponent(StaticMesh);
}

// Called when the game starts or when spawned
void AGeneratorPod::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGeneratorPod::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(isGeneratingEnergy && !CheckPlayerStillInRange())
	{
		isGeneratingEnergy = false;
	}

	if(isGeneratingEnergy)
	{
		currentTime += DeltaTime;
		if(currentTime>=1.f)
		{
			currentTime = 0.f;
			ACharacter* player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
			auto mainCharacter = Cast<AE1211XUNRCharacter>(player);
			if(mainCharacter)
			{
				mainCharacter->energy += speed;
			}
			
		}
	}
}

void AGeneratorPod::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp,
	bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	auto mainCharacter = Cast<AE1211XUNRCharacter>(Other);
	if(mainCharacter != nullptr)
	{
		isGeneratingEnergy = true;
	}
}

bool AGeneratorPod::CheckPlayerStillInRange()
{
	ACharacter* mainCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	if(GetDistanceTo(mainCharacter)<=chargeRange)
	{
		return true;
	}
	return false;
}



