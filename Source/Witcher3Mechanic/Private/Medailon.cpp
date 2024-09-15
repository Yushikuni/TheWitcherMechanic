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
	PrimaryActorTick.bCanEverTick = true;
	DetectionRadius = 50000.f;
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
    if (!OwningWitcher)
    {
        UE_LOG(LogTemp, Warning, TEXT("OwningWitcher is null!"));
        return;  // Pokud je OwningWitcher null, vynech detekci
    }
    FVector WitcherLocation = OwningWitcher->GetActorLocation();
    FVector MedallionLocation = WitcherLocation;
    TArray<FOverlapResult> OverlapResult;
    FCollisionShape Sphere = FCollisionShape::MakeSphere(DetectionRadius);

    // Raycasting nebo Overlap pro detekci objektù v blízkosti
    bool bIsOverlapping = GetWorld()->OverlapMultiByChannel(
        OverlapResult,  // Zde používáme HitResults, což je správný typ
        MedallionLocation,
        FQuat::Identity,
        ECC_Pawn,  // Mùžeš používat rùzné kolizní kanály
        Sphere
    );

    DrawDebugSphere(GetWorld(), WitcherLocation, DetectionRadius, 50.0, FColor::Red, false, 1.0f); // Debugovací koule

    if (bIsOverlapping)
    {
        for (const FOverlapResult& Result : OverlapResult)
        {
            AActor* OverlappedActor = Result.GetActor();
            if (OverlappedActor && OverlappedActor->ActorHasTag("Enemy"))
            {
                TriggerMedallionEffectEnemy();
                break;
            }
        }
    }
}
// Own category for loging
//DEFINE_LOG_CATEGORY_STATIC(LogMedailon, Log, All);

void AMedailon::TriggerMedallionEffect()
{
    UE_LOG(LogTemp, Fatal, TEXT("Medallion Detects a Threat!"));
}

void AMedailon::TriggerMedallionEffectEnemy()
{
    // Sem vlož logiku vibrace, zvuk, nebo vizuální efekt
    UE_LOG(LogTemp, Error, TEXT("Medallion Detects a Enemy Threat!"));

    // Mùžeš pøidat Particle system nebo haptickou zpìtnou vazbu
}

void AMedailon::TriggerMedallionEffectMagic()
{
    UE_LOG(LogTemp, Warning, TEXT("Medallion Detects a MAGIC!"));
}