# iglNanoVG

iglNanoVG是将[nanovg](https://github.com/memononen/nanovg)与[igl](https://github.com/facebook/igl)相结合而实现的项目，使NanoVG能够运行在Opengl, Metal, Vulkan之上。

Support Platforms : MacOS, Windows, Linux, iOS, Android.

项目最初是想提交PR合入[igl](https://github.com/facebook/igl)，但是facebook/igl团队认为与他们想最小化减少对第三方项目依赖的原则相冲突，所以单独建立此仓库。

原始PR: https://github.com/facebook/igl/pull/213

## Demo搭建流程

1，在根目录下执行 

```
prepare.sh
```

2，进入igl目录执行，按照igl要求执行脚本和CMake命令，打开igl工程。

1）执行脚本，下载依赖的第三方代码:

```
python3 deploy_deps.py

```

2）执行CMake命令，生成工程：

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

3，编译运行工程：

1）Linux, Macos, Windows, iOS选择NanovgSession工程。

2）Android选择nanovg工程。

	修改SampleLib.java:
	System.loadLibrary("NanovgSession");


## Screenshot

Metal :

https://github.com/user-attachments/assets/4428c775-8002-407b-a454-1f3e0913d46b

OpenGL:

https://github.com/user-attachments/assets/92dce2a9-caed-487d-9609-44f6a3bb5d9c

Vulkan  : 

https://github.com/user-attachments/assets/91f051bd-ff14-4a3d-979e-88b68f8e5826
