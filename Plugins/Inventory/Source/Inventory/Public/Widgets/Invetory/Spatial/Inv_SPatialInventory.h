// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/Invetory/InvetoryBase/Inv_InventoryBase.h"
#include "Inv_SPatialInventory.generated.h"

class UInv_InventoryGrid;
class UWidgetSwitcher;

UCLASS()
class INVENTORY_API UInv_SPatialInventory : public UInv_InventoryBase
{
	GENERATED_BODY()

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UWidgetSwitcher> Switcher;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UInv_InventoryGrid> Grid_Equippables;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UInv_InventoryGrid> Grid_Consumables;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UInv_InventoryGrid> Grid_Craftables;
};
