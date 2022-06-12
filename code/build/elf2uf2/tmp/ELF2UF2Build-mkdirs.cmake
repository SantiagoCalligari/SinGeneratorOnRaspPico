# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/santiago/Politecnico2022/pico-sdk/tools/elf2uf2"
  "/home/santiago/Politecnico2022/Coba/SinGeneratorOnRaspPico/code/build/elf2uf2"
  "/home/santiago/Politecnico2022/Coba/SinGeneratorOnRaspPico/code/build/elf2uf2"
  "/home/santiago/Politecnico2022/Coba/SinGeneratorOnRaspPico/code/build/elf2uf2/tmp"
  "/home/santiago/Politecnico2022/Coba/SinGeneratorOnRaspPico/code/build/elf2uf2/src/ELF2UF2Build-stamp"
  "/home/santiago/Politecnico2022/Coba/SinGeneratorOnRaspPico/code/build/elf2uf2/src"
  "/home/santiago/Politecnico2022/Coba/SinGeneratorOnRaspPico/code/build/elf2uf2/src/ELF2UF2Build-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/santiago/Politecnico2022/Coba/SinGeneratorOnRaspPico/code/build/elf2uf2/src/ELF2UF2Build-stamp/${subDir}")
endforeach()
