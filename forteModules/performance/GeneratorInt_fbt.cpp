/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: GeneratorInt
 *** Description: Service Interface Function Block Type
 *** Version:
 ***     1.0: 2024-12-21/cochicde -  -
 *************************************************************************/

#include "GeneratorInt_fbt.h"

#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"
#include "core/iec61131_functions.h"

USE_STRING_ID(Event);
USE_STRING_ID(INITO);
USE_STRING_ID(INT);
USE_STRING_ID(RD);
USE_STRING_ID(REQ);
USE_STRING_ID(performance__GeneratorInt);

DEFINE_FIRMWARE_FB(FORTE_performance__GeneratorInt,
                   STRID(performance__GeneratorInt))

const CStringDictionary::TStringId
    FORTE_performance__GeneratorInt::scmDataOutputNames[] = {STRID(RD)};
const CStringDictionary::TStringId
    FORTE_performance__GeneratorInt::scmDataOutputTypeIds[] = {STRID(INT)};
const TForteInt16 FORTE_performance__GeneratorInt::scmEIWithIndexes[] = {-1};
const CStringDictionary::TStringId
    FORTE_performance__GeneratorInt::scmEventInputNames[] = {STRID(REQ)};
const TDataIOID FORTE_performance__GeneratorInt::scmEOWith[] = {
    0, scmWithListDelimiter};
const TForteInt16 FORTE_performance__GeneratorInt::scmEOWithIndexes[] = {0};
const CStringDictionary::TStringId
    FORTE_performance__GeneratorInt::scmEventOutputNames[] = {STRID(INITO)};
const SFBInterfaceSpec FORTE_performance__GeneratorInt::scmFBInterfaceSpec = {
    1,
    scmEventInputNames,
    nullptr,
    nullptr,
    scmEIWithIndexes,
    1,
    scmEventOutputNames,
    nullptr,
    scmEOWith,
    scmEOWithIndexes,
    0,
    nullptr,
    nullptr,
    1,
    scmDataOutputNames,
    scmDataOutputTypeIds,
    0,
    nullptr,
    0,
    nullptr};

FORTE_performance__GeneratorInt::FORTE_performance__GeneratorInt(
    const CStringDictionary::TStringId paInstanceNameId,
    forte::core::CFBContainer &paContainer)
    : CFunctionBlock(paContainer, scmFBInterfaceSpec, paInstanceNameId),
      var_RD(0_INT), conn_INITO(*this, 0), conn_RD(*this, 0, var_RD){};

void FORTE_performance__GeneratorInt::setInitialValues() { var_RD = 0_INT; }

void FORTE_performance__GeneratorInt::executeEvent(
    const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch (paEIID) {
  case scmEventREQID:
    var_RD.setValue(CIEC_INT(static_cast<TForteInt16>(var_RD) + 1));
    sendOutputEvent(scmEventINITOID, paECET);
    break;
  }
}

void FORTE_performance__GeneratorInt::readInputData(TEventID) {
  // nothing to do
}

void FORTE_performance__GeneratorInt::writeOutputData(const TEventID paEIID) {
  switch (paEIID) {
  case scmEventINITOID: {
    writeData(0, var_RD, conn_RD);
    break;
  }
  default:
    break;
  }
}

CIEC_ANY *FORTE_performance__GeneratorInt::getDI(size_t) { return nullptr; }

CIEC_ANY *FORTE_performance__GeneratorInt::getDO(const size_t paIndex) {
  switch (paIndex) {
  case 0:
    return &var_RD;
  }
  return nullptr;
}

CEventConnection *
FORTE_performance__GeneratorInt::getEOConUnchecked(const TPortId paIndex) {
  switch (paIndex) {
  case 0:
    return &conn_INITO;
  }
  return nullptr;
}

CDataConnection **FORTE_performance__GeneratorInt::getDIConUnchecked(TPortId) {
  return nullptr;
}

CDataConnection *
FORTE_performance__GeneratorInt::getDOConUnchecked(const TPortId paIndex) {
  switch (paIndex) {
  case 0:
    return &conn_RD;
  }
  return nullptr;
}
