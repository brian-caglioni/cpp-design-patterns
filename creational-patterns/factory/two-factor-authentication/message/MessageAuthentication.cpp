// Copyright (c) 2025 Brian Caglioni
// Licensed under the MIT License. See LICENSE file in the project root.
#include "MessageAuthentication.h"

#include "MessageAuthenticationMethod.h"

std::unique_ptr<AuthenticationMethod>
MessageAuthentication::authMethod() const {
  return std::make_unique<MessageAuthenticationMethod>();
}