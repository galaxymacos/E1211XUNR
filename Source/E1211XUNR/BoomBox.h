// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BoomBox.generated.h"

UCLASS()
class E1211XUNR_API ABoomBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoomBox();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* staticMesh;

	UPROPERTY(EditAnywhere)
		int distance = 300;

	UPROPERTY(EditAnywhere)
		float period = 2.f;

	UPROPERTY(VisibleAnywhere)
		float currentTime;

	UPROPERTY(EditAnywhere)
	UParticleSystem* ParticleSystem;

	UPROPERTY(EditAnywhere)
		float LaunchForce = 1000.f;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
