// Fill out your copyright notice in the Description page of Project Settings.


#include "Magic.h"

// Sets default values
AMagic::AMagic()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMagic::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMagic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

