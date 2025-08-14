/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: ConsumerInt
 *** Description: Service Interface Function Block Type
 *** Version:
 ***     1.0: 2024-12-21/cochicde -  -
 *************************************************************************/

#include "ConsumerInt_fbt.h"

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
USE_STRING_ID(performance__ConsumerInt);

DEFINE_FIRMWARE_FB(FORTE_performance__ConsumerInt,
                   STRID(performance__ConsumerInt))

const CStringDictionary::TStringId
    FORTE_performance__ConsumerInt::scmDataInputNames[] = {STRID(SD)};
const CStringDictionary::TStringId
    FORTE_performance__ConsumerInt::scmDataInputTypeIds[] = {STRID(ANY)};
const TDataIOID FORTE_performance__ConsumerInt::scmEIWith[] = {
    0, scmWithListDelimiter};
const TForteInt16 FORTE_performance__ConsumerInt::scmEIWithIndexes[] = {0};
const CStringDictionary::TStringId
    FORTE_performance__ConsumerInt::scmEventInputNames[] = {STRID(REQ)};
const TForteInt16 FORTE_performance__ConsumerInt::scmEOWithIndexes[] = {-1};
const CStringDictionary::TStringId
    FORTE_performance__ConsumerInt::scmEventOutputNames[] = {STRID(CNF)};
const SFBInterfaceSpec FORTE_performance__ConsumerInt::scmFBInterfaceSpec = {
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
    1,
    scmDataInputNames,
    scmDataInputTypeIds,
    0,
    nullptr,
    nullptr,
    0,
    nullptr,
    0,
    nullptr};

FORTE_performance__ConsumerInt::FORTE_performance__ConsumerInt(
    const CStringDictionary::TStringId paInstanceNameId,
    forte::core::CFBContainer &paContainer)
    : CFunctionBlock(paContainer, scmFBInterfaceSpec, paInstanceNameId),
      var_SD(CIEC_ANY_VARIANT()), conn_CNF(*this, 0), conn_SD(nullptr){};

void FORTE_performance__ConsumerInt::setInitialValues() {
  var_SD = CIEC_ANY_VARIANT();
}

void FORTE_performance__ConsumerInt::executeEvent(
    const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch (paEIID) {
  case scmEventREQID:
    sendOutputEvent(scmEventCNFID, paECET);
    break;
  }
}

void FORTE_performance__ConsumerInt::readInputData(const TEventID paEIID) {
  switch (paEIID) {
  case scmEventREQID: {
    readData(0, var_SD, conn_SD);
    break;
  }
  default:
    break;
  }
}

void FORTE_performance__ConsumerInt::writeOutputData(TEventID) {
  // nothing to do
}

CIEC_ANY *FORTE_performance__ConsumerInt::getDI(const size_t paIndex) {
  switch (paIndex) {
  case 0:
    return &var_SD;
  }
  return nullptr;
}

CIEC_ANY *FORTE_performance__ConsumerInt::getDO(size_t) { return nullptr; }

CEventConnection *
FORTE_performance__ConsumerInt::getEOConUnchecked(const TPortId paIndex) {
  switch (paIndex) {
  case 0:
    return &conn_CNF;
  }
  return nullptr;
}

CDataConnection **
FORTE_performance__ConsumerInt::getDIConUnchecked(const TPortId paIndex) {
  switch (paIndex) {
  case 0:
    return &conn_SD;
  }
  return nullptr;
}

CDataConnection *FORTE_performance__ConsumerInt::getDOConUnchecked(TPortId) {
  return nullptr;
}
