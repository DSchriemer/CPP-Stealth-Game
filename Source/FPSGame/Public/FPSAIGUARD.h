// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FPSAIGUARD.generated.h"

class UPawnSensingComponent;



UCLASS()
class FPSGAME_API AFPSAIGUARD : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPSAIGUARD();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UPawnSensingComponent* PawnSensingComp;

	UFUNCTION()
		void OnPawnSeen(APawn* SeenPawn);

	UFUNCTION()
		void OnNoiseHeard(APawn* NoiseInstigator, const FVector& Location, float Volume);
	
	FRotator OriginalRotation;
	
	UFUNCTION()
		void ResetOrientation();
	
	FTimerHandle TimerHandle_ResetOrientation;
	

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


protected:

};
