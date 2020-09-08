// Fill out your copyright notice in the Description page of Project Settings.


#include "Tile.h"
#include "DrawDebugHelpers.h"
#include "EngineUtils.h"
#include "../Public/ActorPool.h"
#include "AI/NavigationSystemBase.h"
#include "NavigationSystem.h"

// Sets default values
ATile::ATile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MinExtent = FVector(-3275, -2325, 0);
	MaxExtent = FVector(3275, 2325, 0);
}

void ATile::SetPool(UActorPool* InPool) 
{
	Pool = InPool;
	PositionNavMeshBoundsVolume();
}

void ATile::PositionNavMeshBoundsVolume()
{
	NavMeshBoundsVolume = Pool->CheckOut();
	if (NavMeshBoundsVolume == nullptr) 
	{
		return;
	}
	NavMeshBoundsVolume->SetActorLocation(GetActorLocation());

	//GetWorld()->GetNavigationSystem()->Build();
}

bool ATile::FindEmptyLocation(FVector& OutLocation, float Radius)
{

	FBox Bounds(MinExtent, MaxExtent);

	const int MAX_ATTEMPTS = 100;
	for (size_t i = 0; i < MAX_ATTEMPTS; i++)
	{
		FVector CandidatePoint = FMath::RandPointInBox(Bounds);
		if (CanSpawnAtLocation(CandidatePoint, Radius))
		{
			OutLocation = CandidatePoint;
			return true;
		}
	}
	return false;
}

void ATile::PlaceActors(TSubclassOf<AActor> ToSpawn, FVector SpawnPoint, float Rotation, float Scale)
{
	AActor* Spawned = GetWorld()->SpawnActor<AActor>(ToSpawn);
	Spawned->SetActorRelativeLocation(SpawnPoint);
	Spawned->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false));
	Spawned->SetActorRotation(FRotator(0, Rotation, 0));
	Spawned->SetActorScale3D(FVector(Scale));
}

void ATile::PlaceActors(TSubclassOf<AActor> ToSpawn, int MinSpawn, int MaxSpawn, float Radius, float MinScale, float MaxScale)
{
	int numbertospawn = FMath::RandRange(MinSpawn, MaxSpawn);
	for (size_t i = 0; i < numbertospawn; i++) 
	{
		FVector SpawnPoint;
		float RandomScale = FMath::RandRange(MinScale, MaxScale);
		bool found = FindEmptyLocation(SpawnPoint, Radius * RandomScale);
		if (found) 
		{
			float RandomRotation = FMath::RandRange(-180.f, 180.f);
			PlaceActors(ToSpawn, SpawnPoint, RandomRotation, RandomScale);
		}
	}
}

// Called when the game starts or when spawned
void ATile::BeginPlay()
{
	Super::BeginPlay(); 

}

void ATile::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	Pool->Return(NavMeshBoundsVolume);
}

// Called every frame
void ATile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool ATile::CanSpawnAtLocation(FVector Location, float Radius)
{
	FHitResult HitResult;
	FVector GlobalLocation = ActorToWorld().TransformPosition(Location);
	bool HasHit = GetWorld()->SweepSingleByChannel(HitResult,
		GlobalLocation,
		GlobalLocation,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel2,
		FCollisionShape::MakeSphere(Radius));

	return !HasHit;
}
