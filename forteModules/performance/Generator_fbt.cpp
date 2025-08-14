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

#include "Generator_fbt.h"

#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"
#include "core/iec61131_functions.h"

USE_STRING_ID(BOOL);
USE_STRING_ID(BYTE);
USE_STRING_ID(CHAR);
USE_STRING_ID(DATE);
USE_STRING_ID(DATE_AND_TIME);
USE_STRING_ID(DINT);
USE_STRING_ID(DWORD);
USE_STRING_ID(Event);
USE_STRING_ID(IN);
USE_STRING_ID(INT);
USE_STRING_ID(LDATE);
USE_STRING_ID(LDATE_AND_TIME);
USE_STRING_ID(LINT);
USE_STRING_ID(LREAL);
USE_STRING_ID(LTIME);
USE_STRING_ID(LTIME_OF_DAY);
USE_STRING_ID(LWORD);
USE_STRING_ID(MyStruct);
USE_STRING_ID(OUT);
USE_STRING_ID(REAL);
USE_STRING_ID(SINT);
USE_STRING_ID(STRING);
USE_STRING_ID(TIME);
USE_STRING_ID(TIME_OF_DAY);
USE_STRING_ID(UDINT);
USE_STRING_ID(UINT);
USE_STRING_ID(ULINT);
USE_STRING_ID(USINT);
USE_STRING_ID(WCHAR);
USE_STRING_ID(WORD);
USE_STRING_ID(WSTRING);
USE_STRING_ID(_bool);
USE_STRING_ID(_byte);
USE_STRING_ID(_char);
USE_STRING_ID(_date);
USE_STRING_ID(_date_and_time);
USE_STRING_ID(_dint);
USE_STRING_ID(_dword);
USE_STRING_ID(_int);
USE_STRING_ID(_l_date);
USE_STRING_ID(_l_date_and_time);
USE_STRING_ID(_l_time_of_day);
USE_STRING_ID(_lint);
USE_STRING_ID(_lreal);
USE_STRING_ID(_ltime);
USE_STRING_ID(_lword);
USE_STRING_ID(_real);
USE_STRING_ID(_sint);
USE_STRING_ID(_string);
USE_STRING_ID(_struct);
USE_STRING_ID(_time);
USE_STRING_ID(_time_of_day);
USE_STRING_ID(_udint);
USE_STRING_ID(_uint);
USE_STRING_ID(_ulint);
USE_STRING_ID(_usint);
USE_STRING_ID(_wchar);
USE_STRING_ID(_word);
USE_STRING_ID(_wstring);
USE_STRING_ID(performance__Generator);

DEFINE_FIRMWARE_FB(FORTE_performance__Generator, STRID(performance__Generator))

const CStringDictionary::TStringId
    FORTE_performance__Generator::scmDataOutputNames[] = {
        STRID(_char),          STRID(_date),          STRID(_int),
        STRID(_uint),          STRID(_sint),          STRID(_usint),
        STRID(_real),          STRID(_string),        STRID(_bool),
        STRID(_byte),          STRID(_date_and_time), STRID(_dint),
        STRID(_dword),         STRID(_lint),          STRID(_l_date_and_time),
        STRID(_l_date),        STRID(_lreal),         STRID(_ltime),
        STRID(_l_time_of_day), STRID(_lword),         STRID(_time),
        STRID(_time_of_day),   STRID(_udint),         STRID(_ulint),
        STRID(_wchar),         STRID(_word),          STRID(_wstring),
        STRID(_struct)};
