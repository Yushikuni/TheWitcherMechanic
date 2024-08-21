// Fill out your copyright notice in the Description page of Project Settings.


#include "TheWitcher.h"
#include "Medailon.h"

// Sets default values
ATheWitcher::ATheWitcher()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    //Add to the witcher component
    // Vytvo� novou statickou komponentu pro medailon a p�ipoj ji ke ko�enov�mu komponentu postavy
    MedailonComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MedailonComponent"));
    MedailonComponent->SetupAttachment(RootComponent);

    MedailonComponent->SetStaticMesh(MedailonMesh);  // Nastaven� mesh
    MedailonComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    MedailonComponent->SetGenerateOverlapEvents(true);  // Povolen� detekce overlapu


}

// Called when the game starts or when spawned
void ATheWitcher::BeginPlay()
{
	Super::BeginPlay();

	if (TheWitcherMedailon != nullptr)
	{
        FActorSpawnParameters SpawnParams;
        SpawnParams.Owner = this;
        SpawnParams.Instigator = GetInstigator();

        // Vytvo�en� instance Medailonu
        AMedailon* Medailon = GetWorld()->SpawnActor<AMedailon>(TheWitcherMedailon, GetActorLocation(), GetActorRotation(), SpawnParams);

        // P�ipojen� medailonu k postav� (nap��klad ke ko�enov�mu komponentu)
        if (Medailon)
        {
            Medailon->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
        }
	}
	
}

// Called every frame
void ATheWitcher::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATheWitcher::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

