consensus.data <- read.csv(file = "consensus-size.csv",  header = TRUE, sep = ",")
#get dot plot
plot(consensus.data$consensus.time ~ consensus.data$size)
#linear regression
fit<-lm(consensus.data$consensus.time ~ poly(consensus.data$size, 3, raw=TRUE), data = consensus.data)
#draw curve
#curve(coef(mod.log)[1] + coef(mod.log)[2]*(x^2), add=TRUE)
lines(consensus.data$size, predict(fit, data.frame(x=consensus.data$size)), col='red')

