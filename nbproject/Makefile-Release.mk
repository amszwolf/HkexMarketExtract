#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/DataExtract/FutureInstrument.o \
	${OBJECTDIR}/DataExtract/HkexExtractor.o \
	${OBJECTDIR}/DataExtract/Instrument.o \
	${OBJECTDIR}/Util/UtilConfigAccess.o \
	${OBJECTDIR}/Util/UtilDateTime.o \
	${OBJECTDIR}/Util/UtilHttpRequestHandler.o \
	${OBJECTDIR}/Util/UtilLogger.o \
	${OBJECTDIR}/Util/UtilMysqlClient.o \
	${OBJECTDIR}/main.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-std=c++11
CXXFLAGS=-std=c++11

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/usr/local/lib -L/usr/lib64/mysql -lboost_date_time -lboost_system -lboost_thread -lboost_regex -lmysqlpp -lmysqlclient -llog4cplus

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/HkexMarketExtract

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/HkexMarketExtract: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/HkexMarketExtract ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/DataExtract/FutureInstrument.o: nbproject/Makefile-${CND_CONF}.mk DataExtract/FutureInstrument.cpp 
	${MKDIR} -p ${OBJECTDIR}/DataExtract
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/local/include/ -I/usr/include/ -I/usr/local/include/mysql++ -I/usr/include/mysql -I. -IUtil -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataExtract/FutureInstrument.o DataExtract/FutureInstrument.cpp

${OBJECTDIR}/DataExtract/HkexExtractor.o: nbproject/Makefile-${CND_CONF}.mk DataExtract/HkexExtractor.cpp 
	${MKDIR} -p ${OBJECTDIR}/DataExtract
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/local/include/ -I/usr/include/ -I/usr/local/include/mysql++ -I/usr/include/mysql -I. -IUtil -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataExtract/HkexExtractor.o DataExtract/HkexExtractor.cpp

${OBJECTDIR}/DataExtract/Instrument.o: nbproject/Makefile-${CND_CONF}.mk DataExtract/Instrument.cpp 
	${MKDIR} -p ${OBJECTDIR}/DataExtract
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/local/include/ -I/usr/include/ -I/usr/local/include/mysql++ -I/usr/include/mysql -I. -IUtil -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataExtract/Instrument.o DataExtract/Instrument.cpp

${OBJECTDIR}/Util/UtilConfigAccess.o: nbproject/Makefile-${CND_CONF}.mk Util/UtilConfigAccess.cpp 
	${MKDIR} -p ${OBJECTDIR}/Util
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/local/include/ -I/usr/include/ -I/usr/local/include/mysql++ -I/usr/include/mysql -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Util/UtilConfigAccess.o Util/UtilConfigAccess.cpp

${OBJECTDIR}/Util/UtilDateTime.o: nbproject/Makefile-${CND_CONF}.mk Util/UtilDateTime.cpp 
	${MKDIR} -p ${OBJECTDIR}/Util
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/local/include/ -I/usr/include/ -I/usr/local/include/mysql++ -I/usr/include/mysql -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Util/UtilDateTime.o Util/UtilDateTime.cpp

${OBJECTDIR}/Util/UtilHttpRequestHandler.o: nbproject/Makefile-${CND_CONF}.mk Util/UtilHttpRequestHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/Util
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/local/include/ -I/usr/include/ -I/usr/local/include/mysql++ -I/usr/include/mysql -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Util/UtilHttpRequestHandler.o Util/UtilHttpRequestHandler.cpp

${OBJECTDIR}/Util/UtilLogger.o: nbproject/Makefile-${CND_CONF}.mk Util/UtilLogger.cpp 
	${MKDIR} -p ${OBJECTDIR}/Util
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/local/include/ -I/usr/include/ -I/usr/local/include/mysql++ -I/usr/include/mysql -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Util/UtilLogger.o Util/UtilLogger.cpp

${OBJECTDIR}/Util/UtilMysqlClient.o: nbproject/Makefile-${CND_CONF}.mk Util/UtilMysqlClient.cpp 
	${MKDIR} -p ${OBJECTDIR}/Util
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/local/include/ -I/usr/include/ -I/usr/local/include/mysql++ -I/usr/include/mysql -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Util/UtilMysqlClient.o Util/UtilMysqlClient.cpp

