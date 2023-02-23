# Names: Lucas Hasting, Ethan Nix, Krutivas Pradhan
# Course: CS 355
# Assignment: Assignment 7
# Date: 2/23/2023
# Program Description: Analyze the dataFinal.csv and data.csv files
# File Name: Analyze.R
# File Contribution: Lucas Hasting
# Reference 1: https://www.statmethods.net/management/subset.html 
# Reference 2: https://www.geeksforgeeks.org/how-to-overlay-plots-in-r/
# Reference 3: http://www.sthda.com/english/wiki/add-legends-to-plots-in-r-software-the-easiest-way


#Read all the data
data <- read.csv("dataFinal.csv")

#Semi-Random data had to be redone
data2 <- read.csv("data.csv")

#Subset the data
dataRandom <- subset(data, test_type == "Random")
dataSemiRandom <- subset(data2, test_type == "Semi-Random")
dataRandomMax <- subset(data, test_type == "Random-Max")
dataRandomMin <- subset(data, test_type == "Random-Min")
dataAscending <- subset(data, test_type == "Ascending")
dataDescending <- subset(data, test_type == "Descending")

#plot all the data individually
plot(dataRandom$size ~ dataRandom$time, xlab = "Time", ylab = "Size", main = "Random with Max = Size", col = "red", pch = 19)
plot(dataSemiRandom$size ~ dataSemiRandom$time, xlab = "Time", ylab = "Size", main = "Semi-Random", col = "blue", pch = 19)
plot(dataRandomMax$size ~ dataRandomMax$time, xlab = "Time", ylab = "Size", main = "Random Max", col = "green", pch = 19)
plot(dataRandomMin$size ~ dataRandomMin$time, xlab = "Time", ylab = "Size", main = "Random Max = 10", col = "purple", pch = 19)
plot(dataAscending$size ~ dataAscending$time, xlab = "Time", ylab = "Size", main = "Ascending Data", col = "pink", pch = 19)
plot(dataDescending$size ~ dataDescending$time, xlab = "Time", ylab = "Size", main = "Descending Data", col = "black", pch = 19)

#Make a big plot for all the data
plot(1, type = "n", xlim=c(0,7),ylim=c(0,dataRandomMax$size[1]),  xlab = "Time", ylab = "Size", main = "All Plots")

#assign all the points
points(dataRandom$size ~ dataRandom$time, col = "red", pch = 19)
points(dataSemiRandom$size ~ dataSemiRandom$time, col = "blue", pch = 19)
points(dataRandomMax$size ~ dataRandomMax$time, col = "green", pch = 19)
points(dataRandomMin$size ~ dataRandomMin$time, col = "purple", pch = 19)
points(dataAscending$size ~ dataAscending$time, col = "pink", pch = 19)
points(dataDescending$size ~ dataDescending$time, col = "black", pch = 19)

#assign the legend
legend(4, dataRandomMax$size[1]/1.5, legend=c("Random with Max = Size", "Semi-Random", "Random Max", "Random Max = 10", "Ascending Data", "Descending Data"),
       col=c("red", "blue", "green", "purple", "pink", "black"), pch = 19, cex=0.8)