const CStringDictionary::TStringId
    FORTE_performance__Generator::scmDataOutputTypeIds[] = {
        STRID(CHAR),         STRID(DATE),          STRID(INT),
        STRID(UINT),         STRID(SINT),          STRID(USINT),
        STRID(REAL),         STRID(STRING),        STRID(BOOL),
        STRID(BYTE),         STRID(DATE_AND_TIME), STRID(DINT),
        STRID(DWORD),        STRID(LINT),          STRID(LDATE_AND_TIME),
        STRID(LDATE),        STRID(LREAL),         STRID(LTIME),
        STRID(LTIME_OF_DAY), STRID(LWORD),         STRID(TIME),
        STRID(TIME_OF_DAY),  STRID(UDINT),         STRID(ULINT),
        STRID(WCHAR),        STRID(WORD),          STRID(WSTRING),
        STRID(MyStruct)};
const TForteInt16 FORTE_performance__Generator::scmEIWithIndexes[] = {-1};
const CStringDictionary::TStringId
    FORTE_performance__Generator::scmEventInputNames[] = {STRID(IN)};
const TDataIOID FORTE_performance__Generator::scmEOWith[] = {
    0,
    1,
    2,
    3,
    4,
    5,
    6,
    7,
    8,
    9,
    10,
    11,
    12,
    13,
    14,
    15,
    16,
    17,
    18,
    19,
    20,
    21,
    22,
    23,
    24,
    25,
    26,
    27,
    scmWithListDelimiter};
const TForteInt16 FORTE_performance__Generator::scmEOWithIndexes[] = {0};
const CStringDictionary::TStringId
    FORTE_performance__Generator::scmEventOutputNames[] = {STRID(OUT)};
const SFBInterfaceSpec FORTE_performance__Generator::scmFBInterfaceSpec = {
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
    28,
    scmDataOutputNames,
    scmDataOutputTypeIds,
    0,
    nullptr,
    0,
    nullptr};

FORTE_performance__Generator::FORTE_performance__Generator(
    const CStringDictionary::TStringId paInstanceNameId,
    forte::core::CFBContainer &paContainer)
    : CFunctionBlock(paContainer, scmFBInterfaceSpec, paInstanceNameId),
      var__char('\0'_CHAR), var__date(0_DATE), var__int(0_INT),
      var__uint(0_UINT), var__sint(0_SINT), var__usint(0_USINT),
      var__real(0_REAL), var__string(""_STRING), var__bool(0_BOOL),
      var__byte(0_BYTE), var__date_and_time(0_DATE_AND_TIME), var__dint(0_DINT),
      var__dword(0_DWORD), var__lint(0_LINT),
      var__l_date_and_time(0_LDATE_AND_TIME), var__l_date(0_LDATE),
      var__lreal(0_LREAL), var__ltime(0_LTIME),
      var__l_time_of_day(0_LTIME_OF_DAY), var__lword(0_LWORD),
      var__time(0_TIME), var__time_of_day(0_TIME_OF_DAY), var__udint(0_UDINT),
      var__ulint(0_ULINT), var__wchar(u'\0'_WCHAR), var__word(0_WORD),
      var__wstring(u""_WSTRING), var__struct(0_INT, ""_STRING),
      conn_OUT(*this, 0), conn__char(*this, 0, var__char),
      conn__date(*this, 1, var__date), conn__int(*this, 2, var__int),
      conn__uint(*this, 3, var__uint), conn__sint(*this, 4, var__sint),
      conn__usint(*this, 5, var__usint), conn__real(*this, 6, var__real),
      conn__string(*this, 7, var__string), conn__bool(*this, 8, var__bool),
      conn__byte(*this, 9, var__byte),
      conn__date_and_time(*this, 10, var__date_and_time),
      conn__dint(*this, 11, var__dint), conn__dword(*this, 12, var__dword),
      conn__lint(*this, 13, var__lint),
      conn__l_date_and_time(*this, 14, var__l_date_and_time),
      conn__l_date(*this, 15, var__l_date), conn__lreal(*this, 16, var__lreal),
      conn__ltime(*this, 17, var__ltime),
      conn__l_time_of_day(*this, 18, var__l_time_of_day),
      conn__lword(*this, 19, var__lword), conn__time(*this, 20, var__time),
      conn__time_of_day(*this, 21, var__time_of_day),
      conn__udint(*this, 22, var__udint), conn__ulint(*this, 23, var__ulint),
      conn__wchar(*this, 24, var__wchar), conn__word(*this, 25, var__word),
      conn__wstring(*this, 26, var__wstring),
      conn__struct(*this, 27, var__struct){};

