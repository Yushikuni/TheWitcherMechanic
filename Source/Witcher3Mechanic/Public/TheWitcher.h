// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Medailon.h"
#include "TheWitcher.generated.h"

UCLASS()
class WITCHER3MECHANIC_API ATheWitcher : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATheWitcher();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Add medailon to class
	UPROPERTY(EditAnywhere, Category = "Medailon")
	TSubclassOf<class AMedailon> TheWitcherMedailon;

	// Reference to the medailon component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* MedailonComponent;

	// Reference to the medailon mesh
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Medailon")
	UStaticMesh* MedailonMesh;

};
