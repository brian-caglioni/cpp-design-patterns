// Copyright (c) 2025 Brian Caglioni
// Licensed under the MIT License. See LICENSE file in the project root.
#include "MessageTwoFactor.h"

#include "MessageAuthenticationMethod.h"
#include "MessageNotificationMethod.h"

std::unique_ptr<AuthenticationMethod>
MessageTwoFactor::authenticationMethod() const {
  return std::make_unique<MessageAuthenticationMethod>();
}

std::unique_ptr<NotificationMethod>
MessageTwoFactor::notificationMethod() const {
  return std::make_unique<MessageNotificationMethod>();
};
