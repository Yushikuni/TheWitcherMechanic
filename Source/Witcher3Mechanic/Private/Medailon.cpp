// Fill out your copyright notice in the Description page of Project Settings.

#include "Medailon.h"
#include "TheWitcher.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "Components/PrimitiveComponent.h"
#include "CollisionShape.h"
#include "Engine/EngineTypes.h"
#include "CollisionQueryParams.h"
#include "PhysicsEngine/PhysicsSettings.h"
#include "Engine/OverlapResult.h"

// Sets default values
AMedailon::AMedailon()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;
    DetectionRadius = 1500.f;
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
}

void AMedailon::DetectNearbyThreats()
{
    if (!OwningWitcher)
    {
        UE_LOG(LogTemp, Warning, TEXT("OwningWitcher is null!"));
        return; // Pokud je OwningWitcher null, vynech detekci
    }
    FVector WitcherLocation = OwningWitcher->GetActorLocation();
    FVector MedallionLocation = WitcherLocation;
    TArray<FOverlapResult> OverlapResult;
    FCollisionShape Sphere = FCollisionShape::MakeSphere(DetectionRadius);

    // Raycasting nebo Overlap pro detekci objekt� v bl�zkosti
    bool bIsOverlapping = GetWorld()->OverlapMultiByChannel(
        OverlapResult, // Zde pou��v�me HitResults, co� je spr�vn� typ
        MedallionLocation,
        FQuat::Identity,
        ECC_Pawn, // M��e� pou��vat r�zn� kolizn� kan�ly
        Sphere);

    DrawDebugSphere(GetWorld(), WitcherLocation, DetectionRadius, 50.0, FColor::Red, false, 1.0f); // Debugovac� koule
    if (!bIsOverlapping)
    {
        return;
    }

    if (bIsOverlapping)
    {
        FName TagToCheck = (CurrentMode == EDetectionMode::Enemy) ? FName("Enemy") : FName("Magic");
        float StrongestSignal = 0.0f;
        bool bFoundEnemy = false;
        for (const FOverlapResult &Result : OverlapResult)
        {
            AActor *OverlappedActor = Result.GetActor();
            if (OverlappedActor && OverlappedActor != OwningWitcher && OverlappedActor->ActorHasTag("Enemy"))
            {
                float Distance = FVector::Dist(WitcherLocation, OverlappedActor->GetActorLocation());
                float SignalStrenght = FMath::Clamp(1.0f - (Distance / DetectionRadius), 0.0f, 1.0f);

                UE_LOG(LogTemp, Warning, TEXT("Enemy: %s | Distance: %f | Strength: %f"), *OverlappedActor->GetName(), Distance, SignalStrenght);

                StrongestSignal = FMath::Max(StrongestSignal, SignalStrenght);
                bFoundEnemy = true;
            }
        }
        if (bFoundEnemy)
        {
            if (CurrentMode == EDetectionMode::Enemy)
            {
                TriggerMedallionEffectEnemy(StrongestSignal);
            }
            else
            {
                TriggerMedallionEffectMagic(StrongestSignal);
            }
        }
    }
}
// Own category for loging
// DEFINE_LOG_CATEGORY_STATIC(LogMedailon, Log, All);

void AMedailon::TriggerMedallionEffect()
{
    UE_LOG(LogTemp, Log, TEXT("Medallion Detects a Threat!"));
}

void AMedailon::TriggerMedallionEffectEnemy(float SignalStrenght)
{
    UE_LOG(LogTemp, Log, TEXT("Medallion Detects a Enemy Threat! Strength: %f"), SignalStrenght);
    // Sem později: intenzita vibrace/zvuku/vizuálu podle SignalStrength
}

void AMedailon::TriggerMedallionEffectMagic(float SignalStrenght)
{
    UE_LOG(LogTemp, Log, TEXT("Medallion Detects a MAGIC Threat! Strength: %f"), SignalStrenght);
}

void AMedailon::ToggleDetectionMode()
{
    CurrentMode = (CurrentMode == EDetectionMode::Enemy) ? EDetectionMode::Magic : EDetectionMode::Enemy;
    UE_LOG(LogTemp, Log, TEXT("Medallion mode: %s"),
           CurrentMode == EDetectionMode::Enemy ? TEXT("Enemy") : TEXT("Magic"));
}