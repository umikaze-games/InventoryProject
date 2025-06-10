// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Inv_PlayerController.h"
#include "Inventory.h"

void AInv_PlayerController::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(logInventory, Log, TEXT("Player Controller Begin play"));
}
