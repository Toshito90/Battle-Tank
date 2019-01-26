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

ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}