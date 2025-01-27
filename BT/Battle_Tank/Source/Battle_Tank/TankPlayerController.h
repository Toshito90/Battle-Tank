// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLE_TANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATank* GetControlledTank() const;
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	void AimTowardsCrosshair();

	//Return OUT Parameter

	bool GetSightRayHitLocation(FVector& outHitLocation) const;

	bool GetLookDirection(FVector2D screenLocation, FVector& lookDirection) const;

	bool GetLookVectorHitLocation(FVector lookDirection, FVector& hitLocation) const;

	UPROPERTY(EditAnywhere)
	float crossHairLocation_X = 0.5;

	UPROPERTY(EditAnywhere)
	float crossHairLocation_Y = 0.3333;

	UPROPERTY(EditAnywhere)
	float lineTraceRange = 1000000;
};
