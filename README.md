# SWARM-ARGOS

Set of programs for simulated ant-like foraging robots used in the following paper.


Regulatory mechanism predates the evolution of self-organizing capacity in simulated ant-like robots. [bioRxiv](https://doi.org/10.1101/372391)

## Main files
* Harsh_Mistress20.exe: Main file of the foraging simulation. In the simulation, ant-like robots start to move from their nest and search foods. Once they find the food, they bring back the food to their nest with/without pheromone. Parameters used in the file are given by param.csv. Genome information for swarm is given by Swarm_i.csv where i specifies the generation number. This main file outputs the result data in each generation specified by result_i.csv.
* Initilization.py: Generate an initial genome (generation 0) file (Swarm_0.csv) to be used as the initial input in Harsh_Mistress20.exe.
* Evolution.py: This file reads the result data in each generation (result_i.csv) and evaluates the performance of the swarms (N swarms in total). Each swarm is given its relative fitness. The set of fitness is used to generate offspring (swarm) in the next generation. The fitter swarm produces more offspring. We used the roulette-wheel selection for the selection method.

## System requirements
### Required software
* OS: Windows 10 & Cygwin 2.9
* Harsh_Mistress20.exe: Microsoft Visual Studio Community 2017 (Version 15.2). For the visualization of simulations, OpenGL ([Freeglut 3.0.0](http://freeglut.sourceforge.net/index.php#download)) needs to be installed
* Initilization.py & Evolution.py: Python 2.7.x is used. NumPy is needed.
* run.sh, analysis.sh & fitness.sh: bash.

### Versions the software has been tested on
* OS: Windows 10 Pro ver.1803
* CPU: Intel Core i7-660U CPU 2.60GHz

## Installation guide
* Instructions: Download Harsh_Mistress20.exe, param.csv, Initilization.py, Evolution.py, and run.sh from Run directory.
* Typical install time on a normal desktop computer: 30 min

## Demo
### Instrucions to run on data
* To run the simulation, simply run run.sh in Cygwin (run.sh should be executable beforehand).
  ```bash
  $ ./run.sh
  ```

  It automatically runs the main files specified above in the correct order as follows. From now, we see the content of run.sh. First, by calling Initialization.py, it generates the initial input file for Harsh_Mistress20.exe.

  ```bash
  $ python Initialization.py
  ```

  Then, it runs the main file and generates a next input file from the result.

  ```bash
  $ ./Harsh_Mistress20.exe $i
  $ python Evolution.py SwarmInput_$i.csv
  ```

* result_0.csv is the example of the expected output at generation 0.
* Expected run time for demo on a normal desktop computer: 3 hours per generation


## Other information
* For the analysis, use the files in Analysis directory.
  * analysis.sh & analysis.R: Those files generate the average values and their standard deviation of genes (average.csv) for the analysis. R-3.x.x is needed.
  * fitness.sh & fitness.R: Those files generate the average and maximum values of their performance (fitness.csv) for the analysis. R-3.x.x is needed.
