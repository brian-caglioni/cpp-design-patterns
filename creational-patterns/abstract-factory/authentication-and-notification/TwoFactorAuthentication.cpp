// Copyright (c) 2025 Brian Caglioni
// Licensed under the MIT License. See LICENSE file in the project root.
#include "TwoFactorAuthentication.h"

#include "AuthenticationMethod.h"
#include "NotificationMethod.h"

TwoFactorAuthentication::~TwoFactorAuthentication() = default;

void TwoFactorAuthentication::verify() const {
  this->authenticationMethod()->send();
}

void TwoFactorAuthentication::notify() const {
  this->notificationMethod()->sendNotification();
}