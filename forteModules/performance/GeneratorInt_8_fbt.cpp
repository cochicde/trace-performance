/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: GeneratorInt_8
 *** Description: Service Interface Function Block Type
 *** Version:
 ***     1.0: 2024-12-21/cochicde -  -
 *************************************************************************/

#include "GeneratorInt_8_fbt.h"

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
USE_STRING_ID(RD5);
USE_STRING_ID(RD6);
USE_STRING_ID(RD7);
USE_STRING_ID(RD8);
USE_STRING_ID(REQ);
USE_STRING_ID(performance__GeneratorInt_8);

DEFINE_FIRMWARE_FB(FORTE_performance__GeneratorInt_8,
                   STRID(performance__GeneratorInt_8))

const CStringDictionary::TStringId
    FORTE_performance__GeneratorInt_8::scmDataOutputNames[] = {
        STRID(RD),  STRID(RD2), STRID(RD3), STRID(RD4),
        STRID(RD5), STRID(RD6), STRID(RD7), STRID(RD8)};
const CStringDictionary::TStringId
    FORTE_performance__GeneratorInt_8::scmDataOutputTypeIds[] = {
        STRID(INT), STRID(INT), STRID(INT), STRID(INT),
        STRID(INT), STRID(INT), STRID(INT), STRID(INT)};
const TForteInt16 FORTE_performance__GeneratorInt_8::scmEIWithIndexes[] = {-1};
const CStringDictionary::TStringId
    FORTE_performance__GeneratorInt_8::scmEventInputNames[] = {STRID(REQ)};
const TDataIOID FORTE_performance__GeneratorInt_8::scmEOWith[] = {
    0, 1, 2, 4, 3, 5, 7, 6, scmWithListDelimiter};
const TForteInt16 FORTE_performance__GeneratorInt_8::scmEOWithIndexes[] = {0};
const CStringDictionary::TStringId
    FORTE_performance__GeneratorInt_8::scmEventOutputNames[] = {STRID(INITO)};
const SFBInterfaceSpec FORTE_performance__GeneratorInt_8::scmFBInterfaceSpec = {
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
    8,
    scmDataOutputNames,
    scmDataOutputTypeIds,
    0,
    nullptr,
    0,
    nullptr};

FORTE_performance__GeneratorInt_8::FORTE_performance__GeneratorInt_8(
    const CStringDictionary::TStringId paInstanceNameId,
    forte::core::CFBContainer &paContainer)
    : CFunctionBlock(paContainer, scmFBInterfaceSpec, paInstanceNameId),
      var_RD(0_INT), var_RD2(0_INT), var_RD3(0_INT), var_RD4(0_INT),
      var_RD5(0_INT), var_RD6(0_INT), var_RD7(0_INT), var_RD8(0_INT),
      conn_INITO(*this, 0), conn_RD(*this, 0, var_RD),
      conn_RD2(*this, 1, var_RD2), conn_RD3(*this, 2, var_RD3),
      conn_RD4(*this, 3, var_RD4), conn_RD5(*this, 4, var_RD5),
      conn_RD6(*this, 5, var_RD6), conn_RD7(*this, 6, var_RD7),
      conn_RD8(*this, 7, var_RD8){};

void FORTE_performance__GeneratorInt_8::setInitialValues() {
  var_RD = 0_INT;
  var_RD2 = 0_INT;
  var_RD3 = 0_INT;
  var_RD4 = 0_INT;
  var_RD5 = 0_INT;
  var_RD6 = 0_INT;
  var_RD7 = 0_INT;
  var_RD8 = 0_INT;
}

void FORTE_performance__GeneratorInt_8::executeEvent(
    const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch (paEIID) {
  case scmEventREQID:
    var_RD.setValue(CIEC_INT(static_cast<TForteInt16>(var_RD) + 1));
    var_RD2.setValue(CIEC_INT(static_cast<TForteInt16>(var_RD2) + 1));
    var_RD3.setValue(CIEC_INT(static_cast<TForteInt16>(var_RD3) + 1));
    var_RD4.setValue(CIEC_INT(static_cast<TForteInt16>(var_RD4) + 1));
    var_RD5.setValue(CIEC_INT(static_cast<TForteInt16>(var_RD5) + 1));
    var_RD6.setValue(CIEC_INT(static_cast<TForteInt16>(var_RD6) + 1));
    var_RD7.setValue(CIEC_INT(static_cast<TForteInt16>(var_RD7) + 1));
    var_RD8.setValue(CIEC_INT(static_cast<TForteInt16>(var_RD8) + 1));
    sendOutputEvent(scmEventINITOID, paECET);
    break;
  }
}

void FORTE_performance__GeneratorInt_8::readInputData(TEventID) {
  // nothing to do
}

void FORTE_performance__GeneratorInt_8::writeOutputData(const TEventID paEIID) {
  switch (paEIID) {
  case scmEventINITOID: {
    writeData(0, var_RD, conn_RD);
    writeData(1, var_RD2, conn_RD2);
    writeData(2, var_RD3, conn_RD3);
    writeData(4, var_RD5, conn_RD5);
    writeData(3, var_RD4, conn_RD4);
    writeData(5, var_RD6, conn_RD6);
    writeData(7, var_RD8, conn_RD8);
    writeData(6, var_RD7, conn_RD7);
    break;
  }
  default:
    break;
  }
}

CIEC_ANY *FORTE_performance__GeneratorInt_8::getDI(size_t) { return nullptr; }

CIEC_ANY *FORTE_performance__GeneratorInt_8::getDO(const size_t paIndex) {
  switch (paIndex) {
  case 0:
    return &var_RD;
  case 1:
    return &var_RD2;
  case 2:
    return &var_RD3;
  case 3:
    return &var_RD4;
  case 4:
    return &var_RD5;
  case 5:
    return &var_RD6;
  case 6:
    return &var_RD7;
  case 7:
    return &var_RD8;
  }
  return nullptr;
}

CEventConnection *
FORTE_performance__GeneratorInt_8::getEOConUnchecked(const TPortId paIndex) {
  switch (paIndex) {
  case 0:
    return &conn_INITO;
  }
  return nullptr;
}

CDataConnection **
FORTE_performance__GeneratorInt_8::getDIConUnchecked(TPortId) {
  return nullptr;
}

CDataConnection *
FORTE_performance__GeneratorInt_8::getDOConUnchecked(const TPortId paIndex) {
  switch (paIndex) {
  case 0:
    return &conn_RD;
  case 1:
    return &conn_RD2;
  case 2:
    return &conn_RD3;
  case 3:
    return &conn_RD4;
  case 4:
    return &conn_RD5;
  case 5:
    return &conn_RD6;
  case 6:
    return &conn_RD7;
  case 7:
    return &conn_RD8;
  }
  return nullptr;
}
