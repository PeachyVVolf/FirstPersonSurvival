// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "D:/Projects/FirstPersonGame/Source/FirstPersonGame/TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "PatrollingGuards.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTPERSONGAME_API APatrollingGuards : public ATP_ThirdPersonCharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditInstanceOnly, Category="Patrol Points")
	TArray<AActor*> PatrolPointsCPP;
	
};