void FORTE_performance__Generator::setInitialValues() {
  var__char = '\0'_CHAR;
  var__date = 0_DATE;
  var__int = 0_INT;
  var__uint = 0_UINT;
  var__sint = 0_SINT;
  var__usint = 0_USINT;
  var__real = 0_REAL;
  var__string = ""_STRING;
  var__bool = 0_BOOL;
  var__byte = 0_BYTE;
  var__date_and_time = 0_DATE_AND_TIME;
  var__dint = 0_DINT;
  var__dword = 0_DWORD;
  var__lint = 0_LINT;
  var__l_date_and_time = 0_LDATE_AND_TIME;
  var__l_date = 0_LDATE;
  var__lreal = 0_LREAL;
  var__ltime = 0_LTIME;
  var__l_time_of_day = 0_LTIME_OF_DAY;
  var__lword = 0_LWORD;
  var__time = 0_TIME;
  var__time_of_day = 0_TIME_OF_DAY;
  var__udint = 0_UDINT;
  var__ulint = 0_ULINT;
  var__wchar = u'\0'_WCHAR;
  var__word = 0_WORD;
  var__wstring = u""_WSTRING;
  var__struct.var__int = 0_INT;
  var__struct.var__string = ""_STRING;
}

void FORTE_performance__Generator::executeEvent(
    const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch (paEIID) {
  case scmEventINID:
    var__char = CIEC_CHAR(static_cast<CIEC_CHAR::TValueType>(var__char) +
                          static_cast<CIEC_CHAR::TValueType>(1));
    var__date = CIEC_DATE(static_cast<CIEC_DATE::TValueType>(var__date) +
                          static_cast<CIEC_DATE::TValueType>(1));
    var__int = CIEC_INT(static_cast<CIEC_INT::TValueType>(var__int) +
                        static_cast<CIEC_INT::TValueType>(1));
    var__uint = CIEC_UINT(static_cast<CIEC_UINT::TValueType>(var__uint) +
                          static_cast<CIEC_UINT::TValueType>(1));
    var__sint = CIEC_SINT(static_cast<CIEC_SINT::TValueType>(var__sint) +
                          static_cast<CIEC_SINT::TValueType>(1));
    var__usint = CIEC_USINT(static_cast<CIEC_USINT::TValueType>(var__usint) +
                            static_cast<CIEC_USINT::TValueType>(1));
    var__real = CIEC_REAL(static_cast<CIEC_REAL::TValueType>(var__real) +
                          static_cast<CIEC_REAL::TValueType>(1));
    var__string =
        CIEC_STRING(CIEC_CHAR(static_cast<CIEC_CHAR::TValueType>(var__char) +
                              static_cast<CIEC_CHAR::TValueType>(1)));
    var__bool = CIEC_BOOL(static_cast<CIEC_BOOL::TValueType>(var__bool) +
                          static_cast<CIEC_BOOL::TValueType>(1));
    var__byte = CIEC_BYTE(static_cast<CIEC_BYTE::TValueType>(var__byte) +
                          static_cast<CIEC_BYTE::TValueType>(1));
    var__date_and_time = CIEC_DATE_AND_TIME(
        static_cast<CIEC_DATE_AND_TIME::TValueType>(var__date_and_time) +
        static_cast<CIEC_DATE_AND_TIME::TValueType>(1));
    var__dint = CIEC_DINT(static_cast<CIEC_DINT::TValueType>(var__dint) +
                          static_cast<CIEC_DINT::TValueType>(1));
    var__dword = CIEC_DWORD(static_cast<CIEC_DWORD::TValueType>(var__dword) +
                            static_cast<CIEC_DWORD::TValueType>(1));
    var__lint = CIEC_LINT(static_cast<CIEC_LINT::TValueType>(var__lint) +
                          static_cast<CIEC_LINT::TValueType>(1));
    var__l_date_and_time = CIEC_LDATE_AND_TIME(
        static_cast<CIEC_LDATE_AND_TIME::TValueType>(var__l_date_and_time) +
        static_cast<CIEC_LDATE_AND_TIME::TValueType>(1));
    var__l_date = CIEC_LDATE(static_cast<CIEC_LDATE::TValueType>(var__l_date) +
                             static_cast<CIEC_LDATE::TValueType>(1));
    var__lreal = CIEC_LREAL(static_cast<CIEC_LREAL::TValueType>(var__lreal) +
                            static_cast<CIEC_LREAL::TValueType>(1));
    var__ltime = CIEC_LTIME(static_cast<CIEC_LTIME::TValueType>(var__ltime) +
                            static_cast<CIEC_LTIME::TValueType>(1));
    var__l_time_of_day = CIEC_LTIME_OF_DAY(
        static_cast<CIEC_LTIME_OF_DAY::TValueType>(var__l_time_of_day) +
        static_cast<CIEC_LTIME_OF_DAY::TValueType>(1));
    var__lword = CIEC_LWORD(static_cast<CIEC_LWORD::TValueType>(var__lword) +
                            static_cast<CIEC_LWORD::TValueType>(1));
    var__time = CIEC_TIME(static_cast<CIEC_TIME::TValueType>(var__time) +
                          static_cast<CIEC_TIME::TValueType>(1));
    var__time_of_day = CIEC_TIME_OF_DAY(
        static_cast<CIEC_TIME_OF_DAY::TValueType>(var__time_of_day) +
        static_cast<CIEC_TIME_OF_DAY::TValueType>(1));
    var__udint = CIEC_UDINT(static_cast<CIEC_UDINT::TValueType>(var__udint) +
                            static_cast<CIEC_UDINT::TValueType>(1));
    var__ulint = CIEC_ULINT(static_cast<CIEC_ULINT::TValueType>(var__ulint) +
                            static_cast<CIEC_ULINT::TValueType>(1));
    var__wchar = CIEC_WCHAR(static_cast<CIEC_WCHAR::TValueType>(var__wchar) +
                            static_cast<CIEC_WCHAR::TValueType>(1));
    var__word = CIEC_WORD(static_cast<CIEC_WORD::TValueType>(var__word) +
                          static_cast<CIEC_WORD::TValueType>(1));
    var__wstring = CIEC_WSTRING(
        CIEC_WCHAR(static_cast<CIEC_WCHAR::TValueType>(var__wchar) +
                   static_cast<CIEC_WCHAR::TValueType>(1)));
    // *var__struct.getMember(0) = static_cast<TForteChar>(var__char)++;
    // *var__struct.getMember(1) = static_cast<TForteChar>(var__char)++;

    sendOutputEvent(scmEventOUTID, paECET);
    break;
  }
}

