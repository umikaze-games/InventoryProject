// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Inv_PlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Inventory.h"
#include "Items/Components/Inv_ItemComponent.h"
#include "Kismet/GameplayStatics.h"

AInv_PlayerController::AInv_PlayerController()
{
	PrimaryActorTick.bCanEverTick = true;
	TraceLength=500.f;
	ItemTraceChannel=ECC_GameTraceChannel1;
}

void AInv_PlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	TraceForItem();
}

void AInv_PlayerController::BeginPlay()
{
	Super::BeginPlay();

	UEnhancedInputLocalPlayerSubsystem*SubSystem=ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	
	if (IsValid(SubSystem))
	{
		SubSystem->AddMappingContext(DefaultIMC,0);
	}
	CreateHUDWidget();
}

void AInv_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent*EnhancedInputComponent=CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(PrimaryInteractAction,ETriggerEvent::Started,this,&AInv_PlayerController::PrimaryInteract);
}

void AInv_PlayerController::PrimaryInteract()
{
	if (!IsValid(GEngine) || !IsValid(GEngine->GameViewport)) return;
	FVector2D ViewpointSize;
	GEngine->GameViewport->GetViewportSize(ViewpointSize);
	const FVector2D ViewportCenter = ViewpointSize*0.5f;
	FVector TraceStart, Forward;
	if (!UGameplayStatics::DeprojectScreenToWorld(this,ViewportCenter,TraceStart,Forward))return;
	const FVector TraceEnd = TraceStart+Forward*TraceLength;
	FHitResult HitResult;
	GetWorld()->LineTraceSingleByChannel(HitResult,TraceStart,TraceEnd,ItemTraceChannel);
	LastActor=ThisActor;
	ThisActor=HitResult.GetActor();
	UE_LOG(LogTemp,Warning,TEXT("Stopped tracing a last actor."));

	if (!ThisActor.IsValid())
	{
		if (IsValid(HUDWidget)) HUDWidget->HidePickupMessage();
	}
	if (ThisActor==LastActor)return;
	
	if (ThisActor.IsValid())
	{
		UE_LOG(LogTemp,Warning,TEXT("Started tracing a new actor."));
		UInv_ItemComponent* ItemComponent = ThisActor->FindComponentByClass<UInv_ItemComponent>();
		if (!IsValid(ItemComponent)) return;

		if (IsValid(HUDWidget)) HUDWidget->ShowPickupMessage(ItemComponent->GetPickupMessage());
	}

	if (LastActor.IsValid())
	{
		UE_LOG(LogTemp,Warning,TEXT("Stopped tracing a last actor."));
	}
}

void AInv_PlayerController::CreateHUDWidget()
{
	if (!IsLocalController())return;
	HUDWidget=CreateWidget<UInv_HUDWidget>(this,HUDWidgetClass);
	if (IsValid(HUDWidget))
	{
		HUDWidget->AddToViewport();
	}
		
}

void AInv_PlayerController::TraceForItem()
{
	
}
