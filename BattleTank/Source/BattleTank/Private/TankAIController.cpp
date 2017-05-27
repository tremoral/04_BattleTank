// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank/Public/TankAIController.h"
#include "BattleTank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("AIController not possessing a tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AIController possessing: %s"), *(ControlledTank->GetName()));
	}

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("AIController didnt found player tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("player tanks is: %s"), *(PlayerTank->GetName()));
	}
	
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		// TODO Move towards the player

		//aim towards the player
		GetControlledTank()->Aimat(GetPlayerTank()->GetActorLocation());
		//fire if ready
	}
	//start the tank moving the varrel so tha a show woult it where
	//the crosshair intersects the world
	//AimTowardsCrosshair();
	//UE_LOG(LogTemp, Warning, TEXT("PlayerController ticking"));
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) {
		return nullptr;
	}
	return Cast<ATank>(PlayerPawn);
}



