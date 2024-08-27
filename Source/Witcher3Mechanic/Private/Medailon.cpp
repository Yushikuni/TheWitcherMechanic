// Fill out your copyright notice in the Description page of Project Settings.


#include "Medailon.h"
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
    TArray<FHitResult> HitResults;  // Zm�na na TArray<FHitResult>
    FCollisionShape Sphere = FCollisionShape::MakeSphere(DetectionRadius);

    // Raycasting nebo Overlap pro detekci objekt� v bl�zkosti
    bool bIsOverlapping = GetWorld()->SweepMultiByChannel(
        HitResults,  // Zde pou��v�me HitResults, co� je spr�vn� typ
        MedallionLocation,
        MedallionLocation + FVector(0, 0, 1),  // Sm�r je nulov�, proto�e chceme detekci kolem
        FQuat::Identity,
        ECC_Pawn,  // M��e� pou��vat r�zn� kolizn� kan�ly
        Sphere
    );

    if (bIsOverlapping)
    {
        for (auto& Result : HitResults)
        {
            AActor* OverlappedActor = Result.GetActor();
            if (OverlappedActor && OverlappedActor->ActorHasTag("Enemy"))
            {
                // Spustit efekt medailonu
                TriggerMedallionEffect();
                break;
            }
        }
    }
}

void AMedailon::TriggerMedallionEffect()
{
    // Sem vlo� logiku vibrace, zvuk, nebo vizu�ln� efekt
    UE_LOG(LogTemp, Error, TEXT("Medallion Detects a Threat!"));

    // M��e� p�idat Particle system nebo haptickou zp�tnou vazbu
}