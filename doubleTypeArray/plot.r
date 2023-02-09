consensus.data <- read.csv(file = "consensus.csv",  header = TRUE, sep = ",")
#get dot plot
plot(consensus.data$consensus.time ~ consensus.data$size)
#linear regression
mod.log<-lm(consensus.data$consensus.time ~ log(consensus.data$size, 3))
#draw curve
curve(coef(mod.log)[1] + coef(mod.log)[2]*log(x, 3), add=TRUE)
