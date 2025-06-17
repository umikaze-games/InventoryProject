// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InventoryManagement/Components/Inv_InventoryComponent.h"
#include "Widgets/HUD/Inv_HUDWidget.h"
#include "Inv_PlayerController.generated.h"

UCLASS()
class INVENTORY_API AInv_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AInv_PlayerController();

	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION(BlueprintCallable)
	void ToggleInventory();
	
protected:
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;
private:
	void PrimaryInteract();
	void CreateHUDWidget();
	void TraceForItem();
	
	TWeakObjectPtr<UInv_InventoryComponent>InventoryComponent;
	
	UPROPERTY(EditDefaultsOnly,Category="Inventory")	
	TObjectPtr<class UInputMappingContext> DefaultIMC;

	UPROPERTY(EditDefaultsOnly,Category="Inventory")	
	TObjectPtr<class UInputAction> PrimaryInteractAction;

	UPROPERTY(EditDefaultsOnly,Category="Inventory")	
	TObjectPtr<class UInputAction> ToggleInventoryAction;
	
	UPROPERTY(EditDefaultsOnly,Category="Inventory")
	TSubclassOf<UInv_HUDWidget>HUDWidgetClass;

	UPROPERTY()
	TObjectPtr<UInv_HUDWidget> HUDWidget;

	UPROPERTY(EditDefaultsOnly,Category="Inventory")
	double TraceLength;

	UPROPERTY(EditDefaultsOnly,Category="Inventory")
	TEnumAsByte<ECollisionChannel> ItemTraceChannel;

	TWeakObjectPtr<AActor> ThisActor;
	TWeakObjectPtr<AActor> LastActor;
	
};