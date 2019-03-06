// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BluePrintSpawnableComponent), hidecategories("Collision"))
class BATTLE_TANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()


public:
	void Elevate(float relativeSpeed);


private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float maxDegreesPerSecond = 20;

	UPROPERTY(EditAnywhere, Category = Setup)
	float maxElevationDegrees = 0;

	UPROPERTY(EditAnywhere, Category = Setup)
	float minElevationDegrees = 0;

};
