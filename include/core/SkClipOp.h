/*
 * Copyright 2016 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkClipOp_DEFINED
#define SkClipOp_DEFINED

#include "SkTypes.h"

// SkClipOp enum values always match the corresponding values in SkRegion::Op

enum class SkClipOp {
    kDifference    = 0,
    kIntersect     = 1,

    // Goal: remove these, since they can grow the current clip

#ifdef SK_SUPPORT_EXOTIC_CLIPOPS
    kUnion         = 2,
    kXOR           = 3,
    kReverseDifference = 4,
    kReplace       = 5,
#endif

    ////////////////////////////////////////////////////////////////////////////////
    // End of enum










    ////////////////////////////////////////////////////////////////////////////////
    // Nothing to see here









    ////////////////////////////////////////////////////////////////////////////////
    // Turn back!





    // Private Internal enums -- do not use -- destined to be removed at any moment!

    kUnion_private_internal_do_not_use             = 2,
    kXOR_private_internal_do_not_use               = 3,
    kReverseDifference_private_internal_do_not_use = 4,
    kReplace_private_internal_do_not_use           = 5,

    kMax_EnumValue = kReplace_private_internal_do_not_use
};

#endif
