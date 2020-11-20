// Fill out your copyright notice in the Description page of Project Settings.


#include "Engine/DecalActor.h"
#include "Components/DecalComponent.h"
#include "PaintShoot.h"

// Sets default values
APaintShoot::APaintShoot()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	rootScene = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = rootScene;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	mesh->SetupAttachment(RootComponent);

	
}

// Called when the game starts or when spawned
void APaintShoot::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APaintShoot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector location = GetActorLocation();

	location += GetActorForwardVector() * speed * DeltaTime;

	SetActorLocation(location);

}

void APaintShoot::SplashPaint(FVector normal) {
	FActorSpawnParameters SpawnInfo;
	AActor* spawnedDecal;
	spawnedDecal = GetWorld()->SpawnActor<ADecalActor>(DecalBlueprint->GetClass(), GetActorLocation(), GetActorRotation(), SpawnInfo);
	Destroy();
	
}

