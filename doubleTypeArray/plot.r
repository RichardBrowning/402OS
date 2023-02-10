consensus.data <- read.csv(file = "consensus.csv",  header = TRUE, sep = ",")
#get dot plot
plot(consensus.data$consensus.time ~ consensus.data$size)
 #linear regression
fit<-lm(consensus.data$consensus.time ~ poly(consensus.data$size, 2, raw=TRUE))
#draw curve
curve(coef(mod.log)[1] + coef(mod.log)[2]*log(x, 3), add=TRUE)
