include Makefile.inc

SUBDIRS = blink_led_pwm \
	  blink_led_sw \
	  blink_led_timerA \
	  blink_led_wdt \
	  led_pwm

all:
	for d in $(SUBDIRS); do $(MAKE) -C $$d; done

clean:
	for d in $(SUBDIRS); do $(MAKE) clean -C $$d; done
