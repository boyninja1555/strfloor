<div align="center">
    <h1>strfloor</h1>
</div>

C implementation of advanced strings.  
No fluff in this README, just what you need.

## Installation

strfloor is a dead simple library. To include it, I recommend git submodules. But you could also use CMake's FetchContent because this is a CMake project.

**With Git Submodules**  
Run these commands in a terminal with access to git:

```bash
git submodule add https://github.com/boyninja1555/strfloor.git strfloor
git submodule update --init --recursive
```

**With FetchContent**  
Copy this into your `CMakeLists.txt`

```cmake
include(FetchContent)
FetchContent_Declare(
        strfloor
        GIT_REPOSITORY https://github.com/boyninja1555/strfloor.git
        GIT_TAG main
)

FetchContent_MakeAvailable(strfloor)
```

## Usage

You can explore the [strfloor.h](strfloor.h) for actual usage within code, but here I simply explain how to include the header file:

```c
#include "strfloor.h"
```

This is assuming your build config uses FetchContent (handles linking automatically) or git submodules. Always include the `strfloor` directory in your build config if using git submodules!
