// Copyright (c) 2025 Brian Caglioni
// Licensed under the MIT License. See LICENSE file in the project root.

#include "EmailAuthentication.h"

#include "EmailAuthenticationMethod.h"

std::unique_ptr<AuthenticationMethod> EmailAuthentication::authMethod() const {
  return std::make_unique<EmailAuthenticationMethod>();
}