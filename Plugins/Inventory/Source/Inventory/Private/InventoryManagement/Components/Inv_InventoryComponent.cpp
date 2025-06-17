
#include "InventoryManagement/Components/Inv_InventoryComponent.h"

#include "Widgets/Invetory/InvetoryBase/Inv_InventoryBase.h"

UInv_InventoryComponent::UInv_InventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UInv_InventoryComponent::BeginPlay()
{
	Super::BeginPlay();
	ConstructInventory();
}

void UInv_InventoryComponent::ConstructInventory()
{
	OwningController=Cast<APlayerController>(GetOwner());
	OwningController = Cast<APlayerController>(GetOwner());
	checkf(OwningController.IsValid(), TEXT("Inventory Component should have a Player Controller as Owner."))
	if (!OwningController->IsLocalController()) return;

	InventoryMenu = CreateWidget<UInv_InventoryBase>(OwningController.Get(), InventoryMenuClass);
	InventoryMenu->AddToViewport();
}
