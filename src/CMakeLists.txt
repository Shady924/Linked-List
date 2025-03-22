# CMakeLists.txt in src/

# Find all .cpp files in the current directory
file(GLOB SRC_FILES *.cpp)

# Link include directory 
target_include_directories(${PROJECT_NAME} PUBLIC include )