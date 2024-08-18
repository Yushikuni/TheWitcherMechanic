// Fill out your copyright notice in the Description page of Project Settings.


#include "Medailon.h"
#include "Enemy.h"
#include "Magic.h"

// Sets default values
AMedailon::AMedailon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Binging overlap events
	OnActorBeginOverlap.AddDynamic(this, &AMedailon::OnOverlapBegin);

}

//Overlap Function

void AMedailon::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	// Check if the overlapped actor is an enemy or magic source
	if (OtherActor->IsA(AEnemy::StaticClass()) || OtherActor->IsA(AMagic::StaticClass()))
	{
		// Trigger medallion reaction (vibration, animation, sound, etc.)
		ReactToMagicOrEnemies();
	}
}

//Reacting for Magic and enemies
void AMedailon::ReactToMagicOrEnemies()
{
	// TODO: implement UI for visualization of medailon
	UE_LOG(LogTemp, Warning, TEXT("Medailon is reacting something is wrong"));
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

}


