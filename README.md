# Game Of Life

### [Conway's game of life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) made in C++ using SFML

> This is my first C++ project.

<!-- ## How to run:

(I will provide compiled binaries from release 1) -->

---

## How to compile:

### On linux:

1. Get a c++ compiler(on Ubuntu/Ubuntu based distros : `sudo apt install build-essential`)
2. Get SFML binaries(or you may build from it's source) goto https://www.sfml-dev.org/download.php and download the appropriate file.
3. Extract `SFML-2.5.1-linux-gcc-64-bit.tar.gz`
4. Copy the contents of `SFML-2.5.1/lib/` to `/usr/lib`
5. Copy the extracted folder `SFML-2.5.1` to this repo.
1. Run the script `build-and-run.sh` by using this command.
    ```bash
    ./build-and-run.sh
    ```
    * This will create a executable called `gameoflife`.
    * You can run this any time but just double-clicking it.

### On Windows:

https://www.sfml-dev.org/tutorials/2.5/start-vc.php

> (They have explained most of the steps very well. I would highly encourage you to read it.)

### On macOS:

https://www.sfml-dev.org/tutorials/2.5/start-osx.php

> (They have explained most of the steps very well. I would highly encourage you to read it.)
