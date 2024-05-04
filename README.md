<img src="https://github.com/Kuvrot/Jaraan/assets/23508114/e934a4c8-9e21-404b-9a3b-555043bd4470" width=256>

# Jaraan
#### GUI framework for C++. (still in development, PR are welcome!)
*Make C++ applications with a simple modern GUI with the least amount of code.* 

## Demo

![jaraan](https://github.com/Kuvrot/Jaraan/assets/23508114/974544a5-f4b6-4ec9-b8f9-bbc346fd574b)

Made with just this amount of code: 

```c++
#include "Jaraan/Jaraan.h"

void select(int n , Label lb) {

    switch (n) {

        case 1: lb.setText("¡Hola amigo!"); break;
        case 2: lb.setText("Hello friend!"); break;
        case 3: lb.setText("Hallo freund!"); break;
        case 4: lb.setText("Salve amici!"); break;
    }
}

int main()
{   
    Window window(800, 600, "Jaraan");
    Label label(10, 2, "Select a language", 24);
    Button btn1(1, 1, "Spanish", 12, [label]() {select(1 , label); });
    Button btn2(1, 2, "English", 12, [label]() {select(2, label); });
    Button btn3(1, 3, "Deutsch", 12, [label]() {select(3 , label); });
    Button btn4(1, 4, "Latin", 12, [label]() {select(4 , label); });

    window.Update();

    return 0;
}

```
## How to use:
If using git, clone the repo with 
```
git clone https://github.com/Kuvrot/Jaraan.git
```
1. Configure and build your project. Most popular IDEs support CMake projects with very little effort on your part.
    - [Visual Studio](https://docs.microsoft.com/en-us/cpp/build/cmake-projects-in-visual-studio?view=msvc-170) (recommended)
    - [VS Code](https://code.visualstudio.com) via the [CMake extension](https://code.visualstudio.com/docs/cpp/cmake-linux)
    - [CLion](https://www.jetbrains.com/clion/features/cmake-support.html)
    - [Qt Creator](https://doc.qt.io/qtcreator/creator-project-cmake.html)

    Using CMake from the command line is straightforward as well.

    For a single-configuration generator (typically the case on Linux and macOS):
    ```
    cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
    cmake --build build
    ```

    For a multi-configuration generator (typically the case on Windows):
    ```
    cmake -S . -B build
    cmake --build build --config Release
    ```

If using Linux, install SFML's dependencies using your system package manager. On Ubuntu and other Debian-based distributions you can use the following commands:
```
    sudo apt update
    sudo apt install \
        libxrandr-dev \
        libxcursor-dev \
        libudev-dev \
        libfreetype-dev \
        libopenal-dev \
        libflac-dev \
        libvorbis-dev \
        libgl1-mesa-dev \
        libegl1-mesa-dev
```

### Setup the font
- Download a font 
  * Download the [Arial font](https://www.freebestfonts.com/download?fn=257)
- After the cmake build is done, go to your Jaraan repo and then go to `out > build > x64_Debug > bin` and put the arial.ttf file inside the bin folder. 

## Todo list
- Widgets
  * [x] labels
  * [x] buttons
  * [x] text field
  * [ ] text area
  * [ ] dropdown
  * [x] check box
  * [ ] slider
  * [ ] add icons to buttons
- Enhancement
  * [ ] Good layout system
- Multimedia
  * [ ] interactions with audio
  * [ ] video and images support