void FORTE_performance__Generator::readInputData(TEventID) {
  // nothing to do
}

void FORTE_performance__Generator::writeOutputData(const TEventID paEIID) {
  switch (paEIID) {
  case scmEventOUTID: {
    writeData(0, var__char, conn__char);
    writeData(1, var__date, conn__date);
    writeData(2, var__int, conn__int);
    writeData(3, var__uint, conn__uint);
    writeData(4, var__sint, conn__sint);
    writeData(5, var__usint, conn__usint);
    writeData(6, var__real, conn__real);
    writeData(7, var__string, conn__string);
    writeData(8, var__bool, conn__bool);
    writeData(9, var__byte, conn__byte);
    writeData(10, var__date_and_time, conn__date_and_time);
    writeData(11, var__dint, conn__dint);
    writeData(12, var__dword, conn__dword);
    writeData(13, var__lint, conn__lint);
    writeData(14, var__l_date_and_time, conn__l_date_and_time);
    writeData(15, var__l_date, conn__l_date);
    writeData(16, var__lreal, conn__lreal);
    writeData(17, var__ltime, conn__ltime);
    writeData(18, var__l_time_of_day, conn__l_time_of_day);
    writeData(19, var__lword, conn__lword);
    writeData(20, var__time, conn__time);
    writeData(21, var__time_of_day, conn__time_of_day);
    writeData(22, var__udint, conn__udint);
    writeData(23, var__ulint, conn__ulint);
    writeData(24, var__wchar, conn__wchar);
    writeData(25, var__word, conn__word);
    writeData(26, var__wstring, conn__wstring);
    writeData(27, var__struct, conn__struct);
    break;
  }
  default:
    break;
  }
}

