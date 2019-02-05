// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "Battle_Tank.h"

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();

	auto controlledTank = GetControlledTank();

	if (!controlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a tank!"))
	} else {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing %s"), *(controlledTank->GetName()))
	}

	
}

void ATankPlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair() {
	if (!GetControlledTank()) {
		return;
	}

	FVector hitLocation; //Out Parameter
	if (GetSightRayHitLocation(hitLocation)) {
		//UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *hitLocation.ToString())
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& outHitLocation) const {
	//outHitLocation = FVector(1.0);
	int32 viewPortSizeX, viewPortSizeY;

	GetViewportSize(viewPortSizeX, viewPortSizeY);
	auto screenLocation = FVector2D(viewPortSizeX * crossHairLocation_X, viewPortSizeY * crossHairLocation_Y);

	//UE_LOG(LogTemp, Warning, TEXT("Screen Location: %s"), *screenLocation.ToString())

	return true;
}