// Copyright (c) 2025 Brian Caglioni
// Licensed under the MIT License. See LICENSE file in the project root.
#pragma once

#include "../TwoFactorAuthentication.h"

class MessageAuthentication : public TwoFactorAuthentication {
  std::unique_ptr<AuthenticationMethod> authMethod() const override;
};