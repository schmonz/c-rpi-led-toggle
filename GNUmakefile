SILENT		?= @

DEFAULT_SYSTEM	=  host
THE_TESTS	=  check_led_toggle
THE_LIBRARY	=  led.a
THE_PROGRAM	=  toggler

TARGET_SYSTEM	?= ${DEFAULT_SYSTEM}
ifeq (rpi, ${TARGET_SYSTEM})
MAKE_TARGET	= ${THE_PROGRAM}
EXT_TREES_ROOT	?= ${HOME}/Documents/trees
NETBSDSRCDIR	?= ${EXT_TREES_ROOT}/netbsd-src
CROSS_ROOT	?= ${EXT_TREES_ROOT}/rpi
CROSS_ARCH	?= evbearmv6hf-el
CFLAGS		+= --sysroot=${CROSS_ROOT}/distrib/${CROSS_ARCH}
TOOLDIR		?= ${CROSS_ROOT}/tools
TARGET_PREFIX	= armv6--netbsdelf-eabihf-
else
MAKE_TARGET	= ${THE_PROGRAM} check
TOOLDIR		?= /usr
TARGET_PREFIX	?=
endif

CC		= ${TOOLDIR}/bin/${TARGET_PREFIX}gcc
LD		= ${TOOLDIR}/bin/${TARGET_PREFIX}ld
AR		= ${TOOLDIR}/bin/${TARGET_PREFIX}ar
RANLIB		= ${TOOLDIR}/bin/${TARGET_PREFIX}ranlib

CFLAGS		+= -g -O0 -Wall -Werror -Wextra -std=c99
TEST_CFLAGS	:= $(shell pkg-config --cflags check)
TEST_LIBS	:= $(shell pkg-config --libs check)
TEST_LIBS	+= -lm

LED_H		= led.h
LED_C		= led.c
LED_H		?= ${TARGET_SYSTEM}_led.h
LED_C		?= ${TARGET_SYSTEM}_led.c

all: ${CC}
	${SILENT}${MAKE} ${MAKE_TARGET}

${NETBSDSRCDIR}:
	${SILENT}mkdir -p ${NETBSDSRCDIR} && cd ${NETBSDSRCDIR} && git clone https://github.com/jsonn/src.git .

${CC}: ${NETBSDSRCDIR}
	${SILENT}cd ${NETBSDSRCDIR} && git checkout netbsd_7_0 && env PATH="/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/opt/X11/bin" MAKECONF="/dev/null" ./build.sh -m ${CROSS_ARCH} -u -U -T ${TOOLDIR} -R ${CROSS_ROOT}/release -O ${CROSS_ROOT}/obj/${CROSS_ARCH} -D ${CROSS_ROOT}/distrib/${CROSS_ARCH} distribution

check: ${THE_TESTS}
	${SILENT}./${THE_TESTS}

clean:
	${SILENT}rm -f *.o ${THE_TESTS} ${THE_LIBRARY} ${THE_PROGRAM}
	${SILENT}rm -rf *.dSYM *.gcda *.gcno *.gcov

.PHONY: all check clean

${THE_TESTS}: ${THE_LIBRARY} check_led_toggle.c check_led_toggle_acceptance.c check_led_toggle_unit.c
	${SILENT}${CC} ${CFLAGS} ${TEST_CFLAGS} -o ${THE_TESTS} check_led_toggle_acceptance.c check_led_toggle_unit.c check_led_toggle.c ${TEST_LIBS} ${THE_LIBRARY}

${THE_LIBRARY}: ${LED_H} ${LED_C}
	${SILENT}${CC} ${CFLAGS} -c ${LED_C} -o led.o
	${SILENT}${AR} rc ${THE_LIBRARY} led.o
	${SILENT}${RANLIB} ${THE_LIBRARY}

${THE_PROGRAM}: ${THE_LIBRARY} ${LED_H} toggler.c
	${SILENT}${CC} ${CFLAGS} -o ${THE_PROGRAM} toggler.c ${THE_LIBRARY}
