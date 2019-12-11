// Fill out your copyright notice in the Description page of Project Settings.


#include "Cubemon.h"
#include "Components/StaticMeshComponent.h"
#include "WidgetComponent.h"
#include "CubemonHP.h"
#include "Kismet/GameplayStatics.h"
#include "E1211XUNRProjectile.h"
#include "Engine/Engine.h"

// Sets default values
ACubemon::ACubemon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	SetRootComponent(StaticMesh);

	HeadMesh = CreateDefaultSubobject<UStaticMeshComponent>("HeadMesh");
	HeadMesh->SetupAttachment(StaticMesh);

	HealthWidget = CreateDefaultSubobject<UWidgetComponent>("HealthWidget");
	HealthWidget->SetCollisionResponseToAllChannels(ECR_Ignore);
	HealthWidget->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void ACubemon::BeginPlay()
{
	Super::BeginPlay();
	Cast<UCubemonHP>(HealthWidget->GetUserWidgetObject())->Cubemon = this;
}

// Called every frame
void ACubemon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	APlayerCameraManager* camera = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0);
	HealthWidget->SetWorldRotation(camera->GetCameraRotation());
	HealthWidget->AddLocalRotation(FRotator(0, 180, 0));

}

void ACubemon::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved,
	FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	auto projectile = Cast<AE1211XUNRProjectile>(Other);
	if(projectile != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, TEXT("dwad"));
		HP -= 10;
	}
}



