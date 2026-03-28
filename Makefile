SHELL	= /bin/bash

.PHONY	=	all compile upload
PORTA	=	$(shell cat config/porta)
BOARD	=	$(shell cat config/board)
SKETCH	:=	$(basename $(notdir $(shell ls -t */*.ino | head -n 1)))

all:
	@echo "Compilando a sketch:" $(SKETCH)
	@echo "Board:" $(BOARD)
	@echo "Porta:" $(PORTA)

compile:
	@arduino-cli compile --fqbn $(BOARD) $(SKETCH)

upload:
	@arduino-cli upload -p $(PORTA) --fqbn $(BOARD) $(SKETCH)
