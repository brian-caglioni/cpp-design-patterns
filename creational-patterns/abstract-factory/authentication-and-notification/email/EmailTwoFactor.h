// Copyright (c) 2025 Brian Caglioni
// Licensed under the MIT License. See LICENSE file in the project root.
#pragma once

#include "../TwoFactorAuthentication.h"

class EmailTwoFactor : public TwoFactorAuthentication {
  std::unique_ptr<AuthenticationMethod> authenticationMethod() const override;
  std::unique_ptr<NotificationMethod> notificationMethod() const override;
};