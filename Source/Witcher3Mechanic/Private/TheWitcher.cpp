// Fill out your copyright notice in the Description page of Project Settings.


#include "TheWitcher.h"
#include "Medailon.h"

// Sets default values
ATheWitcher::ATheWitcher()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    //Add to the witcher component
    // Vytvoø novou statickou komponentu pro medailon a pøipoj ji ke koøenovému komponentu postavy
    MedailonComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MedailonComponent"));
    MedailonComponent->SetupAttachment(RootComponent);

    MedailonComponent->SetStaticMesh(MedailonMesh);  // Nastavení mesh
    MedailonComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    MedailonComponent->SetGenerateOverlapEvents(true);  // Povolení detekce overlapu


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

        // Vytvoøení instance Medailonu
        AMedailon* Medailon = GetWorld()->SpawnActor<AMedailon>(TheWitcherMedailon, GetActorLocation(), GetActorRotation(), SpawnParams);

        // Pøipojení medailonu k postavì (napøíklad ke koøenovému komponentu)
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

