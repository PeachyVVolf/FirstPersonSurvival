// Fill out your copyright notice in the Description page of Project Settings.


#include "GM_InfiniteTerrain.h"
#include "NavMesh/NavMeshBoundsVolume.h"
#include "EngineUtils.h"

void AGM_InfiniteTerrain::PopulateBoundsVolumePool()
{
	auto VolumeIterator = TActorIterator<ANavMeshBoundsVolume>(GetWorld());
	while (VolumeIterator)
	{
		AddToPool(*VolumeIterator);
		++VolumeIterator;
	}
}

void AGM_InfiniteTerrain::AddToPool(ANavMeshBoundsVolume* VolumeToAdd)
{
	UE_LOG(LogTemp, Error, TEXT("Volume To Add: %s"), *VolumeToAdd->GetName());
}
