// Copyright (c) 2025 Brian Caglioni
// Licensed under the MIT License. See LICENSE file in the project root.
#pragma once

#include "../NotificationMethod.h"

class EmailNotificationMethod : public NotificationMethod {
  void sendNotification() const override;
};