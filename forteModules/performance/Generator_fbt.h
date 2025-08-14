/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: Generator
 *** Description: Service Interface Function Block Type
 *** Version:
 ***     1.0: 2024-12-18/cochicde -  -
 *************************************************************************/

#pragma once

#include "MyStruct_dtp.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"
#include "core/datatypes/forte_bool.h"
#include "core/datatypes/forte_byte.h"
#include "core/datatypes/forte_char.h"
#include "core/datatypes/forte_date.h"
#include "core/datatypes/forte_date_and_time.h"
#include "core/datatypes/forte_dint.h"
#include "core/datatypes/forte_dword.h"
#include "core/datatypes/forte_int.h"
#include "core/datatypes/forte_ldate.h"
#include "core/datatypes/forte_ldate_and_time.h"
#include "core/datatypes/forte_lint.h"
#include "core/datatypes/forte_lreal.h"
#include "core/datatypes/forte_ltime.h"
#include "core/datatypes/forte_ltime_of_day.h"
#include "core/datatypes/forte_lword.h"
#include "core/datatypes/forte_real.h"
#include "core/datatypes/forte_sint.h"
#include "core/datatypes/forte_string.h"
#include "core/datatypes/forte_time.h"
#include "core/datatypes/forte_time_of_day.h"
#include "core/datatypes/forte_udint.h"
#include "core/datatypes/forte_uint.h"
#include "core/datatypes/forte_ulint.h"
#include "core/datatypes/forte_usint.h"
#include "core/datatypes/forte_wchar.h"
#include "core/datatypes/forte_word.h"
#include "core/datatypes/forte_wstring.h"
#include "core/funcbloc.h"
#include "core/iec61131_functions.h"

class FORTE_performance__Generator final : public CFunctionBlock {
  DECLARE_FIRMWARE_FB(FORTE_performance__Generator)

private:
  static const CStringDictionary::TStringId scmDataOutputNames[];
  static const CStringDictionary::TStringId scmDataOutputTypeIds[];
  static const TEventID scmEventINID = 0;
  static const TForteInt16 scmEIWithIndexes[];
  static const CStringDictionary::TStringId scmEventInputNames[];
  static const TEventID scmEventOUTID = 0;
  static const TDataIOID scmEOWith[];
  static const TForteInt16 scmEOWithIndexes[];
  static const CStringDictionary::TStringId scmEventOutputNames[];

  static const SFBInterfaceSpec scmFBInterfaceSpec;

  void executeEvent(TEventID paEIID,
                    CEventChainExecutionThread *const paECET) override;

  void readInputData(TEventID paEIID) override;
  void writeOutputData(TEventID paEIID) override;
  void setInitialValues() override;

public:
  FORTE_performance__Generator(CStringDictionary::TStringId paInstanceNameId,
                               forte::core::CFBContainer &paContainer);

  CIEC_CHAR var__char;
  CIEC_DATE var__date;
  CIEC_INT var__int;
  CIEC_UINT var__uint;
  CIEC_SINT var__sint;
  CIEC_USINT var__usint;
  CIEC_REAL var__real;
  CIEC_STRING var__string;
  CIEC_BOOL var__bool;
  CIEC_BYTE var__byte;
  CIEC_DATE_AND_TIME var__date_and_time;
  CIEC_DINT var__dint;
  CIEC_DWORD var__dword;
  CIEC_LINT var__lint;
  CIEC_LDATE_AND_TIME var__l_date_and_time;
  CIEC_LDATE var__l_date;
  CIEC_LREAL var__lreal;
  CIEC_LTIME var__ltime;
  CIEC_LTIME_OF_DAY var__l_time_of_day;
  CIEC_LWORD var__lword;
  CIEC_TIME var__time;
  CIEC_TIME_OF_DAY var__time_of_day;
  CIEC_UDINT var__udint;
  CIEC_ULINT var__ulint;
  CIEC_WCHAR var__wchar;
  CIEC_WORD var__word;
  CIEC_WSTRING var__wstring;
  CIEC_performance__MyStruct var__struct;

  CEventConnection conn_OUT;

  COutDataConnection<CIEC_CHAR> conn__char;
  COutDataConnection<CIEC_DATE> conn__date;
  COutDataConnection<CIEC_INT> conn__int;
  COutDataConnection<CIEC_UINT> conn__uint;
  COutDataConnection<CIEC_SINT> conn__sint;
  COutDataConnection<CIEC_USINT> conn__usint;
  COutDataConnection<CIEC_REAL> conn__real;
  COutDataConnection<CIEC_STRING> conn__string;
  COutDataConnection<CIEC_BOOL> conn__bool;
  COutDataConnection<CIEC_BYTE> conn__byte;
  COutDataConnection<CIEC_DATE_AND_TIME> conn__date_and_time;
  COutDataConnection<CIEC_DINT> conn__dint;
  COutDataConnection<CIEC_DWORD> conn__dword;
  COutDataConnection<CIEC_LINT> conn__lint;
  COutDataConnection<CIEC_LDATE_AND_TIME> conn__l_date_and_time;
  COutDataConnection<CIEC_LDATE> conn__l_date;
  COutDataConnection<CIEC_LREAL> conn__lreal;
  COutDataConnection<CIEC_LTIME> conn__ltime;
  COutDataConnection<CIEC_LTIME_OF_DAY> conn__l_time_of_day;
  COutDataConnection<CIEC_LWORD> conn__lword;
  COutDataConnection<CIEC_TIME> conn__time;
  COutDataConnection<CIEC_TIME_OF_DAY> conn__time_of_day;
  COutDataConnection<CIEC_UDINT> conn__udint;
  COutDataConnection<CIEC_ULINT> conn__ulint;
  COutDataConnection<CIEC_WCHAR> conn__wchar;
  COutDataConnection<CIEC_WORD> conn__word;
  COutDataConnection<CIEC_WSTRING> conn__wstring;
  COutDataConnection<CIEC_performance__MyStruct> conn__struct;

