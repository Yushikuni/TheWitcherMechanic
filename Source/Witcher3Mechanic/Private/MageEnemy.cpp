// Fill out your copyright notice in the Description page of Project Settings.

#include "MageEnemy.h"

void AMageEnemy ::CastFireball(AActor *TargetEnemy)
{
    if (!TargetEnemy)
    {
        return;
    }

    float Distance = FVector::Dist(GetActorLocation(), TargetEnemy->GetActorLocation());
    if (Distance <= CastRange)
    {
        UE_LOG(LogTemp, Log, TEXT("MeleeEnemy attacks %s for %.1f damage!"), *TargetEnemy->GetName(), FireballDamage);
        // Sem později: skutečné aplikování damage (UGameplayStatics::ApplyDamage), animace útoku
    }
}
