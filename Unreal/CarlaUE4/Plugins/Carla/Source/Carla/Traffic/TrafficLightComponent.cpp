// Copyright (c) 2020 Computer Vision Center (CVC) at the Universitat Autonoma
// de Barcelona (UAB).
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.


#include "TrafficLightComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TrafficLightController.h"
#include "TrafficLightGroup.h"
#include "TrafficLightInterface.h"
#include "TrafficLightManager.h"

UTrafficLightComponent::UTrafficLightComponent()
  : Super()
{
}

// Called when the game starts
void UTrafficLightComponent::BeginPlay()
{
  Super::BeginPlay();
}

// Called every frame
void UTrafficLightComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
  Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
  // ...
}

void UTrafficLightComponent::SetLightState(ETrafficLightState NewState)
{
  LightState = NewState;
  LightChangeDispatcher.Broadcast();
  if (GetOwner()->Implements<UTrafficLightInterface>())
  {
    ITrafficLightInterface::Execute_LightChanged(GetOwner(), LightState);
  }
}

ETrafficLightState UTrafficLightComponent::GetLightState() const
{
  return LightState;
}

void UTrafficLightComponent::SetFrozenGroup(bool InFreeze)
{
  if (TrafficLightGroup)
  {
    TrafficLightGroup->SetFrozenGroup(InFreeze);
  }
}

ATrafficLightGroup* UTrafficLightComponent::GetGroup()
{
  return TrafficLightGroup;
}

UTrafficLightController* UTrafficLightComponent::GetController()
{
  return TrafficLightController;
}
