/*
 * Copyright 2016 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkSVGValue_DEFINED
#define SkSVGValue_DEFINED

#include "SkColor.h"
#include "SkMatrix.h"
#include "SkPath.h"
#include "SkSVGTypes.h"
#include "SkTypes.h"

class SkSVGValue : public SkNoncopyable {
public:
    enum class Type {
        kColor,
        kLength,
        kLineCap,
        kLineJoin,
        kNumber,
        kPaint,
        kPath,
        kTransform,
        kViewBox,
    };

    Type type() const { return fType; }

    template <typename T>
    const T* as() const {
        return fType == T::TYPE ? static_cast<const T*>(this) : nullptr;
    }

protected:
    SkSVGValue(Type t) : fType(t) { }

private:
    Type fType;

    typedef SkNoncopyable INHERITED;
};

template <typename T, SkSVGValue::Type ValueType>
class SkSVGWrapperValue final : public SkSVGValue {
public:
    static constexpr Type TYPE = ValueType;

    explicit SkSVGWrapperValue(const T& v)
        : INHERITED(ValueType)
        , fWrappedValue(v) { }

    operator const T&() const { return fWrappedValue; }
    const T* operator->() const { return &fWrappedValue; }

private:
    // Stack-only
    void* operator new(size_t) = delete;
    void* operator new(size_t, void*) = delete;

    const T& fWrappedValue;

    typedef SkSVGValue INHERITED;
};

using SkSVGColorValue     = SkSVGWrapperValue<SkSVGColorType    , SkSVGValue::Type::kColor    >;
using SkSVGLengthValue    = SkSVGWrapperValue<SkSVGLength       , SkSVGValue::Type::kLength   >;
using SkSVGPathValue      = SkSVGWrapperValue<SkPath            , SkSVGValue::Type::kPath     >;
using SkSVGTransformValue = SkSVGWrapperValue<SkSVGTransformType, SkSVGValue::Type::kTransform>;
using SkSVGViewBoxValue   = SkSVGWrapperValue<SkSVGViewBoxType  , SkSVGValue::Type::kViewBox  >;
using SkSVGPaintValue     = SkSVGWrapperValue<SkSVGPaint        , SkSVGValue::Type::kPaint    >;
using SkSVGLineCapValue   = SkSVGWrapperValue<SkSVGLineCap      , SkSVGValue::Type::kLineCap  >;
using SkSVGLineJoinValue  = SkSVGWrapperValue<SkSVGLineJoin     , SkSVGValue::Type::kLineJoin >;
using SkSVGNumberValue    = SkSVGWrapperValue<SkSVGNumberType   , SkSVGValue::Type::kNumber   >;

#endif // SkSVGValue_DEFINED