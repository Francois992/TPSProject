// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DecalActor.h"
#include "Components/DecalComponent.h"
#include "GameFramework/Actor.h"
#include "PaintShoot.generated.h"

UCLASS()
class TPSPROJECT_API APaintShoot : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APaintShoot();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = setup)
		USceneComponent* rootScene;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = setup)
		UStaticMeshComponent* mesh;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = Shoot)
		float speed;
	UPROPERTY(EditAnywhere, Category = Shoot)
		TSubclassOf<ADecalActor> DecalBlueprint;

	UFUNCTION(BlueprintCallable)
		void SplashPaint(FVector normal);
};
