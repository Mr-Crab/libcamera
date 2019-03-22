/* SPDX-License-Identifier: LGPL-2.1-or-later */
/*
 * Copyright (C) 2018, Google Inc.
 *
 * utils.h - Miscellaneous utility functions
 */
#ifndef __LIBCAMERA_UTILS_H__
#define __LIBCAMERA_UTILS_H__

#include <memory>

#define ARRAY_SIZE(a)	(sizeof(a) / sizeof(a[0]))

namespace libcamera {

namespace utils {

const char *basename(const char *path);

/* C++11 doesn't provide std::make_unique */
template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args)
{
	return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

char *secure_getenv(const char *name);

} /* namespace utils */

} /* namespace libcamera */

#endif /* __LIBCAMERA_UTILS_H__ */
