// Fill out your copyright notice in the Description page of Project Settings.


#include "BoomBox.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "E1211XUNRCharacter.h"
#include "Engine/Engine.h"

// Sets default values
ABoomBox::ABoomBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	staticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	SetRootComponent(staticMesh);
}

// Called when the game starts or when spawned
void ABoomBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABoomBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ACharacter* player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	AE1211XUNRCharacter* mainCharacter = Cast<AE1211XUNRCharacter>(player);
	if(GetDistanceTo(mainCharacter) <= distance)
	{
		currentTime += DeltaTime;
		if(currentTime>=period)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, FString::FromInt(period) + "    " + FString::FromInt(currentTime));


			currentTime = 0;
			mainCharacter->LaunchCharacter(FVector(0.f, 0.f, 1000.f), false, false);
			if (ParticleSystem)
			{
				UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ParticleSystem, GetActorLocation());

			}
		}
		
	}

}