${OBJECTDIR}/main.o: nbproject/Makefile-${CND_CONF}.mk main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -IUtil -I/usr/local/include/ -I/usr/include/ -I/usr/local/include/mysql++ -I/usr/include/mysql -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f1: ${TESTDIR}/DataExtract/DataExtractTest/FutureInstrumentTest.o ${TESTDIR}/Util/RunAllTests.o ${TESTDIR}/Util/UtilTest/UtilConfigAccessTest.o ${TESTDIR}/Util/UtilTest/UtilDateTimeTest.o ${TESTDIR}/Util/UtilTest/UtilHttpRequestHandlerTest.o ${TESTDIR}/Util/UtilTest/UtilLoggerTest.o ${TESTDIR}/Util/UtilTest/UtilMysqlClientTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} -lboost_unit_test_framework 


${TESTDIR}/DataExtract/DataExtractTest/FutureInstrumentTest.o: DataExtract/DataExtractTest/FutureInstrumentTest.cpp 
	${MKDIR} -p ${TESTDIR}/DataExtract/DataExtractTest
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/local/include/ -I/usr/include/ -I/usr/local/include/mysql++ -I/usr/include/mysql -I. -IUtil -IDataExtract -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/DataExtract/DataExtractTest/FutureInstrumentTest.o DataExtract/DataExtractTest/FutureInstrumentTest.cpp


${TESTDIR}/Util/RunAllTests.o: Util/RunAllTests.cpp 
	${MKDIR} -p ${TESTDIR}/Util
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/local/include/ -I/usr/include/ -I/usr/local/include/mysql++ -I/usr/include/mysql -I. -IUtil -IDataExtract -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/Util/RunAllTests.o Util/RunAllTests.cpp


${TESTDIR}/Util/UtilTest/UtilConfigAccessTest.o: Util/UtilTest/UtilConfigAccessTest.cpp 
	${MKDIR} -p ${TESTDIR}/Util/UtilTest
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/local/include/ -I/usr/include/ -I/usr/local/include/mysql++ -I/usr/include/mysql -I. -IUtil -IDataExtract -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/Util/UtilTest/UtilConfigAccessTest.o Util/UtilTest/UtilConfigAccessTest.cpp


${TESTDIR}/Util/UtilTest/UtilDateTimeTest.o: Util/UtilTest/UtilDateTimeTest.cpp 
	${MKDIR} -p ${TESTDIR}/Util/UtilTest
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/local/include/ -I/usr/include/ -I/usr/local/include/mysql++ -I/usr/include/mysql -I. -IUtil -IDataExtract -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/Util/UtilTest/UtilDateTimeTest.o Util/UtilTest/UtilDateTimeTest.cpp


${TESTDIR}/Util/UtilTest/UtilHttpRequestHandlerTest.o: Util/UtilTest/UtilHttpRequestHandlerTest.cpp 
	${MKDIR} -p ${TESTDIR}/Util/UtilTest
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/local/include/ -I/usr/include/ -I/usr/local/include/mysql++ -I/usr/include/mysql -I. -IUtil -IDataExtract -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/Util/UtilTest/UtilHttpRequestHandlerTest.o Util/UtilTest/UtilHttpRequestHandlerTest.cpp


${TESTDIR}/Util/UtilTest/UtilLoggerTest.o: Util/UtilTest/UtilLoggerTest.cpp 
	${MKDIR} -p ${TESTDIR}/Util/UtilTest
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/local/include/ -I/usr/include/ -I/usr/local/include/mysql++ -I/usr/include/mysql -I. -IUtil -IDataExtract -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/Util/UtilTest/UtilLoggerTest.o Util/UtilTest/UtilLoggerTest.cpp


${TESTDIR}/Util/UtilTest/UtilMysqlClientTest.o: Util/UtilTest/UtilMysqlClientTest.cpp 
	${MKDIR} -p ${TESTDIR}/Util/UtilTest
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/local/include/ -I/usr/include/ -I/usr/local/include/mysql++ -I/usr/include/mysql -I. -IUtil -IDataExtract -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/Util/UtilTest/UtilMysqlClientTest.o Util/UtilTest/UtilMysqlClientTest.cpp


