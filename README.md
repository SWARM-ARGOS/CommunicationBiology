# SWARM-ARGOS

Simulated ant-like foraging robots used in the following paper.


Regulatory mechanism predates the evolution of self-organizing capacity in simulated ant-like robots. [bioRxiv](https://doi.org/10.1101/372391)


## Description
### Main files
* Harsh_Mistress20.exe: Main file of the foraging simulation. In the simulation, ant-like robots start to move from their nest and search foods. Once they find the food, they bring back the food to their nest with/without pheromone. Parameters used in the file are given by param.csv. Genome information for swarm is given by Swarm_i.csv where i specifies the generation number. This main file outputs the result data in each generation specified by result_i.csv.
* Initilization.py: Generate an initial genome (generation 0) file (Swarm_0.csv) to be used as the initial input in Harsh_Mistress20.exe.
* Evolution.py: This file reads the result data in each generation (result_i.csv) and evaluates the performance of the swarms (N swarms in total). Each swarm is given its relative fitness. The set of fitness is used to generate offspring (swarm) in the next generation. The fitter swarm produces more offspring. We used the roulette-wheel selection for the selection method.

### Script files
* run.sh: ...
* analysis.sh: ...
* fitness.sh: ...

```bash
$ git clone https://github.com/google/benchmark.git
# Benchmark requires Google Test as a dependency. Add the source tree as a subdirectory.
$ git clone https://github.com/google/googletest.git benchmark/googletest
$ mkdir build && cd build
$ cmake -G <generator> [options] ../benchmark
# Assuming a makefile generator was used
$ make
```

Note that Google Benchmark requires Google Test to build and run the tests. This
dependency can be provided two ways:

* Checkout the Google Test sources into `benchmark/googletest` as above.
* Otherwise, if `-DBENCHMARK_DOWNLOAD_DEPENDENCIES=ON` is specified during
  configuration, the library will automatically download and build any required
  dependencies.

If you do not wish to build and run the tests, add `-DBENCHMARK_ENABLE_GTEST_TESTS=OFF`
to `CMAKE_ARGS`.


## Installation Guide

For Ubuntu and Debian Based System

First make sure you have git and cmake installed (If not please install them)

```
sudo apt-get install git cmake
```

Now, let's clone the repository and build it

```
