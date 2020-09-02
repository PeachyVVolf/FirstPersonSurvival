// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PatrolRoutes.generated.h"

/**
* A Route Card to help AI Choose their next waypoint
*/
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FIRSTPERSONGAME_API UPatrolRoutes : public UActorComponent
{
	GENERATED_BODY()

public:
	TArray<AActor*> GetPatrolPoints()const;

private:
	UPROPERTY(EditInstanceOnly, Category = "Patrol Points")
	TArray<AActor*> PatrolPoints;
};