${OBJECTDIR}/DataExtract/FutureInstrument_nomain.o: ${OBJECTDIR}/DataExtract/FutureInstrument.o DataExtract/FutureInstrument.cpp 
	${MKDIR} -p ${OBJECTDIR}/DataExtract
	@NMOUTPUT=`${NM} ${OBJECTDIR}/DataExtract/FutureInstrument.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I/usr/local/include/ -I/usr/include/ -I/usr/local/include/mysql++ -I/usr/include/mysql -I. -IUtil -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataExtract/FutureInstrument_nomain.o DataExtract/FutureInstrument.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/DataExtract/FutureInstrument.o ${OBJECTDIR}/DataExtract/FutureInstrument_nomain.o;\
	fi

${OBJECTDIR}/DataExtract/HkexExtractor_nomain.o: ${OBJECTDIR}/DataExtract/HkexExtractor.o DataExtract/HkexExtractor.cpp 
	${MKDIR} -p ${OBJECTDIR}/DataExtract
	@NMOUTPUT=`${NM} ${OBJECTDIR}/DataExtract/HkexExtractor.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I/usr/local/include/ -I/usr/include/ -I/usr/local/include/mysql++ -I/usr/include/mysql -I. -IUtil -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataExtract/HkexExtractor_nomain.o DataExtract/HkexExtractor.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/DataExtract/HkexExtractor.o ${OBJECTDIR}/DataExtract/HkexExtractor_nomain.o;\
	fi

${OBJECTDIR}/DataExtract/Instrument_nomain.o: ${OBJECTDIR}/DataExtract/Instrument.o DataExtract/Instrument.cpp 
	${MKDIR} -p ${OBJECTDIR}/DataExtract
	@NMOUTPUT=`${NM} ${OBJECTDIR}/DataExtract/Instrument.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I/usr/local/include/ -I/usr/include/ -I/usr/local/include/mysql++ -I/usr/include/mysql -I. -IUtil -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataExtract/Instrument_nomain.o DataExtract/Instrument.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/DataExtract/Instrument.o ${OBJECTDIR}/DataExtract/Instrument_nomain.o;\
	fi

${OBJECTDIR}/Util/UtilConfigAccess_nomain.o: ${OBJECTDIR}/Util/UtilConfigAccess.o Util/UtilConfigAccess.cpp 
	${MKDIR} -p ${OBJECTDIR}/Util
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Util/UtilConfigAccess.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I/usr/local/include/ -I/usr/include/ -I/usr/local/include/mysql++ -I/usr/include/mysql -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Util/UtilConfigAccess_nomain.o Util/UtilConfigAccess.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Util/UtilConfigAccess.o ${OBJECTDIR}/Util/UtilConfigAccess_nomain.o;\
	fi

${OBJECTDIR}/Util/UtilDateTime_nomain.o: ${OBJECTDIR}/Util/UtilDateTime.o Util/UtilDateTime.cpp 
	${MKDIR} -p ${OBJECTDIR}/Util
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Util/UtilDateTime.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I/usr/local/include/ -I/usr/include/ -I/usr/local/include/mysql++ -I/usr/include/mysql -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Util/UtilDateTime_nomain.o Util/UtilDateTime.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Util/UtilDateTime.o ${OBJECTDIR}/Util/UtilDateTime_nomain.o;\
	fi

${OBJECTDIR}/Util/UtilHttpRequestHandler_nomain.o: ${OBJECTDIR}/Util/UtilHttpRequestHandler.o Util/UtilHttpRequestHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/Util
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Util/UtilHttpRequestHandler.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I/usr/local/include/ -I/usr/include/ -I/usr/local/include/mysql++ -I/usr/include/mysql -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Util/UtilHttpRequestHandler_nomain.o Util/UtilHttpRequestHandler.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Util/UtilHttpRequestHandler.o ${OBJECTDIR}/Util/UtilHttpRequestHandler_nomain.o;\
	fi

${OBJECTDIR}/Util/UtilLogger_nomain.o: ${OBJECTDIR}/Util/UtilLogger.o Util/UtilLogger.cpp 
	${MKDIR} -p ${OBJECTDIR}/Util
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Util/UtilLogger.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I/usr/local/include/ -I/usr/include/ -I/usr/local/include/mysql++ -I/usr/include/mysql -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Util/UtilLogger_nomain.o Util/UtilLogger.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Util/UtilLogger.o ${OBJECTDIR}/Util/UtilLogger_nomain.o;\
	fi

${OBJECTDIR}/Util/UtilMysqlClient_nomain.o: ${OBJECTDIR}/Util/UtilMysqlClient.o Util/UtilMysqlClient.cpp 
	${MKDIR} -p ${OBJECTDIR}/Util
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Util/UtilMysqlClient.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I/usr/local/include/ -I/usr/include/ -I/usr/local/include/mysql++ -I/usr/include/mysql -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Util/UtilMysqlClient_nomain.o Util/UtilMysqlClient.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Util/UtilMysqlClient.o ${OBJECTDIR}/Util/UtilMysqlClient_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -IUtil -I/usr/local/include/ -I/usr/include/ -I/usr/local/include/mysql++ -I/usr/include/mysql -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_nomain.o main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/HkexMarketExtract

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
