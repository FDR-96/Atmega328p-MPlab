#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Atmega328p-8x8Led.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Atmega328p-8x8Led.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../../../../../Desktop/src/main.c ../../../../../Desktop/src/ledmatrix7219d88/ledmatrix7219d88.c ../../../../../Desktop/src/max7219/max7219.c Fuente.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/434197822/main.o ${OBJECTDIR}/_ext/957789726/ledmatrix7219d88.o ${OBJECTDIR}/_ext/95806630/max7219.o ${OBJECTDIR}/Fuente.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/434197822/main.o.d ${OBJECTDIR}/_ext/957789726/ledmatrix7219d88.o.d ${OBJECTDIR}/_ext/95806630/max7219.o.d ${OBJECTDIR}/Fuente.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/434197822/main.o ${OBJECTDIR}/_ext/957789726/ledmatrix7219d88.o ${OBJECTDIR}/_ext/95806630/max7219.o ${OBJECTDIR}/Fuente.o

# Source Files
SOURCEFILES=../../../../../Desktop/src/main.c ../../../../../Desktop/src/ledmatrix7219d88/ledmatrix7219d88.c ../../../../../Desktop/src/max7219/max7219.c Fuente.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Atmega328p-8x8Led.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=ATmega328P
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/434197822/main.o: ../../../../../Desktop/src/main.c  .generated_files/6e62f2c4c3291bbe8ad7c2dd9f64e3764a83cd35.flag .generated_files/5956b3afcf9cb34aa02383370edf875e44e34c9f.flag
	@${MKDIR} "${OBJECTDIR}/_ext/434197822" 
	@${RM} ${OBJECTDIR}/_ext/434197822/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/434197822/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/434197822/main.o.d" -MT "${OBJECTDIR}/_ext/434197822/main.o.d" -MT ${OBJECTDIR}/_ext/434197822/main.o -o ${OBJECTDIR}/_ext/434197822/main.o ../../../../../Desktop/src/main.c 
	
${OBJECTDIR}/_ext/957789726/ledmatrix7219d88.o: ../../../../../Desktop/src/ledmatrix7219d88/ledmatrix7219d88.c  .generated_files/82849ed71a1aa436f107178258afa2a6bb16cefd.flag .generated_files/5956b3afcf9cb34aa02383370edf875e44e34c9f.flag
	@${MKDIR} "${OBJECTDIR}/_ext/957789726" 
	@${RM} ${OBJECTDIR}/_ext/957789726/ledmatrix7219d88.o.d 
	@${RM} ${OBJECTDIR}/_ext/957789726/ledmatrix7219d88.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/957789726/ledmatrix7219d88.o.d" -MT "${OBJECTDIR}/_ext/957789726/ledmatrix7219d88.o.d" -MT ${OBJECTDIR}/_ext/957789726/ledmatrix7219d88.o -o ${OBJECTDIR}/_ext/957789726/ledmatrix7219d88.o ../../../../../Desktop/src/ledmatrix7219d88/ledmatrix7219d88.c 
	
${OBJECTDIR}/_ext/95806630/max7219.o: ../../../../../Desktop/src/max7219/max7219.c  .generated_files/6addb0f56cf5ce0280eedde3ceadecff60f7f5f6.flag .generated_files/5956b3afcf9cb34aa02383370edf875e44e34c9f.flag
	@${MKDIR} "${OBJECTDIR}/_ext/95806630" 
	@${RM} ${OBJECTDIR}/_ext/95806630/max7219.o.d 
	@${RM} ${OBJECTDIR}/_ext/95806630/max7219.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/95806630/max7219.o.d" -MT "${OBJECTDIR}/_ext/95806630/max7219.o.d" -MT ${OBJECTDIR}/_ext/95806630/max7219.o -o ${OBJECTDIR}/_ext/95806630/max7219.o ../../../../../Desktop/src/max7219/max7219.c 
	
${OBJECTDIR}/Fuente.o: Fuente.c  .generated_files/ecdcfe63cd6cc3423673db742cfaf9aaf345bf7b.flag .generated_files/5956b3afcf9cb34aa02383370edf875e44e34c9f.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Fuente.o.d 
	@${RM} ${OBJECTDIR}/Fuente.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/Fuente.o.d" -MT "${OBJECTDIR}/Fuente.o.d" -MT ${OBJECTDIR}/Fuente.o -o ${OBJECTDIR}/Fuente.o Fuente.c 
	
