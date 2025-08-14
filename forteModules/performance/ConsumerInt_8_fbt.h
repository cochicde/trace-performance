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

#pragma once

#include "core/funcbloc.h"
#include "core/datatypes/forte_any_variant.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

class FORTE_performance__ConsumerInt_8 final : public CFunctionBlock {
  DECLARE_FIRMWARE_FB(FORTE_performance__ConsumerInt_8)

  private:
    static const CStringDictionary::TStringId scmDataInputNames[];
    static const CStringDictionary::TStringId scmDataInputTypeIds[];
    static const TEventID scmEventREQID = 0;
    static const TDataIOID scmEIWith[];
    static const TForteInt16 scmEIWithIndexes[];
    static const CStringDictionary::TStringId scmEventInputNames[];
    static const TEventID scmEventCNFID = 0;
    static const TForteInt16 scmEOWithIndexes[];
    static const CStringDictionary::TStringId scmEventOutputNames[];

    static const SFBInterfaceSpec scmFBInterfaceSpec;

    void executeEvent(TEventID paEIID, CEventChainExecutionThread *const paECET) override;

    void readInputData(TEventID paEIID) override;
    void writeOutputData(TEventID paEIID) override;
    void setInitialValues() override;

  public:
    FORTE_performance__ConsumerInt_8(CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer);

    CIEC_ANY_VARIANT var_SD;
    CIEC_ANY_VARIANT var_SD2;
    CIEC_ANY_VARIANT var_SD3;
    CIEC_ANY_VARIANT var_SD4;
    CIEC_ANY_VARIANT var_SD5;
    CIEC_ANY_VARIANT var_SD6;
    CIEC_ANY_VARIANT var_SD7;
    CIEC_ANY_VARIANT var_SD8;

    CEventConnection conn_CNF;

    CDataConnection *conn_SD;
    CDataConnection *conn_SD2;
    CDataConnection *conn_SD3;
    CDataConnection *conn_SD4;
    CDataConnection *conn_SD5;
    CDataConnection *conn_SD6;
    CDataConnection *conn_SD7;
    CDataConnection *conn_SD8;

    CIEC_ANY *getDI(size_t) override;
    CIEC_ANY *getDO(size_t) override;
    CEventConnection *getEOConUnchecked(TPortId) override;
    CDataConnection **getDIConUnchecked(TPortId) override;
    CDataConnection *getDOConUnchecked(TPortId) override;

    void evt_REQ(const CIEC_ANY &paSD, const CIEC_ANY &paSD2, const CIEC_ANY &paSD3, const CIEC_ANY &paSD4, const CIEC_ANY &paSD5, const CIEC_ANY &paSD6, const CIEC_ANY &paSD7, const CIEC_ANY &paSD8) {
      var_SD = paSD;
      var_SD2 = paSD2;
      var_SD3 = paSD3;
      var_SD4 = paSD4;
      var_SD5 = paSD5;
      var_SD6 = paSD6;
      var_SD7 = paSD7;
      var_SD8 = paSD8;
      executeEvent(scmEventREQID, nullptr);
    }

    void operator()(const CIEC_ANY &paSD, const CIEC_ANY &paSD2, const CIEC_ANY &paSD3, const CIEC_ANY &paSD4, const CIEC_ANY &paSD5, const CIEC_ANY &paSD6, const CIEC_ANY &paSD7, const CIEC_ANY &paSD8) {
      evt_REQ(paSD, paSD2, paSD3, paSD4, paSD5, paSD6, paSD7, paSD8);
    }
};

