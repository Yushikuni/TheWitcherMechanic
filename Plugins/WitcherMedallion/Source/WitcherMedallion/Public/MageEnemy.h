// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "MageEnemy.generated.h"

/**
 *
 */
UCLASS()
class WITCHERMEDALLION_API AMageEnemy : public AEnemy
{
	GENERATED_BODY()
public:
	AMageEnemy();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	float CastRange = 800.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	float FireballDamage = 15.0f;

	UFUNCTION(BlueprintCallable, Category = "Combat")
	void CastFireball(AActor *TargetEnemy);
};
