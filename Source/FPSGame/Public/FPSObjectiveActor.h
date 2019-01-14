// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPSObjectiveActor.generated.h"

class USphereComponent;

UCLASS()
class FPSGAME_API AFPSObjectiveActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFPSObjectiveActor();

protected: //Noone from outside the class can call these functions

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UStaticMeshComponent* MeshComp;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		USphereComponent* SphereComp;

	UPROPERTY(EditDefaultsOnly, Category = "Effects") //exposes to blueprint, very important to know
	UParticleSystem* PickupFX;
	//used for the item

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void PlayEffects();

public:

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	//overriding preimplementation 

};
