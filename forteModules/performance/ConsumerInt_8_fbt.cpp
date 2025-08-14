/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: ConsumerInt_8
 *** Description: Service Interface Function Block Type
 *** Version:
 ***     1.0: 2024-12-21/cochicde -  -
 *************************************************************************/

#include "ConsumerInt_8_fbt.h"

#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"
#include "core/iec61131_functions.h"

USE_STRING_ID(ANY);
USE_STRING_ID(CNF);
USE_STRING_ID(Event);
USE_STRING_ID(REQ);
USE_STRING_ID(SD);
USE_STRING_ID(SD2);
USE_STRING_ID(SD3);
USE_STRING_ID(SD4);
USE_STRING_ID(SD5);
USE_STRING_ID(SD6);
USE_STRING_ID(SD7);
USE_STRING_ID(SD8);
USE_STRING_ID(performance__ConsumerInt_8);

DEFINE_FIRMWARE_FB(FORTE_performance__ConsumerInt_8,
                   STRID(performance__ConsumerInt_8))

const CStringDictionary::TStringId
    FORTE_performance__ConsumerInt_8::scmDataInputNames[] = {
        STRID(SD),  STRID(SD2), STRID(SD3), STRID(SD4),
        STRID(SD5), STRID(SD6), STRID(SD7), STRID(SD8)};
const CStringDictionary::TStringId
    FORTE_performance__ConsumerInt_8::scmDataInputTypeIds[] = {
        STRID(ANY), STRID(ANY), STRID(ANY), STRID(ANY),
        STRID(ANY), STRID(ANY), STRID(ANY), STRID(ANY)};
const TDataIOID FORTE_performance__ConsumerInt_8::scmEIWith[] = {
    0, 1, 2, 3, 4, 5, 7, 6, scmWithListDelimiter};
const TForteInt16 FORTE_performance__ConsumerInt_8::scmEIWithIndexes[] = {0};
const CStringDictionary::TStringId
    FORTE_performance__ConsumerInt_8::scmEventInputNames[] = {STRID(REQ)};
const TForteInt16 FORTE_performance__ConsumerInt_8::scmEOWithIndexes[] = {-1};
const CStringDictionary::TStringId
    FORTE_performance__ConsumerInt_8::scmEventOutputNames[] = {STRID(CNF)};
const SFBInterfaceSpec FORTE_performance__ConsumerInt_8::scmFBInterfaceSpec = {
    1,
    scmEventInputNames,
    nullptr,
    scmEIWith,
    scmEIWithIndexes,
    1,
    scmEventOutputNames,
    nullptr,
    nullptr,
    scmEOWithIndexes,
    8,
    scmDataInputNames,
    scmDataInputTypeIds,
    0,
    nullptr,
    nullptr,
    0,
    nullptr,
    0,
    nullptr};

FORTE_performance__ConsumerInt_8::FORTE_performance__ConsumerInt_8(
    const CStringDictionary::TStringId paInstanceNameId,
    forte::core::CFBContainer &paContainer)
    : CFunctionBlock(paContainer, scmFBInterfaceSpec, paInstanceNameId),
      var_SD(CIEC_ANY_VARIANT()), var_SD2(CIEC_ANY_VARIANT()),
      var_SD3(CIEC_ANY_VARIANT()), var_SD4(CIEC_ANY_VARIANT()),
      var_SD5(CIEC_ANY_VARIANT()), var_SD6(CIEC_ANY_VARIANT()),
      var_SD7(CIEC_ANY_VARIANT()), var_SD8(CIEC_ANY_VARIANT()),
      conn_CNF(*this, 0), conn_SD(nullptr), conn_SD2(nullptr),
      conn_SD3(nullptr), conn_SD4(nullptr), conn_SD5(nullptr),
      conn_SD6(nullptr), conn_SD7(nullptr), conn_SD8(nullptr){};

void FORTE_performance__ConsumerInt_8::setInitialValues() {
  var_SD = CIEC_ANY_VARIANT();
  var_SD2 = CIEC_ANY_VARIANT();
  var_SD3 = CIEC_ANY_VARIANT();
  var_SD4 = CIEC_ANY_VARIANT();
  var_SD5 = CIEC_ANY_VARIANT();
  var_SD6 = CIEC_ANY_VARIANT();
  var_SD7 = CIEC_ANY_VARIANT();
  var_SD8 = CIEC_ANY_VARIANT();
}

void FORTE_performance__ConsumerInt_8::executeEvent(
    const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch (paEIID) {
  case scmEventREQID:
    sendOutputEvent(scmEventCNFID, paECET);
    break;
  }
}

void FORTE_performance__ConsumerInt_8::readInputData(const TEventID paEIID) {
  switch (paEIID) {
  case scmEventREQID: {
    readData(0, var_SD, conn_SD);
    readData(1, var_SD2, conn_SD2);
    readData(2, var_SD3, conn_SD3);
    readData(3, var_SD4, conn_SD4);
    readData(4, var_SD5, conn_SD5);
    readData(5, var_SD6, conn_SD6);
    readData(7, var_SD8, conn_SD8);
    readData(6, var_SD7, conn_SD7);
    break;
  }
  default:
    break;
  }
}

void FORTE_performance__ConsumerInt_8::writeOutputData(TEventID) {
  // nothing to do
}

CIEC_ANY *FORTE_performance__ConsumerInt_8::getDI(const size_t paIndex) {
  switch (paIndex) {
  case 0:
    return &var_SD;
  case 1:
    return &var_SD2;
  case 2:
    return &var_SD3;
  case 3:
    return &var_SD4;
  case 4:
    return &var_SD5;
  case 5:
    return &var_SD6;
  case 6:
    return &var_SD7;
  case 7:
    return &var_SD8;
  }
  return nullptr;
}

CIEC_ANY *FORTE_performance__ConsumerInt_8::getDO(size_t) { return nullptr; }

CEventConnection *
FORTE_performance__ConsumerInt_8::getEOConUnchecked(const TPortId paIndex) {
  switch (paIndex) {
  case 0:
    return &conn_CNF;
  }
  return nullptr;
}

CDataConnection **
FORTE_performance__ConsumerInt_8::getDIConUnchecked(const TPortId paIndex) {
  switch (paIndex) {
  case 0:
    return &conn_SD;
  case 1:
    return &conn_SD2;
  case 2:
    return &conn_SD3;
  case 3:
    return &conn_SD4;
  case 4:
    return &conn_SD5;
  case 5:
    return &conn_SD6;
  case 6:
    return &conn_SD7;
  case 7:
    return &conn_SD8;
  }
  return nullptr;
}

CDataConnection *FORTE_performance__ConsumerInt_8::getDOConUnchecked(TPortId) {
  return nullptr;
}