CIEC_ANY *FORTE_performance__Generator::getDI(size_t) { return nullptr; }

CIEC_ANY *FORTE_performance__Generator::getDO(const size_t paIndex) {
  switch (paIndex) {
  case 0:
    return &var__char;
  case 1:
    return &var__date;
  case 2:
    return &var__int;
  case 3:
    return &var__uint;
  case 4:
    return &var__sint;
  case 5:
    return &var__usint;
  case 6:
    return &var__real;
  case 7:
    return &var__string;
  case 8:
    return &var__bool;
  case 9:
    return &var__byte;
  case 10:
    return &var__date_and_time;
  case 11:
    return &var__dint;
  case 12:
    return &var__dword;
  case 13:
    return &var__lint;
  case 14:
    return &var__l_date_and_time;
  case 15:
    return &var__l_date;
  case 16:
    return &var__lreal;
  case 17:
    return &var__ltime;
  case 18:
    return &var__l_time_of_day;
  case 19:
    return &var__lword;
  case 20:
    return &var__time;
  case 21:
    return &var__time_of_day;
  case 22:
    return &var__udint;
  case 23:
    return &var__ulint;
  case 24:
    return &var__wchar;
  case 25:
    return &var__word;
  case 26:
    return &var__wstring;
  case 27:
    return &var__struct;
  }
  return nullptr;
}

CEventConnection *
FORTE_performance__Generator::getEOConUnchecked(const TPortId paIndex) {
  switch (paIndex) {
  case 0:
    return &conn_OUT;
  }
  return nullptr;
}

CDataConnection **FORTE_performance__Generator::getDIConUnchecked(TPortId) {
  return nullptr;
}

CDataConnection *
FORTE_performance__Generator::getDOConUnchecked(const TPortId paIndex) {
  switch (paIndex) {
  case 0:
    return &conn__char;
  case 1:
    return &conn__date;
  case 2:
    return &conn__int;
  case 3:
    return &conn__uint;
  case 4:
    return &conn__sint;
  case 5:
    return &conn__usint;
  case 6:
    return &conn__real;
  case 7:
    return &conn__string;
  case 8:
    return &conn__bool;
  case 9:
    return &conn__byte;
  case 10:
    return &conn__date_and_time;
  case 11:
    return &conn__dint;
  case 12:
    return &conn__dword;
  case 13:
    return &conn__lint;
  case 14:
    return &conn__l_date_and_time;
  case 15:
    return &conn__l_date;
  case 16:
    return &conn__lreal;
  case 17:
    return &conn__ltime;
  case 18:
    return &conn__l_time_of_day;
  case 19:
    return &conn__lword;
  case 20:
    return &conn__time;
  case 21:
    return &conn__time_of_day;
  case 22:
    return &conn__udint;
  case 23:
    return &conn__ulint;
  case 24:
    return &conn__wchar;
  case 25:
    return &conn__word;
  case 26:
    return &conn__wstring;
  case 27:
    return &conn__struct;
  }
  return nullptr;
}
