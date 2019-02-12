// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	auto playerTank = GetPlayerTank();
	if (!playerTank) {
		UE_LOG(LogTemp, Warning, TEXT("AI Controller can't find a player Tank!"))
	}else{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller found player: %s"), *(playerTank->GetName()))
	}
}

void ATankAIController::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);
	if (GetPlayerTank()) {


		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());


	}
}

ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const {
	auto playerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if(!playerPawn) {
		return nullptr;
	}

	return Cast<ATank>(playerPawn);
}