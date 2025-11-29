// Copyright (c) 2025 Brian Caglioni
// Licensed under the MIT License. See LICENSE file in the project root.
#pragma once

class NotificationMethod {
public:
  virtual ~NotificationMethod() = default;
  virtual void sendNotification() const = 0;
};
