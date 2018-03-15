#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "explorer" for configuration ""
set_property(TARGET explorer APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(explorer PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/bin/explorer"
  )

list(APPEND _IMPORT_CHECK_TARGETS explorer )
list(APPEND _IMPORT_CHECK_FILES_FOR_explorer "${_IMPORT_PREFIX}/bin/explorer" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
