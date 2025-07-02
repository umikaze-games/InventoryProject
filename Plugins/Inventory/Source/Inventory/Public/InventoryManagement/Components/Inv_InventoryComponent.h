// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Inv_InventoryComponent.generated.h"

class UInv_InventoryItem;
class UInv_InventoryBase;
class UInv_ItemComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInventoryItemChange, UInv_InventoryItem*, Item);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FNoRoomInInventory);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent),Blueprintable)
class INVENTORY_API UInv_InventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UInv_InventoryComponent();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category = "Inventory")
	void TryAddItem(UInv_ItemComponent* ItemComponent);
	

	FInventoryItemChange OnItemAdded;
	FInventoryItemChange OnItemRemoved;
	FNoRoomInInventory NoRoomInInventory;
	
	void ToggleInventoryMenu();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	bool bInventoryMenuOpen;
	
	TWeakObjectPtr<APlayerController>OwningController;
	
	UPROPERTY()
	TObjectPtr<UInv_InventoryBase>InventoryMenu;
	
	UPROPERTY(EditAnywhere,Category="Inventory")
	TSubclassOf<UInv_InventoryBase>InventoryMenuClass;

	void ConstructInventory();
	void OpenInventoryMenu();
	void CloseInventoryMenu();
	

};
