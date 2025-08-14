/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: GeneratorInt_4
 *** Description: Service Interface Function Block Type
 *** Version:
 ***     1.0: 2024-12-21/cochicde -  -
 *************************************************************************/

#include "GeneratorInt_4_fbt.h"

#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"
#include "core/iec61131_functions.h"

USE_STRING_ID(Event);
USE_STRING_ID(INITO);
USE_STRING_ID(INT);
USE_STRING_ID(RD);
USE_STRING_ID(RD2);
USE_STRING_ID(RD3);
USE_STRING_ID(RD4);
USE_STRING_ID(REQ);
USE_STRING_ID(performance__GeneratorInt_4);

DEFINE_FIRMWARE_FB(FORTE_performance__GeneratorInt_4,
                   STRID(performance__GeneratorInt_4))

const CStringDictionary::TStringId
    FORTE_performance__GeneratorInt_4::scmDataOutputNames[] = {
        STRID(RD), STRID(RD2), STRID(RD3), STRID(RD4)};
const CStringDictionary::TStringId
    FORTE_performance__GeneratorInt_4::scmDataOutputTypeIds[] = {
        STRID(INT), STRID(INT), STRID(INT), STRID(INT)};
const TForteInt16 FORTE_performance__GeneratorInt_4::scmEIWithIndexes[] = {-1};
const CStringDictionary::TStringId
    FORTE_performance__GeneratorInt_4::scmEventInputNames[] = {STRID(REQ)};
const TDataIOID FORTE_performance__GeneratorInt_4::scmEOWith[] = {
    0, 1, 2, 3, scmWithListDelimiter};
const TForteInt16 FORTE_performance__GeneratorInt_4::scmEOWithIndexes[] = {0};
const CStringDictionary::TStringId
    FORTE_performance__GeneratorInt_4::scmEventOutputNames[] = {STRID(INITO)};
const SFBInterfaceSpec FORTE_performance__GeneratorInt_4::scmFBInterfaceSpec = {
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
    4,
    scmDataOutputNames,
    scmDataOutputTypeIds,
    0,
    nullptr,
    0,
    nullptr};

FORTE_performance__GeneratorInt_4::FORTE_performance__GeneratorInt_4(
    const CStringDictionary::TStringId paInstanceNameId,
    forte::core::CFBContainer &paContainer)
    : CFunctionBlock(paContainer, scmFBInterfaceSpec, paInstanceNameId),
      var_RD(0_INT), var_RD2(0_INT), var_RD3(0_INT), var_RD4(0_INT),
      conn_INITO(*this, 0), conn_RD(*this, 0, var_RD),
      conn_RD2(*this, 1, var_RD2), conn_RD3(*this, 2, var_RD3),
      conn_RD4(*this, 3, var_RD4){};

void FORTE_performance__GeneratorInt_4::setInitialValues() {
  var_RD = 0_INT;
  var_RD2 = 0_INT;
  var_RD3 = 0_INT;
  var_RD4 = 0_INT;
}

void FORTE_performance__GeneratorInt_4::executeEvent(
    const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch (paEIID) {
  case scmEventREQID:
    var_RD.setValue(CIEC_INT(static_cast<TForteInt16>(var_RD) + 1));
    var_RD2.setValue(CIEC_INT(static_cast<TForteInt16>(var_RD2) + 1));
    var_RD3.setValue(CIEC_INT(static_cast<TForteInt16>(var_RD3) + 1));
    var_RD4.setValue(CIEC_INT(static_cast<TForteInt16>(var_RD4) + 1));
    sendOutputEvent(scmEventINITOID, paECET);
    break;
  }
}

void FORTE_performance__GeneratorInt_4::readInputData(TEventID) {
  // nothing to do
}

void FORTE_performance__GeneratorInt_4::writeOutputData(const TEventID paEIID) {
  switch (paEIID) {
  case scmEventINITOID: {
    writeData(0, var_RD, conn_RD);
    writeData(1, var_RD2, conn_RD2);
    writeData(2, var_RD3, conn_RD3);
    writeData(3, var_RD4, conn_RD4);
    break;
  }
  default:
    break;
  }
}

CIEC_ANY *FORTE_performance__GeneratorInt_4::getDI(size_t) { return nullptr; }

CIEC_ANY *FORTE_performance__GeneratorInt_4::getDO(const size_t paIndex) {
  switch (paIndex) {
  case 0:
    return &var_RD;
  case 1:
    return &var_RD2;
  case 2:
    return &var_RD3;
  case 3:
    return &var_RD4;
  }
  return nullptr;
}

CEventConnection *
FORTE_performance__GeneratorInt_4::getEOConUnchecked(const TPortId paIndex) {
  switch (paIndex) {
  case 0:
    return &conn_INITO;
  }
  return nullptr;
}

CDataConnection **
FORTE_performance__GeneratorInt_4::getDIConUnchecked(TPortId) {
  return nullptr;
}

CDataConnection *
FORTE_performance__GeneratorInt_4::getDOConUnchecked(const TPortId paIndex) {
  switch (paIndex) {
  case 0:
    return &conn_RD;
  case 1:
    return &conn_RD2;
  case 2:
    return &conn_RD3;
  case 3:
    return &conn_RD4;
  }
  return nullptr;
}
