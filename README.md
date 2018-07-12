Null Renderer Plugin
-----

[![Build Status](https://travis-ci.org/icebreakersentertainment/null_renderer_plugin.svg?branch=master)](https://travis-ci.org/icebreakersentertainment/null_renderer_plugin)
[![Build status](https://ci.appveyor.com/api/projects/status/2tqewfhy60mxv429/branch/master?svg=true)](https://ci.appveyor.com/project/icebreakersentertainment/ice-engine/branch/master)

**Note**: This project is incredibly young, and isn't in any kind of production ready state. 

To clone:

    git clone --recursive https://github.com/icebreakersentertainment/null_renderer_plugin.git

Updating submodules:

    git submodule update --recursive --remote

Get/build prerequisites:

    cd ice_engine/ice_engine
    python setup.py

To build on Linux:

    mkdir build
    cd build
    cmake -DCMAKE_BUILD_TYPE=Release ..
    make

To build on Windows:

    mkdir build
    cd build
    
    cmake -DCMAKE_BUILD_TYPE=Release ..
    msbuild /p:Configuration=Release null_renderer_plugin.sln
