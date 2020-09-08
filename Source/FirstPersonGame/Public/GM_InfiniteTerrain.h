// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "..\FirstPersonGameGameMode.h"
#include "NavMesh/NavMeshBoundsVolume.h"
#include "GM_InfiniteTerrain.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTPERSONGAME_API AGM_InfiniteTerrain : public AFirstPersonGameGameMode
{
	GENERATED_BODY()

public:
	AGM_InfiniteTerrain();

	UFUNCTION(BlueprintCallable, Category = "BoundsPool")
	void PopulateBoundsVolumePool();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pool")
	class UActorPool* NavMeshBoundsVolumePool;

private:
	void AddToPool(ANavMeshBoundsVolume* VolumeToAdd);
};