else
${OBJECTDIR}/_ext/434197822/main.o: ../../../../../Desktop/src/main.c  .generated_files/773544df77ef0eb707ec2f48484e18d6ae0055e7.flag .generated_files/5956b3afcf9cb34aa02383370edf875e44e34c9f.flag
	@${MKDIR} "${OBJECTDIR}/_ext/434197822" 
	@${RM} ${OBJECTDIR}/_ext/434197822/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/434197822/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/434197822/main.o.d" -MT "${OBJECTDIR}/_ext/434197822/main.o.d" -MT ${OBJECTDIR}/_ext/434197822/main.o -o ${OBJECTDIR}/_ext/434197822/main.o ../../../../../Desktop/src/main.c 
	
${OBJECTDIR}/_ext/957789726/ledmatrix7219d88.o: ../../../../../Desktop/src/ledmatrix7219d88/ledmatrix7219d88.c  .generated_files/253e25358b18f68d4317db20c27254f915ac27cf.flag .generated_files/5956b3afcf9cb34aa02383370edf875e44e34c9f.flag
	@${MKDIR} "${OBJECTDIR}/_ext/957789726" 
	@${RM} ${OBJECTDIR}/_ext/957789726/ledmatrix7219d88.o.d 
	@${RM} ${OBJECTDIR}/_ext/957789726/ledmatrix7219d88.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/957789726/ledmatrix7219d88.o.d" -MT "${OBJECTDIR}/_ext/957789726/ledmatrix7219d88.o.d" -MT ${OBJECTDIR}/_ext/957789726/ledmatrix7219d88.o -o ${OBJECTDIR}/_ext/957789726/ledmatrix7219d88.o ../../../../../Desktop/src/ledmatrix7219d88/ledmatrix7219d88.c 
	
${OBJECTDIR}/_ext/95806630/max7219.o: ../../../../../Desktop/src/max7219/max7219.c  .generated_files/ece1f83c1d1e2fac98eaa4a370a65128bec2c580.flag .generated_files/5956b3afcf9cb34aa02383370edf875e44e34c9f.flag
	@${MKDIR} "${OBJECTDIR}/_ext/95806630" 
	@${RM} ${OBJECTDIR}/_ext/95806630/max7219.o.d 
	@${RM} ${OBJECTDIR}/_ext/95806630/max7219.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/95806630/max7219.o.d" -MT "${OBJECTDIR}/_ext/95806630/max7219.o.d" -MT ${OBJECTDIR}/_ext/95806630/max7219.o -o ${OBJECTDIR}/_ext/95806630/max7219.o ../../../../../Desktop/src/max7219/max7219.c 
	
${OBJECTDIR}/Fuente.o: Fuente.c  .generated_files/ada2a949d543ebd09322692ed787b4beabf403d8.flag .generated_files/5956b3afcf9cb34aa02383370edf875e44e34c9f.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Fuente.o.d 
	@${RM} ${OBJECTDIR}/Fuente.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/Fuente.o.d" -MT "${OBJECTDIR}/Fuente.o.d" -MT ${OBJECTDIR}/Fuente.o -o ${OBJECTDIR}/Fuente.o Fuente.c 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Atmega328p-8x8Led.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/Atmega328p-8x8Led.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"   -gdwarf-2 -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -Wall -gdwarf-3     $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/Atmega328p-8x8Led.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  -o dist/${CND_CONF}/${IMAGE_TYPE}/Atmega328p-8x8Led.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -Wl,--start-group  -Wl,-lm -Wl,--end-group  -Wl,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/Atmega328p-8x8Led.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Atmega328p-8x8Led.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/Atmega328p-8x8Led.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -Wall -gdwarf-3     $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/Atmega328p-8x8Led.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  -o dist/${CND_CONF}/${IMAGE_TYPE}/Atmega328p-8x8Led.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	${MP_CC_DIR}\\avr-objcopy -O ihex "dist/${CND_CONF}/${IMAGE_TYPE}/Atmega328p-8x8Led.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "dist/${CND_CONF}/${IMAGE_TYPE}/Atmega328p-8x8Led.X.${IMAGE_TYPE}.hex"
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
