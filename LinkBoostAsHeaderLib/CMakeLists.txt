#[==================================================[
LinkBoostAsHeaderLib (executable program)
#]==================================================]
add_executable(targetExe) 

target_include_directories(targetExe
    PRIVATE
        hdr
)

target_sources(targetExe
    PRIVATE
        src/MainLinkBoostAsHeaderLib.cpp
        hdr/LinkBoostAsHeaderLib.hpp
        src/LinkBoostAsHeaderLib.cpp
)

set_target_properties(targetExe
    PROPERTIES
        OUTPUT_NAME                         LinkBoostAsHeaderLib
        DEBUG_POSTFIX                       "_d"
        RUNTIME_OUTPUT_DIRECTORY            ${CMAKE_BINARY_DIR}/buildOut/LinkBoostAsHeaderLib/bin/$<CONFIG>
        PDB_OUTPUT_DIRECTORY                ${CMAKE_BINARY_DIR}/buildOut/LinkBoostAsHeaderLib/pdb/$<CONFIG>
        RUNTIME_OUTPUT_DIRECTORY_<Config>   ${RUNTIME_OUTPUT_DIRECTORY}
        PDB_OUTPUT_DIRECTORY_<Config>       ${PDB_OUTPUT_DIRECTORY}
)

target_compile_features(targetExe
    PRIVATE
        c_std_17
        cxx_std_20
)

if(MSVC)

    target_compile_options(targetExe 
        PRIVATE
            /EHsc
            /W2
            # /Wall
    )

else()

    target_compile_options(targetExe 
        PRIVATE
            -Wall
            # -Wextra
            # -Wpedantic
    )

endif()
