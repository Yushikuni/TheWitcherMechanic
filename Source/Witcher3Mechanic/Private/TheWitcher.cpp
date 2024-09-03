// Fill out your copyright notice in the Description page of Project Settings.


#include "TheWitcher.h"

// Sets default values
ATheWitcher::ATheWitcher()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATheWitcher::BeginPlay()
{
	Super::BeginPlay();

	if (TheWitcherMedailon)
	{
        FActorSpawnParameters SpawnParams;
        SpawnParams.Owner = this;
        SpawnParams.Instigator = GetInstigator();

        // Vytvoøení instance Medailonu
        AMedailon* Medailon = GetWorld()->SpawnActor<AMedailon>(TheWitcherMedailon, GetActorLocation(), GetActorRotation(), SpawnParams);

        // Pøipojení medailonu k postavì (napøíklad ke koøenovému komponentu)
        if (Medailon)
        {
            Medailon->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
            SpawnedMedailon = Medailon;
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
    PlayerInputComponent->BindKey(EKeys::Y, IE_Pressed, this, &ATheWitcher::ActivateMedailon);
}

void ATheWitcher::ActivateMedailon()
{
    if (SpawnedMedailon)
    {
        // Aktivace funkce na Medailonu
        SpawnedMedailon->TriggerMedallionEffect();
    }
}