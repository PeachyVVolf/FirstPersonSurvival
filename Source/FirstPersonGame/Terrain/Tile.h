// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tile.generated.h"


USTRUCT()
struct FSpawnPosition
{
	GENERATED_USTRUCT_BODY()

	FVector Location;
	float Rotation; 
	float Scale;
};

class UActorPool;

UCLASS()
class FIRSTPERSONGAME_API ATile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATile();

	UFUNCTION(BlueprintCallable, Category = "Terrain")
	void PlaceActors(TSubclassOf<AActor> ToSpawn, int MinSpawn = 1, int MaxSpawn = 1, float Radius = 500, float MinScale = 1, float MaxScale = 1);
	
	UFUNCTION(BlueprintCallable, Category = "Terrain")
	void PlaceAIPawns(TSubclassOf<APawn> ToSpawn, int MinSpawn = 1, int MaxSpawn = 1, float Radius = 500);

	void RandomSpawnPositions(int MinSpawn, int MaxSpawn, float Radius, TArray<FSpawnPosition>& SpawnPostions, float MinScale = 1, float MaxScale = 1);
	
	UFUNCTION(BlueprintCallable, Category = "Pool")
	void SetPool(UActorPool* InPool);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
	FVector MinExtent;

	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
	FVector MaxExtent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	bool FindEmptyLocation(FVector& OutLocation, float Radius);
	void PlaceActors(TSubclassOf<AActor> ToSpawn, FSpawnPosition SpawnPosition);
	bool CanSpawnAtLocation(FVector Location, float Radius);

	UActorPool* Pool;
	AActor* NavMeshBoundsVolume;
	void PositionNavMeshBoundsVolume();
};
