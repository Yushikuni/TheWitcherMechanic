// Fill out your copyright notice in the Description page of Project Settings.

#include "MeleeEnemy.h"

void AMeleeEnemy::PerformMeleeAttack(AActor *TargetActor)
{
    if (!TargetActor)
    {
        return;
    }

    float Distance = FVector::Dist(GetActorLocation(), TargetActor->GetActorLocation());
    if (Distance <= AttackRange)
    {
        UE_LOG(LogTemp, Log, TEXT("MeleeEnemy attacks %s for %.1f damage!"), *TargetActor->GetName(), AttackDamage);
        // Sem později: skutečné aplikování damage (UGameplayStatics::ApplyDamage), animace útoku
    }
}
