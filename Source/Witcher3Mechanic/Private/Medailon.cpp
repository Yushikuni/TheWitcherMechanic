// Fill out your copyright notice in the Description page of Project Settings.


#include "Medailon.h"
#include "TheWitcher.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"

// Sets default values
AMedailon::AMedailon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	DetectionRadius = 500.f;
}


// Called when the game starts or when spawned
void AMedailon::BeginPlay()
{
	Super::BeginPlay();
    OwningWitcher = Cast<ATheWitcher>(GetOwner());
}

// Called every frame
void AMedailon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DetectNearbyThreats();
}

void AMedailon::DetectNearbyThreats()
{
    FVector MedallionLocation = GetActorLocation();
    TArray<FHitResult> HitResults;  // Zmìna na TArray<FHitResult>
    FCollisionShape Sphere = FCollisionShape::MakeSphere(DetectionRadius);

    // Raycasting nebo Overlap pro detekci objektù v blízkosti
    bool bIsOverlapping = GetWorld()->SweepMultiByChannel(
        HitResults,  // Zde používáme HitResults, což je správný typ
        MedallionLocation,
        MedallionLocation + FVector(0, 0, 1),  // Smìr je nulový, protože chceme detekci kolem
        FQuat::Identity,
        ECC_Pawn,  // Mùžeš používat rùzné kolizní kanály
        Sphere
    );

    DrawDebugSphere(GetWorld(), MedallionLocation, DetectionRadius, 5.0, FColor::Red, false, 1.0f); // Debugovací koule

    if (bIsOverlapping)
    {
        for (auto& Result : HitResults)
        {
            AActor* OverlappedActor = Result.GetActor();
            if (OverlappedActor)
            {
                if (OverlappedActor->ActorHasTag("Enemy"))
                {
                    // Spustit efekt medailonu
                    TriggerMedallionEffect();
                    break;
                } 
                if (OverlappedActor->ActorHasTag("Magic"))
                {
                    TriggerMedallionEffect();
                    break;
                }
            }
        }
    }
}
// Own category for loging
DEFINE_LOG_CATEGORY_STATIC(LogMedailon, Log, All);

void AMedailon::TriggerMedallionEffect()
{
    // Sem vlož logiku vibrace, zvuk, nebo vizuální efekt
    UE_LOG(LogTemp, Error, TEXT("Medallion Detects a Threat!"));

    // Mùžeš pøidat Particle system nebo haptickou zpìtnou vazbu
}