// Fill out your copyright notice in the Description page of Project Settings.


#include "GM_InfiniteTerrain.h"
#include "NavMesh/NavMeshBoundsVolume.h"
#include "EngineUtils.h"
#include "ActorPool.h"

AGM_InfiniteTerrain::AGM_InfiniteTerrain() 
{
	NavMeshBoundsVolumePool = CreateDefaultSubobject<UActorPool>(FName(" Nav Mesh Bounds Volume"));
}

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
	NavMeshBoundsVolumePool->Add(VolumeToAdd);
}
