// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Paintbullet.generated.h"


UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TPSPROJECT_API UPaintbullet : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPaintbullet();

	UPROPERTY(EditAnywhere, Category = Shoot)
		float speed;
	UPROPERTY(EditAnywhere, Category = Shoot)
		UBlueprint* Decal;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void Move();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
};
