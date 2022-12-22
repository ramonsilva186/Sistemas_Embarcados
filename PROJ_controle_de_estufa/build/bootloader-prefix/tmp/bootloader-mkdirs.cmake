# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/allan/esp/esp-idf/components/bootloader/subproject"
  "D:/Documents/Faculdade/Sistemas_Embarcados/PROJ_controle_de_estufa/build/bootloader"
  "D:/Documents/Faculdade/Sistemas_Embarcados/PROJ_controle_de_estufa/build/bootloader-prefix"
  "D:/Documents/Faculdade/Sistemas_Embarcados/PROJ_controle_de_estufa/build/bootloader-prefix/tmp"
  "D:/Documents/Faculdade/Sistemas_Embarcados/PROJ_controle_de_estufa/build/bootloader-prefix/src/bootloader-stamp"
  "D:/Documents/Faculdade/Sistemas_Embarcados/PROJ_controle_de_estufa/build/bootloader-prefix/src"
  "D:/Documents/Faculdade/Sistemas_Embarcados/PROJ_controle_de_estufa/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/Documents/Faculdade/Sistemas_Embarcados/PROJ_controle_de_estufa/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
