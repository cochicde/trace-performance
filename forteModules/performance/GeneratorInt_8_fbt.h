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

#pragma once

#include "core/funcbloc.h"
#include "core/datatypes/forte_int.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

class FORTE_performance__GeneratorInt_8 final : public CFunctionBlock {
  DECLARE_FIRMWARE_FB(FORTE_performance__GeneratorInt_8)

  private:
    static const CStringDictionary::TStringId scmDataOutputNames[];
    static const CStringDictionary::TStringId scmDataOutputTypeIds[];
    static const TEventID scmEventREQID = 0;
    static const TForteInt16 scmEIWithIndexes[];
    static const CStringDictionary::TStringId scmEventInputNames[];
    static const TEventID scmEventINITOID = 0;
    static const TDataIOID scmEOWith[];
    static const TForteInt16 scmEOWithIndexes[];
    static const CStringDictionary::TStringId scmEventOutputNames[];

    static const SFBInterfaceSpec scmFBInterfaceSpec;

    void executeEvent(TEventID paEIID, CEventChainExecutionThread *const paECET) override;

    void readInputData(TEventID paEIID) override;
    void writeOutputData(TEventID paEIID) override;
    void setInitialValues() override;

  public:
    FORTE_performance__GeneratorInt_8(CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer);

    CIEC_INT var_RD;
    CIEC_INT var_RD2;
    CIEC_INT var_RD3;
    CIEC_INT var_RD4;
    CIEC_INT var_RD5;
    CIEC_INT var_RD6;
    CIEC_INT var_RD7;
    CIEC_INT var_RD8;

    CEventConnection conn_INITO;

    COutDataConnection<CIEC_INT> conn_RD;
    COutDataConnection<CIEC_INT> conn_RD2;
    COutDataConnection<CIEC_INT> conn_RD3;
    COutDataConnection<CIEC_INT> conn_RD4;
    COutDataConnection<CIEC_INT> conn_RD5;
    COutDataConnection<CIEC_INT> conn_RD6;
    COutDataConnection<CIEC_INT> conn_RD7;
    COutDataConnection<CIEC_INT> conn_RD8;

    CIEC_ANY *getDI(size_t) override;
    CIEC_ANY *getDO(size_t) override;
    CEventConnection *getEOConUnchecked(TPortId) override;
    CDataConnection **getDIConUnchecked(TPortId) override;
    CDataConnection *getDOConUnchecked(TPortId) override;

    void evt_REQ(CIEC_INT &paRD, CIEC_INT &paRD2, CIEC_INT &paRD3, CIEC_INT &paRD4, CIEC_INT &paRD5, CIEC_INT &paRD6, CIEC_INT &paRD7, CIEC_INT &paRD8) {
      executeEvent(scmEventREQID, nullptr);
      paRD = var_RD;
      paRD2 = var_RD2;
      paRD3 = var_RD3;
      paRD4 = var_RD4;
      paRD5 = var_RD5;
      paRD6 = var_RD6;
      paRD7 = var_RD7;
      paRD8 = var_RD8;
    }

    void operator()(CIEC_INT &paRD, CIEC_INT &paRD2, CIEC_INT &paRD3, CIEC_INT &paRD4, CIEC_INT &paRD5, CIEC_INT &paRD6, CIEC_INT &paRD7, CIEC_INT &paRD8) {
      evt_REQ(paRD, paRD2, paRD3, paRD4, paRD5, paRD6, paRD7, paRD8);
    }
};

