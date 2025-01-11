# igl-nanovg

igl-nanovg is a project that combines [nanovg](https://github.com/memononen/nanovg) with [igl](https://github.com/facebook/igl), enabling nanovg to run on opengl, metal, and vulkan.

Support Platforms : MacOS, Windows, Linux, iOS, Android.

The project originally wanted to submit a PR to merge into [igl](https://github.com/facebook/igl) , but the Facebook/igl team thought that it conflicted with their principle of minimizing dependence on third-party projects, so i created this repository separately.

Original PR: https://github.com/facebook/igl/pull/213

## Build Demo

1，Download the code (including submodule:igl)：
```
git clone --recursive https://github.com/vinsentli/igl-nanovg.git
```

2，Execute script in the root directory：

```
prepare.sh
```

3，Enter the igl directory and execute the script and CMake commands according to the igl requirements to open the igl project

1）Execute the script to download the third-party code that igl depends on:

```
python3 deploy_deps.py

```

2）Execute the CMake command to generate the project：

* Windows

```
cd build
cmake .. -G "Visual Studio 17 2022"
```

* Linux

```
sudo apt-get install clang xorg-dev libxinerama-dev libxcursor-dev libgles2-mesa-dev libegl1-mesa-dev libglfw3-dev libglew-dev libstdc++-12-dev
cd build
cmake .. -G "Unix Makefiles"
```

* macOS

```
cd build
cmake .. -G "Xcode" -DIGL_WITH_VULKAN=OFF
```

* iOS

```
cd build
cmake .. -G Xcode -DCMAKE_TOOLCHAIN_FILE=../third-party/deps/src/ios-cmake/ios.toolchain.cmake -DDEPLOYMENT_TARGET=13.0 -DPLATFORM=OS64
```

* Android

The Gradle project is located within the [build/android](./build/android/) folder.

4，Compile and run the project：

1）For Linux, MacOS, Windows, or iOS, select the NanovgSession project。

2）Select nanovg project for Android。

	modify SampleLib.java:
	System.loadLibrary("NanovgSession");


## Screenshot

Metal :

https://github.com/user-attachments/assets/4428c775-8002-407b-a454-1f3e0913d46b

OpenGL:

https://github.com/user-attachments/assets/92dce2a9-caed-487d-9609-44f6a3bb5d9c

Vulkan  : 

https://github.com/user-attachments/assets/91f051bd-ff14-4a3d-979e-88b68f8e5826
