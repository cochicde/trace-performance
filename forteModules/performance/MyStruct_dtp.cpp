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

#include "MyStruct_dtp.h"

#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

USE_STRING_ID(_int);
USE_STRING_ID(_string);
USE_STRING_ID(performance__MyStruct);

DEFINE_FIRMWARE_DATATYPE(performance__MyStruct, STRID(performance__MyStruct));

const CStringDictionary::TStringId CIEC_performance__MyStruct::scmElementNames[] = {STRID(_int), STRID(_string)};

CIEC_performance__MyStruct::CIEC_performance__MyStruct() :
    CIEC_STRUCT(),
    var__int(0_INT),
    var__string(""_STRING) {
}

CIEC_performance__MyStruct::CIEC_performance__MyStruct(const CIEC_INT &pa_int, const CIEC_STRING &pa_string) :
    CIEC_STRUCT(),
    var__int(pa_int),
    var__string(pa_string) {
}

CStringDictionary::TStringId CIEC_performance__MyStruct::getStructTypeNameID() const {
  return STRID(performance__MyStruct);
}

void CIEC_performance__MyStruct::setValue(const CIEC_ANY &paValue) {
  if (paValue.getDataTypeID() == e_STRUCT) {
    auto &otherStruct = static_cast<const CIEC_STRUCT &>(paValue);
    if (STRID(performance__MyStruct) == otherStruct.getStructTypeNameID()) {
      operator=(static_cast<const CIEC_performance__MyStruct &>(paValue));
    }
  }
}

CIEC_ANY *CIEC_performance__MyStruct::getMember(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var__int;
    case 1: return &var__string;
  }
  return nullptr;
}

const CIEC_ANY *CIEC_performance__MyStruct::getMember(const size_t paIndex) const {
  switch(paIndex) {
    case 0: return &var__int;
    case 1: return &var__string;
  }
  return nullptr;
}
