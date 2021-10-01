#include <TimeLib.h>
#include <DS3231.h>
#include <Wire.h>
#include <Servo.h>

#define MAX_IRRIGATION_PROGRAM_COUNT 48

Servo servo;
DS3231 dsClock;
RTCDateTime rtcDate; // this is the now variable, {rtcDate.year, .month, .... , .second}
uint8_t nearestIrrigationIndex = 255; // for today

typedef struct {

    bool isActive;

    /*            Repeat Types
     *   0: none                1: daily
     *   2: weekdays            3: weekend
     *   4: weekly              5: biweekly
     *   6: monthly
    */

    uint8_t repeatTypeId;
    uint8_t duration;
    time_t irrigationStartDate; // this date will update by repeatTypeId
    time_t programEndDate;

}irrigationProgram;

irrigationProgram program[MAX_IRRIGATION_PROGRAM_COUNT]; // create Irrigation Programs

void setup() { setSystem(); }

void loop() {

    checkSystemStatus();
    delay(750);

}

//********************** Functions **************************

void defineMyPrograms(){ // You can define your irrigation programs here

    time_t tempStartDate;
    time_t tempEndDate;

    // setProgramDate(time_t whatYouWantToSet, year, month, day, hour, minute, second)
    // you should leave second 0, because we're checking the irrigation programs when the second is 0 and 1
    // look at checkSystemStatus()
    // addProgram(0 to 6: repeatTypeId, 1 to 255: duration(minute), time_t startDate, time_t endDate)
    
    /*          Repeat Types By Id
     *   0: none                1: daily
     *   2: weekdays            3: weekend
     *   4: weekly              5: biweekly
     *   6: monthly
    */

    setProgramDate(tempEndDate, 2021, 8, 25, 12, 00, 0);

    setProgramDate(tempStartDate, 2021, 8, 11, 0, 0, 0);
    addProgram(1, 5, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 0, 30, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 1, 0, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 1, 30, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 2, 0, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 2, 30, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 3, 0, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 3, 30, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 4, 0, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 4, 30, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 5, 0, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 5, 30, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 6, 0, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 6, 30, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 7, 0, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 7, 30, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 8, 0, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 8, 30, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 9, 0, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 9, 30, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 10, 0, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 10, 30, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 11, 0, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 11, 30, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 12, 0, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 12, 30, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 9, 13, 0, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 13, 30, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 14, 0, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 14, 30, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 15, 0, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 15, 30, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 16, 0, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 16, 30, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 17, 0, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 17, 30, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 18, 0, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 18, 0, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 19, 30, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 19, 0, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 20, 30, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 20, 0, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 21, 30, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 21, 0, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 22, 30, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 22, 0, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 23, 30, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

    setProgramDate(tempStartDate, 2021, 8, 10, 23, 0, 0);
    addProgram(1, 1, tempStartDate, tempEndDate);

}

void updateClockInfo(){rtcDate = dsClock.getDateTime();}

void setServo(){

    servo.attach(13);
    turnOffValve();

}

void setClockSystem(){

    Wire.begin();
    //dsClock.setDateTime(__DATE__, __TIME__); // use this once for getting the time from PC to clock
    updateClockInfo();

}

void turnOffValve(){

    servo.write(115);
    delay(150);

}

void turnOnValve(){

    servo.write(0);
    delay(150);

}

void(* resetSystem)(void) = 0;

void setSystem(){

    setServo();
    setClockSystem();
    updateClockInfo();
    deactivateAllPrograms();
    defineMyPrograms();

}

void checkSystemStatus(){

    updateClockInfo();

    if(rtcDate.second < 1){ // for not checking every time, checking every minute

        doIrrigationIfIrrigationProgramExistNow();

        if(rtcDate.hour == 0 && rtcDate.minute == 0){ // define the nearest program when it's 00.00 clock
            //defineNearestProgramToday();
            resetSystem(); // 
        }

    }

}

//************** TIME / DATE FUNCTIONS START ***********************

uint8_t getDayNumberOfWeek(tmElements_t &date){ return weekday(makeTime(date)); }
uint8_t getDayNumberOfWeek(time_t &date){ return weekday(date); }

bool isLeapYear(uint16_t programYear){

    if(programYear % 4 == 0)
        return true;
    return false;

}

bool isDateLaterThan(time_t date, time_t comparedDate){

    if(date > comparedDate)
        return true;

    return false;

}

bool isTimeSameWith(time_t date, time_t comparedDate){

    if(date == comparedDate)
        return true;

    return false;

}

uint8_t getDaysInMonth(uint16_t &dateYear, uint8_t dateMonth){

    uint8_t monthDayLimit;

    switch(dateMonth){

        case 1: return 31;

        case 2:

            if(isLeapYear(dateYear))
                return 29;
            else
                return 28;

        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;

    }

}

void addSecond(time_t &date, uint32_t secondsToBeAdded){date += secondsToBeAdded;}

void addMinute(time_t &date, uint32_t minutesToBeAdded){

    minutesToBeAdded *= 60;
    addSecond(date, minutesToBeAdded);

}

void addHour(time_t &date, uint32_t hoursToBeAdded){

    hoursToBeAdded *= 60;
    addMinute(date, hoursToBeAdded);

}

void addDay(time_t &date, uint32_t daysToBeAdded){

    daysToBeAdded *= 24;
    addHour(date, daysToBeAdded);

}

void addMonth(time_t &date, uint32_t monthsToBeAdded){

    /* if you want to add days by the day of month count you can uncomment this,
     * and don't forget you must comment 2 lines below this comment
     * 
     * usage: for example if it's 1.1.2021 and you want to add 2 months 
     * it'll add 31 days for january and add 28 days(if is leap year 29) for february

    unsigned int yearOfDate = 0;
    uint8_t monthNumber = date.Month;  

    for(int i = 0; i < monthsToBeAdded; i++){

      if(monthNumber > 12)
        monthNumber %= 12;

      yearOfDate = date.Year+1970; // //tempTmElements.Year is offset from 1970

      addDay(date, getDaysInMonth(yearOfDate, monthNumber));

      monthNumber++;

    }*/

    monthsToBeAdded *= 30;
    addDay(date, monthsToBeAdded);

}

void addYear(time_t &date, uint32_t yearsToBeAdded){

    yearsToBeAdded *= 12;
    addMonth(date, yearsToBeAdded);

}

void copyRTCDateTimeToTmElements(RTCDateTime &dsDate, tmElements_t &timeLibDate){

    timeLibDate.Hour = dsDate.hour;
    timeLibDate.Minute = dsDate.minute;
    timeLibDate.Second = dsDate.second;
    timeLibDate.Day = dsDate.day;
    timeLibDate.Month = dsDate.month;
    timeLibDate.Year = dsDate.year - 1970;

}

time_t getTimeFromRTCDateTime(RTCDateTime &dsDate){

    tmElements_t tempTmElement;
    copyRTCDateTimeToTmElements(dsDate, tempTmElement);

    return makeTime(tempTmElement);

}

//************** TIME / DATE FUNCTIONS END ***********************

//************** IRRIGATION PROGRAM FUNCTIONS START ***********************

// IRRIGATION PROGRAM GETTER FUNCTIONS START
bool getIrrigationProgramIsActive(uint8_t irrigationIndex){return  program[irrigationIndex].isActive;}
uint8_t getIrrigationProgramRepeatTypeId(uint8_t irrigationIndex) {return  program[irrigationIndex].repeatTypeId;}
uint8_t getIrrigationProgramDuration(uint8_t irrigationIndex) {return  program[irrigationIndex].duration;}
time_t getIrrigationProgramIrrigationStartDate(uint8_t irrigationIndex) {return  program[irrigationIndex].irrigationStartDate;}
time_t getIrrigationProgramEndDate(uint8_t irrigationIndex) {return  program[irrigationIndex].programEndDate;}
uint8_t getNearestIrrigationIndex(){return nearestIrrigationIndex;}

// IRRIGATION PROGRAM SETTER FUNCTIONS START
void setIrrigationProgramIsActive(uint8_t irrigationIndex, bool isActive) {program[irrigationIndex].isActive = isActive;}
void setIrrigationProgramRepeatTypeId(uint8_t irrigationIndex, uint8_t repeatTypeId) {program[irrigationIndex].repeatTypeId = repeatTypeId;}
void setIrrigationProgramDuration(uint8_t irrigationIndex, uint8_t duration) {program[irrigationIndex].duration = duration;}
void setIrrigationProgramIrrigationStartDate(uint8_t irrigationIndex, time_t startDate) {program[irrigationIndex].irrigationStartDate = startDate;}
void setIrrigationProgramEndDate(uint8_t irrigationIndex, time_t endDate) {program[irrigationIndex].programEndDate = endDate;}
void setNearestProgram(uint8_t index){nearestIrrigationIndex = index;}

// IRRIGATION PROGRAM GETTER/SETTER FUNCTIONS END

void setProgramDate(time_t &date, unsigned int programYear, uint8_t programMonth, uint8_t programDay,
                    uint8_t programHour, uint8_t programMinute, uint8_t programSecond){

    tmElements_t tempTmElements;

    tempTmElements.Year = programYear - 1970; //tempTmElements.Year is offset from 1970
    tempTmElements.Month = programMonth;
    tempTmElements.Day = programDay;
    tempTmElements.Hour = programHour;
    tempTmElements.Minute = programMinute;
    tempTmElements.Second = programSecond;

    date = makeTime(tempTmElements);

}

bool isExistEmptyProgram(){

    for(int programIndex = 0; programIndex < MAX_IRRIGATION_PROGRAM_COUNT; programIndex++){

        if(!getIrrigationProgramIsActive(programIndex))
            return true;

    }
    return false;

}

bool isNearestProgramNull(){

    if(nearestIrrigationIndex != 255)
        return false;
    return true;

}

bool isNearestProgramNull(uint8_t nearestIndex){

    if(nearestIndex == 255)
        return true;
    return false;

}

void nullNearestProgram(){nearestIrrigationIndex = 255;}

uint8_t getEmptyProgram(){

    if(isExistEmptyProgram()){

        for(int programIndex = 0; programIndex < MAX_IRRIGATION_PROGRAM_COUNT; programIndex++){

            if(!getIrrigationProgramIsActive(programIndex))
                return programIndex;

        }

    }

    return 255; // 255 =  null

}

void deactivateProgramIfExpired(uint8_t index){

    if(isIrrigationExpired(index))
        setIrrigationProgramIsActive(index, false);

}

void deactivateAllPrograms(){

    for(int programIndex = 0; programIndex < MAX_IRRIGATION_PROGRAM_COUNT; programIndex++)
        setIrrigationProgramIsActive(programIndex, false);

}

bool isExistIrrigationNow(){

    bool isNearestStartDateAndNowIsEqual =
            isTimeSameWith(getIrrigationProgramIrrigationStartDate(nearestIrrigationIndex), getTimeFromRTCDateTime(rtcDate));

    if(!isNearestProgramNull() && isNearestStartDateAndNowIsEqual)
        return true;
    return false;

}

void doIrrigationIfIrrigationProgramExistNow(){

    uint8_t nearest = getNearestIrrigationIndex();
    updateClockInfo();

    if(isExistIrrigationNow()){

        irrigate(getIrrigationProgramDuration(nearest));
        defineNearestProgramToday();

    }

}

void updateIrrigationStartDateTodayIfEarlierThanToday(uint8_t irrigationIndex){

    if(isIrrigationStartEarlierThanToday(irrigationIndex)){

        while(!isIrrigationStartDateToday(irrigationIndex) && isIrrigationStartEarlierFromNow(irrigationIndex)){
            // add days until it's today or past today

            //addDay(getIrrigationProgramIrrigationStartDate(irrigationIndex),1);
            addDay(program[irrigationIndex].irrigationStartDate,1);

        }

    }

}

void updateIrrigationStartDateIfEarlierToday(uint8_t irrigationIndex){

    if(isIrrigationStartEarlierToday(irrigationIndex)){

        addDayToIrrigationStartDateByRepeatType(irrigationIndex);

    }

}

void addDayToIrrigationStartDateByRepeatType(uint8_t irrigationIndex){

    /*            Repeat Types
     *   0: none                1: daily
     *   2: weekdays            3: weekend
     *   4: weekly              5: biweekly
     *   6: monthly
    */

    uint8_t repeatTypeId = getIrrigationProgramRepeatTypeId(irrigationIndex);

    switch(repeatTypeId){

        case 1: //daily

            addDay(program[irrigationIndex].irrigationStartDate,1); 
            break;

        case 2: //weekdays

            addDay(program[irrigationIndex].irrigationStartDate,1);

            if(weekday(getIrrigationProgramIrrigationStartDate(irrigationIndex)) > 5){
                // if added day is saturday, changing the day to monday
                addDay(program[irrigationIndex].irrigationStartDate,2); 
            }

            break;

        case 3: //weekend

            uint8_t dayNumber = 0;

            while(dayNumber == 6 || dayNumber == 7){
                addDay(program[irrigationIndex].irrigationStartDate,1); 
            }

            break;

        case 4: //weekly
            addDay(program[irrigationIndex].irrigationStartDate,7);
            break;

        case 5: //biweekly
            addDay(program[irrigationIndex].irrigationStartDate,14);
            break;

        case 6: //monthly (30 days)
            addDay(program[irrigationIndex].irrigationStartDate,30);
            break;

    }


}

void updateIrrigationStartDate(uint8_t irrigationIndex){ 

    updateIrrigationStartDateTodayIfEarlierThanToday(irrigationIndex);
    updateIrrigationStartDateIfEarlierToday(irrigationIndex);

}

void updateIrrigationProgram(uint8_t irrigationIndex){
    // nearestIrrigationIndex is for today, if there's no irrigation today the variable will be 255(null)
    // therefore when we addProgram, irrigate or etc., must update the startDate
    // and we're doing that here

    updateIrrigationStartDate(irrigationIndex);
    deactivateProgramIfExpired(irrigationIndex);

}

void updateAllIrrigationProgramsStartDate(){

    for(int programIndex = 0; programIndex < MAX_IRRIGATION_PROGRAM_COUNT; programIndex++){

        if(getIrrigationProgramIsActive(programIndex))
            updateIrrigationProgram(programIndex);

    }
}

void addProgram(uint8_t repeatId, uint8_t duration, time_t startDate, time_t endDate){

    uint8_t emptyIndex = getEmptyProgram();

    setIrrigationProgramIsActive(emptyIndex, true);
    setIrrigationProgramRepeatTypeId(emptyIndex, repeatId);
    setIrrigationProgramDuration(emptyIndex, duration);
    setIrrigationProgramIrrigationStartDate(emptyIndex, startDate);
    setIrrigationProgramEndDate(emptyIndex, endDate);

    defineNearestProgramToday();

}

bool isIrrigationExpired(uint8_t programIndex){

    updateClockInfo();

    bool isNowLaterThanIrrigationEndDate =
            isDateLaterThan(getTimeFromRTCDateTime(rtcDate), program[programIndex].programEndDate);

    bool isIrrigationStartDateLaterThanEndDate =
            isDateLaterThan(getIrrigationProgramIrrigationStartDate(programIndex), getIrrigationProgramEndDate(programIndex));

    if(isNowLaterThanIrrigationEndDate || isIrrigationStartDateLaterThanEndDate){
        return true;
    }
    else
        return false;

}

bool isIrrigationStartDateToday(uint8_t irrigationIndex){

    time_t irrigationStartDate = getIrrigationProgramIrrigationStartDate(irrigationIndex);

    if(year(irrigationStartDate) == rtcDate.year
    && month(irrigationStartDate) == rtcDate.month
    && day(irrigationStartDate) == rtcDate.day) {

        return true;

    }
    return false;

}

bool isIrrigationStartEarlierThanToday(uint8_t irrigationIndex){

    time_t irrigationStartDate = getIrrigationProgramIrrigationStartDate(irrigationIndex);
    bool isIrrigationStartDateEarlierThanToday = isDateLaterThan(getTimeFromRTCDateTime(rtcDate), irrigationStartDate);

    if(!isIrrigationStartDateToday(irrigationIndex) && isIrrigationStartDateEarlierThanToday)
        return true;
    return false;

}

bool isIrrigationStartEarlierToday(uint8_t irrigationIndex){

    time_t irrigationStartDate = getIrrigationProgramIrrigationStartDate(irrigationIndex);
    bool isIrrigationStartDateEarlierToday = isDateLaterThan(getTimeFromRTCDateTime(rtcDate), irrigationStartDate);

    if(isIrrigationStartDateToday(irrigationIndex) && isIrrigationStartDateEarlierToday)
        return true;
    return false;

}

bool isIrrigationStartEarlierFromNow(uint8_t irrigationIndex){

    time_t irrigationStartDate = getIrrigationProgramIrrigationStartDate(irrigationIndex);
    bool isIrrigationStartDateEarlierNow = isDateLaterThan(getTimeFromRTCDateTime(rtcDate), irrigationStartDate);

    if(isIrrigationStartDateEarlierNow)
        return true;
    return false;

}

bool isIrrigationProvidesRequirements(uint8_t irrigationIndex){

    if(!isIrrigationExpired(irrigationIndex)
    && getIrrigationProgramIsActive(irrigationIndex)
    && isIrrigationStartDateToday(irrigationIndex))
        return true;
    return false;

}

void defineNearestProgramToday(){

    updateAllIrrigationProgramsStartDate();

    updateClockInfo();

    uint8_t tempNearestIndex = 255;
    bool isNearestIrrigationStartDateLaterThanThisStartDate = false;

    for(int irrigationIndex = 0; irrigationIndex < MAX_IRRIGATION_PROGRAM_COUNT; irrigationIndex++){

        isNearestIrrigationStartDateLaterThanThisStartDate =
                isDateLaterThan(getIrrigationProgramIrrigationStartDate(tempNearestIndex),
                                getIrrigationProgramIrrigationStartDate(irrigationIndex));

        if(isIrrigationProvidesRequirements(irrigationIndex)
        && (isNearestProgramNull(tempNearestIndex) || isNearestIrrigationStartDateLaterThanThisStartDate)){

            tempNearestIndex = irrigationIndex;

        }

    }

    if(isNearestProgramNull(tempNearestIndex)){
        nullNearestProgram();
    }
    else{
        setNearestProgram(tempNearestIndex);
    }

}

//************** IRRIGATION PROGRAM FUNCTIONS END ***********************

void irrigate(uint8_t irrigationDuration){

    turnOnValve();
    updateClockInfo();

    time_t irrigationEndTime = getTimeFromRTCDateTime(rtcDate);
    addMinute(irrigationEndTime, irrigationDuration);

    while(!(isTimeSameWith(irrigationEndTime, getTimeFromRTCDateTime(rtcDate)))){

        updateClockInfo();
        delay(500);

        //double checking, if irrigationEndTime later than now break the while
        if(rtcDate.minute == 0 && rtcDate.second < 3
        && isDateLaterThan(getTimeFromRTCDateTime(rtcDate), irrigationEndTime))
            break;

    }

    turnOffValve();

    resetSystem(); // 

    delay(75);

}
