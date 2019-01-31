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


}