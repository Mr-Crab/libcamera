/* SPDX-License-Identifier: LGPL-2.1-or-later */
/*
 * Copyright (C) 2019, Google Inc.
 *
 * Image Processing Algorithm proxy
 */

#pragma once

#include <optional>
#include <string>
#include <vector>

#include <libcamera/ipa/ipa_interface.h>

#include "libcamera/internal/global_configuration.h"

namespace libcamera {

class IPAModule;

class IPAProxy : public IPAInterface
{
public:
	enum ProxyState {
		ProxyStopped,
		ProxyStopping,
		ProxyRunning,
	};

	IPAProxy(IPAModule *ipam, const GlobalConfiguration &configuration);
	~IPAProxy();

	bool isValid() const { return valid_; }

	std::string configurationFile(const std::string &name,
				      const std::string &fallbackName = std::string()) const;

protected:
	std::string resolvePath(const std::string &file) const;

	bool valid_;
	ProxyState state_;

private:
	IPAModule *ipam_;
	std::vector<std::string> configPaths_;
	std::vector<std::string> execPaths_;
};

} /* namespace libcamera */
