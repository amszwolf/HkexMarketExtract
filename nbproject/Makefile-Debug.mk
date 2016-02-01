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
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Util/UtilDateTime.o \
	${OBJECTDIR}/main.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/usr/local/lib -lboost_date_time

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/hkexmarketextract

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/hkexmarketextract: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/hkexmarketextract ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Util/UtilDateTime.o: nbproject/Makefile-${CND_CONF}.mk Util/UtilDateTime.cpp 
	${MKDIR} -p ${OBJECTDIR}/Util
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/local/include/ -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Util/UtilDateTime.o Util/UtilDateTime.cpp

${OBJECTDIR}/main.o: nbproject/Makefile-${CND_CONF}.mk main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -IUtil -I/usr/local/include/ -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f1: ${TESTDIR}/Util/UtilDateTimeTest/UtilDateTimeTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} -lboost_unit_test_framework 


${TESTDIR}/Util/UtilDateTimeTest/UtilDateTimeTest.o: Util/UtilDateTimeTest/UtilDateTimeTest.cpp 
	${MKDIR} -p ${TESTDIR}/Util/UtilDateTimeTest
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/local/include/ -IUtil -MMD -MP -MF "$@.d" -o ${TESTDIR}/Util/UtilDateTimeTest/UtilDateTimeTest.o Util/UtilDateTimeTest/UtilDateTimeTest.cpp


${OBJECTDIR}/Util/UtilDateTime_nomain.o: ${OBJECTDIR}/Util/UtilDateTime.o Util/UtilDateTime.cpp 
	${MKDIR} -p ${OBJECTDIR}/Util
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Util/UtilDateTime.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I/usr/local/include/ -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Util/UtilDateTime_nomain.o Util/UtilDateTime.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Util/UtilDateTime.o ${OBJECTDIR}/Util/UtilDateTime_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -IUtil -I/usr/local/include/ -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_nomain.o main.cpp;\
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
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/hkexmarketextract

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
