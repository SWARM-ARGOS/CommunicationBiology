import numpy as np
import random as rd
import csv

# # of swarms
N=200
swarm=range(N)
initialValue=0.0

f = open('SwarmInput_0.csv', 'wb')

csvWriter=csv.writer(f)

# Create initial swarms
for i in range (N):
#    swarm[i]=np.random.rand(4)
    swarm[i]=[initialValue]*4
#    swarm[i][3]=1 # pheromone detection rate
#    print swarm[i]
    csvWriter.writerow(swarm[i])

f.close()