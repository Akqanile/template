ANDROID_NDK_ROOT := C:/Android-NDK/r16b

ifndef ANDROID_NDK_ROOT
$(error ANDROID_NDK_ROOT is not set)
endif

.PHONY: build

build:
	cmake -B build -DCMAKE_TOOLCHAIN_FILE=$(ANDROID_NDK_ROOT)/build/cmake/android.toolchain.cmake -G "Ninja" -DCMAKE_BUILD_TYPE:STRING=Release
	cmake --build build --config Release
clean:
	rmdir build /s /q
