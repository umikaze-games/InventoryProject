
#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Inv_WidgetUtils.generated.h"

UCLASS()
class INVENTORY_API UInv_WidgetUtils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	static int32 GetIndexFromPosition(const FIntPoint& Position, const int32 Columns);
	
	static FIntPoint GetPositionFromIndex(const int32 Index, const int32 Columns);
};