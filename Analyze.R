data <- read.csv("data.csv")

dataRandom <- subset(data, test_type == "Random")

dataSemiRandom <- subset(data, test_type == "Semi-Random")

dataRandomMax <- subset(data, test_type == "Random-Max")

dataRandomMin <- subset(data, test_type == "Random-Min")

dataAscending <- subset(data, test_type == "Ascending")

dataDescending <- subset(data, test_type == "Descending")

plot(dataRandom$size ~ dataRandom$time, xlab = "Time", ylab = "Size", main = "Random with Max = Size", col = "red", pch = 19)
plot(dataSemiRandom$size ~ dataSemiRandom$time, xlab = "Time", ylab = "Size", main = "Semi-Random", col = "blue", pch = 19)
plot(dataRandomMax$size ~ dataRandomMax$time, xlab = "Time", ylab = "Size", main = "Random Max", col = "green", pch = 19)
plot(dataRandomMin$size ~ dataRandomMin$time, xlab = "Time", ylab = "Size", main = "Random Max = 10", col = "purple", pch = 19)
plot(dataAscending$size ~ dataAscending$time, xlab = "Time", ylab = "Size", main = "Ascending Data", col = "pink", pch = 19)
plot(dataDescending$size ~ dataDescending$time, xlab = "Time", ylab = "Size", main = "Descending Data", col = "black", pch = 19)

plot(1, type = "n", xlim=c(0,7),ylim=c(0,dataRandomMax$size[1]),  xlab = "Time", ylab = "Size", main = "All Plots")
points(dataRandom$size ~ dataRandom$time, col = "red", pch = 19)
points(dataSemiRandom$size ~ dataSemiRandom$time, col = "blue", pch = 19)
points(dataRandomMax$size ~ dataRandomMax$time, col = "green", pch = 19)
points(dataRandomMin$size ~ dataRandomMin$time, col = "purple", pch = 19)
points(dataAscending$size ~ dataAscending$time, col = "pink", pch = 19)
points(dataDescending$size ~ dataDescending$time, col = "black", pch = 19)