// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Inv_InventoryComponent.generated.h"


class UInv_InventoryBase;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent),Blueprintable)
class INVENTORY_API UInv_InventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UInv_InventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:

	void ConstructInventory();

	TWeakObjectPtr<APlayerController>OwningController;
	
	UPROPERTY()
	TObjectPtr<UInv_InventoryBase>InventoryMenu;

	UPROPERTY(EditAnywhere,Category="Inventory")
	TSubclassOf<UInv_InventoryBase>InventoryMenuClass;
};
