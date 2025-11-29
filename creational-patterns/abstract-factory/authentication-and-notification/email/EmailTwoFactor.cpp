// Copyright (c) 2025 Brian Caglioni
// Licensed under the MIT License. See LICENSE file in the project root.
#include "EmailTwoFactor.h"

#include "EmailAuthenticationMethod.h"
#include "EmailNotificationMethod.h"

std::unique_ptr<AuthenticationMethod>
EmailTwoFactor::authenticationMethod() const {
  return std::make_unique<EmailAuthenticationMethod>();
}

std::unique_ptr<NotificationMethod> EmailTwoFactor::notificationMethod() const {
  return std::make_unique<EmailNotificationMethod>();
};
