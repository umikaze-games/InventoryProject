// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Widgets/HUD/Inv_HUDWidget.h"
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
	void PrimaryInteract();
	void CreateHUDWidget();
	
	UPROPERTY(EditDefaultsOnly,Category="Inventory")	
	TObjectPtr<class UInputMappingContext> DefaultIMC;

	UPROPERTY(EditDefaultsOnly,Category="Inventory")	
	TObjectPtr<class UInputAction> PrimaryInteractAction;

	UPROPERTY(EditDefaultsOnly,Category="Inventory")
	TSubclassOf<UInv_HUDWidget>HUDWidgetClass;

	UPROPERTY()
	TObjectPtr<UInv_HUDWidget> HUDWidget;
	
};