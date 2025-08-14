/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: MyStruct
 *** Description: A Template for a Data Type
 *** Version:
 ***     1.0: 2024-12-18/cochicde -  -
 *************************************************************************/

#pragma once

#include "core/datatypes/forte_struct.h"

#include "core/datatypes/forte_int.h"
#include "core/datatypes/forte_string.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"


class CIEC_performance__MyStruct final : public CIEC_STRUCT {
  DECLARE_FIRMWARE_DATATYPE(performance__MyStruct)

  public:
    CIEC_performance__MyStruct();

    CIEC_performance__MyStruct(const CIEC_INT &pa_int, const CIEC_STRING &pa_string);

    CIEC_INT var__int;
    CIEC_STRING var__string;

    size_t getStructSize() const override {
      return 2;
    }

    const CStringDictionary::TStringId* elementNames() const override {
      return scmElementNames;
    }

    CStringDictionary::TStringId getStructTypeNameID() const override;

    void setValue(const CIEC_ANY &paValue) override;

    CIEC_ANY *getMember(size_t) override;
    const CIEC_ANY *getMember(size_t) const override;

  private:
    static const CStringDictionary::TStringId scmElementNames[];

};

