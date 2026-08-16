// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "MeleeEnemy.generated.h"

/**
 * Melee enemy as a child enemy.h
 */
UCLASS()
class WITCHER3MECHANIC_API AMeleeEnemy : public AEnemy
{
	GENERATED_BODY()

public:
	AMeleeEnemy();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	float AttackRange = 150.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	float AttackDamage = 10.0f;

	UFUNCTION(BlueprintCallable, Category = "Combat")
	void PerformMeleeAttack(AActor *TargetActor);
};
