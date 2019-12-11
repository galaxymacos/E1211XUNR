// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GeneratorPod.generated.h"

UCLASS()
class E1211XUNR_API AGeneratorPod : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGeneratorPod();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere)
		int speed = 10;

	UPROPERTY(VisibleAnywhere)
		float currentTime;

	UPROPERTY(VisibleAnywhere)
		bool isGeneratingEnergy;

	UPROPERTY(EditAnywhere)
		float chargeRange = 200.f;

	
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;

	bool CheckPlayerStillInRange();
};
