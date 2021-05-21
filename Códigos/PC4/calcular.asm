;-------------------------------------------------------------------------------
            .cdecls C,LIST,"msp430.h"       ; Include device header file
;---------------------------------------------------------------------

			.global calcular               ; Declare symbol to be exported
      		.sect ".text"
calcular
 			add.w  #2, R13
			rra.w  R13
			rrc.w  R12
			ret
