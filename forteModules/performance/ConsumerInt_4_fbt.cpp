/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: ConsumerInt_4
 *** Description: Service Interface Function Block Type
 *** Version:
 ***     1.0: 2024-12-21/cochicde -  -
 *************************************************************************/

#include "ConsumerInt_4_fbt.h"

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
USE_STRING_ID(performance__ConsumerInt_4);

DEFINE_FIRMWARE_FB(FORTE_performance__ConsumerInt_4,
                   STRID(performance__ConsumerInt_4))

const CStringDictionary::TStringId
    FORTE_performance__ConsumerInt_4::scmDataInputNames[] = {
        STRID(SD), STRID(SD2), STRID(SD3), STRID(SD4)};
const CStringDictionary::TStringId
    FORTE_performance__ConsumerInt_4::scmDataInputTypeIds[] = {
        STRID(ANY), STRID(ANY), STRID(ANY), STRID(ANY)};
const TDataIOID FORTE_performance__ConsumerInt_4::scmEIWith[] = {
    0, 2, 1, 3, scmWithListDelimiter};
const TForteInt16 FORTE_performance__ConsumerInt_4::scmEIWithIndexes[] = {0};
const CStringDictionary::TStringId
    FORTE_performance__ConsumerInt_4::scmEventInputNames[] = {STRID(REQ)};
const TForteInt16 FORTE_performance__ConsumerInt_4::scmEOWithIndexes[] = {-1};
const CStringDictionary::TStringId
    FORTE_performance__ConsumerInt_4::scmEventOutputNames[] = {STRID(CNF)};
const SFBInterfaceSpec FORTE_performance__ConsumerInt_4::scmFBInterfaceSpec = {
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
    4,
    scmDataInputNames,
    scmDataInputTypeIds,
    0,
    nullptr,
    nullptr,
    0,
    nullptr,
    0,
    nullptr};

FORTE_performance__ConsumerInt_4::FORTE_performance__ConsumerInt_4(
    const CStringDictionary::TStringId paInstanceNameId,
    forte::core::CFBContainer &paContainer)
    : CFunctionBlock(paContainer, scmFBInterfaceSpec, paInstanceNameId),
      var_SD(CIEC_ANY_VARIANT()), var_SD2(CIEC_ANY_VARIANT()),
      var_SD3(CIEC_ANY_VARIANT()), var_SD4(CIEC_ANY_VARIANT()),
      conn_CNF(*this, 0), conn_SD(nullptr), conn_SD2(nullptr),
      conn_SD3(nullptr), conn_SD4(nullptr){};

void FORTE_performance__ConsumerInt_4::setInitialValues() {
  var_SD = CIEC_ANY_VARIANT();
  var_SD2 = CIEC_ANY_VARIANT();
  var_SD3 = CIEC_ANY_VARIANT();
  var_SD4 = CIEC_ANY_VARIANT();
}

void FORTE_performance__ConsumerInt_4::executeEvent(
    const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch (paEIID) {
  case scmEventREQID:
    sendOutputEvent(scmEventCNFID, paECET);
    break;
  }
}

void FORTE_performance__ConsumerInt_4::readInputData(const TEventID paEIID) {
  switch (paEIID) {
  case scmEventREQID: {
    readData(0, var_SD, conn_SD);
    readData(2, var_SD3, conn_SD3);
    readData(1, var_SD2, conn_SD2);
    readData(3, var_SD4, conn_SD4);
    break;
  }
  default:
    break;
  }
}

void FORTE_performance__ConsumerInt_4::writeOutputData(TEventID) {
  // nothing to do
}

CIEC_ANY *FORTE_performance__ConsumerInt_4::getDI(const size_t paIndex) {
  switch (paIndex) {
  case 0:
    return &var_SD;
  case 1:
    return &var_SD2;
  case 2:
    return &var_SD3;
  case 3:
    return &var_SD4;
  }
  return nullptr;
}

CIEC_ANY *FORTE_performance__ConsumerInt_4::getDO(size_t) { return nullptr; }

CEventConnection *
FORTE_performance__ConsumerInt_4::getEOConUnchecked(const TPortId paIndex) {
  switch (paIndex) {
  case 0:
    return &conn_CNF;
  }
  return nullptr;
}

CDataConnection **
FORTE_performance__ConsumerInt_4::getDIConUnchecked(const TPortId paIndex) {
  switch (paIndex) {
  case 0:
    return &conn_SD;
  case 1:
    return &conn_SD2;
  case 2:
    return &conn_SD3;
  case 3:
    return &conn_SD4;
  }
  return nullptr;
}

CDataConnection *FORTE_performance__ConsumerInt_4::getDOConUnchecked(TPortId) {
  return nullptr;
}
