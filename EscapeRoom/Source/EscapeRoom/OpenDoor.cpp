// No Copyright

#include "OpenDoor.h"
#include "GameFramework/Actor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	AActor* Owner = GetOwner();

	FRotator NewRotation = FRotator(0.0f, -60.0f, 0.0f);

	Owner->SetActorRotation(NewRotation);
	
	/* Rotate by setting the Owners rotation directly
	FString ObjName = Owner->GetName();
	FQuat qObjRotation = Owner->GetTransform().GetRotation();
	FString sObjRotation = qObjRotation.ToString();
	UE_LOG(LogTemp, Warning, TEXT("%s 's Rotation: %s"), *ObjName, *sObjRotation);

	qObjRotation.Z = -90.0f;
	
	Owner->SetActorRotation(qObjRotation);   //->GetTransform().SetRotation(qObjRotation);
	sObjRotation = qObjRotation.ToString();
	UE_LOG(LogTemp, Warning, TEXT("%s 's Updated Rotation: %s"), *ObjName, *sObjRotation);
	*/
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

