// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

void ATankAIController::BeginPlay() 
{
	Super::BeginPlay();

	ATank* PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		UE_LOG(LogTemp, Error, TEXT("Player tank not found"));
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Tank is %s Pawn"), *(PlayerTank->GetName()));
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	APawn* PlayerTank = (GetWorld()->GetFirstPlayerController()->GetPawn());
	if (!PlayerTank) 
		return nullptr;


	return Cast<ATank>(PlayerTank);
}
