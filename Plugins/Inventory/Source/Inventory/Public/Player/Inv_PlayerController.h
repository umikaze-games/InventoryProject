// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Inv_PlayerController.generated.h"


/**
 * 
 */
UCLASS()
class INVENTORY_API AInv_PlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;
private:
	UFUNCTION()
	void PrimaryInteract();
	
	UPROPERTY(EditDefaultsOnly,Category="Inventory")	
	TObjectPtr<class UInputMappingContext> DefaultIMC;

	UPROPERTY(EditDefaultsOnly,Category="Inventory")	
	TObjectPtr<class UInputAction> PrimaryInteractAction;
};