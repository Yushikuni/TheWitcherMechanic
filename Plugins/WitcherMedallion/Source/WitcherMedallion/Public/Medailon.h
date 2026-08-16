// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemy.h"
#include "Magic.h"
#include "Medailon.generated.h"

class ATheWitcher;

UENUM(BlueprintType)
enum class EDetectionMode : uint8
{
	Enemy,
	Magic
};

UCLASS()
class WITCHERMEDALLION_API AMedailon : public AActor
{
	GENERATED_BODY()

public:
	// Making a detection radius
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Medailon")
	float DetectionRadius = 1500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Medailon")
	EDetectionMode CurrentMode = EDetectionMode::Enemy; // default = Enemy

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Medailon")
	float CooldownDuration = 0.5f;

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

	UFUNCTION()
	void ToggleDetectionMode();

	UPROPERTY()
	ATheWitcher *OwningWitcher;
	void TriggerMedallionEffectEnemy(float SignalStrenght);
	void TriggerMedallionEffectMagic(float SignalStrenght);

private:
	float LastPulseTime = -999.0f;
};
