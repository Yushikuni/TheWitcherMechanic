// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemy.h"
#include "Magic.h"
#include "Medailon.generated.h"

class ATheWitcher;

UCLASS()
class WITCHER3MECHANIC_API AMedailon : public AActor
{
	GENERATED_BODY()

public:
	//Making a detection radius
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Medailon")
	float DetectionRadius = 50.0f;

	// Sets default values for this actor's properties
	AMedailon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Custom overlap function
	UFUNCTION()
	void DetectNearbyThreats();

	UPROPERTY()
	ATheWitcher* OwningWitcher;

	void TriggerMedallionEffect();
	void TriggerMedallionEffectEnemy();
	void TriggerMedallionEffectMagic();
};
