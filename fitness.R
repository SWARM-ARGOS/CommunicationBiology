x <- read.csv(commandArgs(trailingOnly=TRUE)[1], sep = ",", header = F)
fitness <- mean(x$V1)
fitness_max <- max(x$V1)
cat(fitness, fitness_max, "\n", file="fitness.csv", append=T, sep = ",")
