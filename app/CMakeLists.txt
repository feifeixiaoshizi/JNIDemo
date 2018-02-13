# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.
#添加so库，第一个参数表明生成的so库的名字，第二个参数表明生成的so库的类型，第三个参数表示源文件，可以是多个源文件。
add_library( # Sets the name of the library.so库的名字
             native-lib

             # Sets the library as a shared library.so库的类型为共享
             SHARED

             # Provides a relative path to your source file(s).提供源文件们来生成so库
             src/main/cpp/native-lib.cpp )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.
#寻找系统中已经存在的so库，比如系统存在的log类库，
find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

#设置要生成的so库所依赖的其他的so库，配置so库间的依赖关系。
#依赖上面查询的log日志类库，这样在你的源文件中就可以调用系统的日志类库打印日志了。
target_link_libraries( # Specifies the target library.
                       native-lib

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )