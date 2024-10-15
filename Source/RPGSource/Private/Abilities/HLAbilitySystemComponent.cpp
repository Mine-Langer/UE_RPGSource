// copyright  By Langer -- libing044@gmail.com


#include "Abilities/HLAbilitySystemComponent.h"

#include "Abilities/HLGameplayAbility.h"


UHLAbilitySystemComponent::UHLAbilitySystemComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UHLAbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();

}

void UHLAbilitySystemComponent::AbilityLocalInputPressed(int32 InputID)
{
	Super::AbilityLocalInputPressed(InputID);

	if (IsGenericConfirmInputBound(InputID))
	{
		LocalInputConfirm();
		return;
	}

	if (IsGenericCancelInputBound(InputID))
	{
		LocalInputCancel();
		return;
	}

	ABILITYLIST_SCOPE_LOCK();
	for (FGameplayAbilitySpec& Spec : ActivatableAbilities.Items)
	{
		if (Spec.InputID == InputID && Spec.Ability)
		{
			if (Spec.IsActive())
			{
				AbilitySpecInputPressed(Spec);
			}
			else
			{
				UHLGameplayAbility* GA = Cast<UHLGameplayAbility>(Spec.Ability);
				if (GA && GA->bActiveOnInput)
				{
					TryActivateAbility(Spec.Handle);
				}
			}
		}
	}
}

