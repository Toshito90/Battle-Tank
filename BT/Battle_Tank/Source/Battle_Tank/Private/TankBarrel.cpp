// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::Elevate(float degreesPerSecond) {
	UE_LOG(LogTemp, Warning, TEXT("Barrel->Elevate() called at speed %f."), degreesPerSecond)
}