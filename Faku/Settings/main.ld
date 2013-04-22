/****************************************************************************

      Project     easy1
      Autor:      Alfred Lohmann
      Company:    HAW-Hamburg
      Filename:   easy1.ld
      Date:       2008-07-22
      Auto generated Code with
      Start ARM


***************************************************************************/
SEARCH_DIR( "$(ToolDir)\..\arm-hitex-elf\lib\interwork" )

/* Path setting depends on the gnu compiler version */ 
/* Adjust the path here to the used version as necessary */
SEARCH_DIR("$(ToolDir)\..\lib\gcc\arm-hitex-elf\4.1.1\interwork" )

/*******************************************
   Define Files
*******************************************/

INPUT 	(
/* HiTOP will automatically put in here all object files to be linked. */
/* Leave this unchanged!                                               */
$(LinkObjects)
		)
	
/* HiTOP will automatically put in here the target file produced by the linker. */
/* Leave this unchanged!                                                        */
OUTPUT ($(TargetDir)$(Target))

	

/*******************************************
   Memory Definitions
*******************************************/

MEMORY
{

  IntCode (rx) : ORIGIN = 0x00000000, LENGTH = 512k
        IntDataRAM (rw) : ORIGIN = 0x40000000, LENGTH = 64k

}

/* this address is used in startup for initilizing stack */
/* stack is at the end of data	range					  */
 	
PROVIDE(_top_stack_ = 0x40010000);

/* This is the end of physical memory to be used by malloc() */
PROVIDE(_end_of_heap_ = 0x40010000);


/*******************************************
   Section Definitions
*******************************************/

SECTIONS
{
/*******************************************/

.text :
    {

            __code_start__ = .;

        	$(TargetDir)startup.o (.text)         /* Startup code */
            *.o       (.text)

            . = ALIGN(4);
            __code_end__ = .;

            	*(.gnu.linkonce.t.*)
	*(.glue_7)
	*(.glue_7t)
	*(.gcc_except_table)
	*(.gnu.linkonce.r.*)

  } >IntCode =0

  . = ALIGN(4);
  /* .rodata section which is used for read-only data (constants) */

  .rodata . :
  {
        *(.rodata)
  } >IntCode

  . = ALIGN(4);
  
  /*******************************************/
/* CPP is disabled                         */
/*******************************************/

  
  _etext = . ;
  PROVIDE (etext = .);


    /*******************************************/
  .data : AT (_etext)
  {
    /* used for initialized data */
    __data_start__ = . ;
    PROVIDE (__data_start__ = .) ;
    *(.data)
   	*(.data.*)    
	  *(.gnu.linkonce.d*)
 
    
    SORT(CONSTRUCTORS)
    __data_end__ = . ;
    PROVIDE (__data_end__ = .) ;
  } >IntDataRAM
  . = ALIGN(4);

  _edata = . ;
   PROVIDE (edata = .);


    /*******************************************/
  .bss :
  {
    /* used for uninitialized data */

    __bss_start = . ;
    __bss_start__ = . ;
    *(.bss)
    *(.gnu.linkonce.b*)
    . = ALIGN(4);
    __bss_end__ = . ;

  } >IntDataRAM

    /*******************************************/
  .bss2 :
  {
    /* used for uninitialized data */

    __bss2_start = . ;
    __bss2_start__ = . ;
    *(COMMON)
    . = ALIGN(4);
    __bss2_end__ = . ;

  } >IntDataRAM
    
  /*******************************************/
  _end = .;
  PROVIDE (end = .);
/*******************************************/


/*******************************************/
  .comment       0 : { *(.comment) }
  /* DWARF debug sections.
     Symbols in the DWARF debugging sections are relative to the beginning
     of the section so we begin them at 0.  */
  /* DWARF 1 */
  .debug          0 : { *(.debug) }
  .line           0 : { *(.line) }
  /* GNU DWARF 1 extensions */
  .debug_srcinfo  0 : { *(.debug_srcinfo) }
  .debug_sfnames  0 : { *(.debug_sfnames) }
  /* DWARF 1.1 and DWARF 2 */
  .debug_aranges  0 : { *(.debug_aranges) }
  .debug_pubnames 0 : { *(.debug_pubnames) }
  /* DWARF 2 */
  .debug_info     0 : { *(.debug_info .gnu.linkonce.wi.*) }
  .debug_abbrev   0 : { *(.debug_abbrev) }
  .debug_line     0 : { *(.debug_line) }
  .debug_frame    0 : { *(.debug_frame) }
  .debug_str      0 : { *(.debug_str) }
  .debug_loc      0 : { *(.debug_loc) }
  .debug_macinfo  0 : { *(.debug_macinfo) }
}

