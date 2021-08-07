Game of Life
============

This is an implementation of Game of Life, which produces of the cellular
automaton in the form of a sequence of PPM files, which can be then converted
into a GIF or MP4 file. It uses no external libraries, which means reproducing
it might be a good teaching project.

Build instructions
------------------

Requires `cmake >=3.10` and a C++ compiler with C++17 support.

Run the following instructions in the shell to configure the project:

```
mkdir -p build/Release
cd build/Release
cmake -DCMAKE_BUILD_TYPE=Release ../..
cd -
```

After that you can build the code with:

```
cmake --build build/Release
```

You can replace `Release` with other build types.

Running instructions
--------------------

At this point the executable will produce a hardcoded animation with a glider.
The files will be generated into a `glider` directory, which needs to be
created first:

```
mkdir glider
```

After that you can run the program with:

```
build/Release/src/game_of_life
```

In order to convert the raw frames to a GIF file, you can use Imagemagick:

```
convert glider/* glider.gif
```