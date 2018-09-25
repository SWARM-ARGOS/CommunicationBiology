import numpy as np
import csv
import sys

N=200
sum=0.0
mutation=0.001
# MAXSTEP=12000
#sigma=0.1
#TSize=10

fitness=[]
offspring=[]
parent=[]

# Input current generation
f = open(sys.argv[1], 'rb')

dataReader=csv.reader(f)

for row in dataReader:
    parent.append(map(float, row))

f.close()

#print parent

# Define absolute fitness
count = 0
for line in open("tmp", "r"):
    fitness.append(float(line))
    sum += fitness[count]
    count += 1

print fitness
f.close()

# Calculate relative fitness
for i in range(N):
    fitness[i] = fitness[i] / float(sum)

# print fitness

f = open('offspring_log.csv','a')

# Roulette wheel selection
for i in range(N):
    point = np.random.rand()
    pointAt = 0.0
    for j in range(N):
        pointAt += fitness[j]
        if point <= pointAt:
            offspring.append(map(float, parent[j]))
            f.write(str(j)+",")
            break

f.write('\n')
f.close()

# Tournament selection

#for i in xrange(N):
#    num=[]
#    num=np.random.choice(N, TSize, replace=False)
#    candidate=[]
#    for j in xrange(TSize):
#        candidate.append(fitness[num[j]])

#    candi_num=np.argmax(candidate)
#    offspring.append(parent[num[candi_num]])

# print offspring

# Mutation
#for i in range(N):
#    for j in range(len(offspring[i])-1):
#        if np.random.rand() <= mutation:
#            offspring[i][j] = np.random.normal(loc=offspring[i][j], scale=sigma)
#            if offspring[i][j] > 1:
#                offspring[i][j] = 1
#            if offspring[i][j] < 0:
#                offspring[i][j] = 0
                
# Mutation
for i in range(N):
    for j in range(len(offspring[i])):
        if np.random.rand() <= mutation:
            if offspring[i][j] == 1.0:
                offspring[i][j] = 0.0
            else:
                offspring[i][j] = 1.0

#print fitness

f = open('output.csv', 'ab')

csvWriter=csv.writer(f)

for i in range (N):
    csvWriter.writerow(offspring[i])

f.close()

count1011=0
for i in range(N):
    if offspring[i][0] == 1 and offspring[i][1] == 0 and offspring[i][2]== 1 and offspring[i][3] == 1:
        count1011 += 1

if count1011 == N:
    f = open('exit.txt','w')
    f.write("exit")
    f.close
