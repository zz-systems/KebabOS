cmake_minimum_required(VERSION 2.8.1)
project(plasma-firmware)

include_directories(include)

set_source_files_properties(
        src/kernel/kernel.asm
        src/kernel/vectortable.asm
        PROPERTIES COMPILE_FLAGS "-x assembler-with-cpp")

add_library(stdlib.zedboard STATIC       
                                src/stdlib/file.c
                                src/stdlib/string.c
                                src/stdlib/memory.c)

target_link_libraries(stdlib.zedboard PUBLIC linker_cfg kernel.zedboard)

add_library(stdlib.de1_soc STATIC       
                                src/stdlib/file.c
                                src/stdlib/string.c
                                src/stdlib/memory.c)                               

target_link_libraries(stdlib.de1_soc PUBLIC linker_cfg kernel.de1_soc)

add_library(drivers.zedboard STATIC     
                                src/drivers/uart.c
                                src/drivers/irc.c
                                src/drivers/counter.c
                                src/drivers/timer.c
                                src/drivers/display.c)

target_link_libraries(drivers.zedboard PUBLIC linker_cfg kernel.zedboard)

add_library(drivers.de1_soc STATIC     
                                src/drivers/uart.c
                                src/drivers/irc.c
                                src/drivers/counter.c
                                src/drivers/timer.c)

target_link_libraries(drivers.de1_soc PUBLIC linker_cfg kernel.de1_soc)

set(kernel.sources      src/kernel/vectortable.asm 
                        src/kernel/kernel.asm 
                        src/kernel/io.c
                        src/kernel/device.c
                        src/kernel/kernel.c
                        src/kernel/interrupt.c
                        src/kernel/memory.c
                        src/kernel/init.c)

add_library(kernel.interface INTERFACE)
target_include_directories(kernel.interface INTERFACE include)


add_library(kernel.zedboard STATIC ${kernel.sources})
target_compile_definitions(kernel.zedboard PUBLIC PLATFORM=zedboard)
target_link_libraries(kernel.zedboard PUBLIC 
                                        kernel.interface 
                                        linker_cfg 
                                        drivers.zedboard 
                                        stdlib.zedboard)

add_library(kernel.de1_soc STATIC ${kernel.sources})
target_compile_definitions(kernel.de1_soc PUBLIC PLATFORM=de1_soc)
target_link_libraries(kernel.de1_soc PUBLIC 
                                        kernel.interface
                                        linker_cfg
                                        drivers.de1_soc 
                                        stdlib.de1_soc)