  CIEC_ANY *getDI(size_t) override;
  CIEC_ANY *getDO(size_t) override;
  CEventConnection *getEOConUnchecked(TPortId) override;
  CDataConnection **getDIConUnchecked(TPortId) override;
  CDataConnection *getDOConUnchecked(TPortId) override;

  void evt_IN(CIEC_CHAR &pa_char, CIEC_DATE &pa_date, CIEC_INT &pa_int,
              CIEC_UINT &pa_uint, CIEC_SINT &pa_sint, CIEC_USINT &pa_usint,
              CIEC_REAL &pa_real, CIEC_STRING &pa_string, CIEC_BOOL &pa_bool,
              CIEC_BYTE &pa_byte, CIEC_DATE_AND_TIME &pa_date_and_time,
              CIEC_DINT &pa_dint, CIEC_DWORD &pa_dword, CIEC_LINT &pa_lint,
              CIEC_LDATE_AND_TIME &pa_l_date_and_time, CIEC_LDATE &pa_l_date,
              CIEC_LREAL &pa_lreal, CIEC_LTIME &pa_ltime,
              CIEC_LTIME_OF_DAY &pa_l_time_of_day, CIEC_LWORD &pa_lword,
              CIEC_TIME &pa_time, CIEC_TIME_OF_DAY &pa_time_of_day,
              CIEC_UDINT &pa_udint, CIEC_ULINT &pa_ulint, CIEC_WCHAR &pa_wchar,
              CIEC_WORD &pa_word, CIEC_WSTRING &pa_wstring,
              CIEC_performance__MyStruct &pa_struct) {
    executeEvent(scmEventINID, nullptr);
    pa_char = var__char;
    pa_date = var__date;
    pa_int = var__int;
    pa_uint = var__uint;
    pa_sint = var__sint;
    pa_usint = var__usint;
    pa_real = var__real;
    pa_string = var__string;
    pa_bool = var__bool;
    pa_byte = var__byte;
    pa_date_and_time = var__date_and_time;
    pa_dint = var__dint;
    pa_dword = var__dword;
    pa_lint = var__lint;
    pa_l_date_and_time = var__l_date_and_time;
    pa_l_date = var__l_date;
    pa_lreal = var__lreal;
    pa_ltime = var__ltime;
    pa_l_time_of_day = var__l_time_of_day;
    pa_lword = var__lword;
    pa_time = var__time;
    pa_time_of_day = var__time_of_day;
    pa_udint = var__udint;
    pa_ulint = var__ulint;
    pa_wchar = var__wchar;
    pa_word = var__word;
    pa_wstring = var__wstring;
    pa_struct = var__struct;
  }

  void operator()(CIEC_CHAR &pa_char, CIEC_DATE &pa_date, CIEC_INT &pa_int,
                  CIEC_UINT &pa_uint, CIEC_SINT &pa_sint, CIEC_USINT &pa_usint,
                  CIEC_REAL &pa_real, CIEC_STRING &pa_string,
                  CIEC_BOOL &pa_bool, CIEC_BYTE &pa_byte,
                  CIEC_DATE_AND_TIME &pa_date_and_time, CIEC_DINT &pa_dint,
                  CIEC_DWORD &pa_dword, CIEC_LINT &pa_lint,
                  CIEC_LDATE_AND_TIME &pa_l_date_and_time,
                  CIEC_LDATE &pa_l_date, CIEC_LREAL &pa_lreal,
                  CIEC_LTIME &pa_ltime, CIEC_LTIME_OF_DAY &pa_l_time_of_day,
                  CIEC_LWORD &pa_lword, CIEC_TIME &pa_time,
                  CIEC_TIME_OF_DAY &pa_time_of_day, CIEC_UDINT &pa_udint,
                  CIEC_ULINT &pa_ulint, CIEC_WCHAR &pa_wchar,
                  CIEC_WORD &pa_word, CIEC_WSTRING &pa_wstring,
                  CIEC_performance__MyStruct &pa_struct) {
    evt_IN(pa_char, pa_date, pa_int, pa_uint, pa_sint, pa_usint, pa_real,
           pa_string, pa_bool, pa_byte, pa_date_and_time, pa_dint, pa_dword,
           pa_lint, pa_l_date_and_time, pa_l_date, pa_lreal, pa_ltime,
           pa_l_time_of_day, pa_lword, pa_time, pa_time_of_day, pa_udint,
           pa_ulint, pa_wchar, pa_word, pa_wstring, pa_struct);
  }
};
