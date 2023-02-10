consensus.size <- read.csv(file = "consensus-size.csv",  header = TRUE, sep = ",")
consensus.magnitude <- read.csv(file = "consensus-magnitude.csv",  header = TRUE, sep = ",")
consensus.variance<- read.csv(file = "consensus-variance.csv",  header = TRUE, sep = ",")

#linear regression
fitSize<-lm(consensus.size$consensus.time ~ poly(consensus.size$size, 5, raw=TRUE), data = consensus.size)
#get dot plot
plot(consensus.size$consensus.time ~ consensus.size$size)
#draw curve
lines(consensus.size$size, predict(fitSize, data.frame(x=consensus.size$size)), col='red')

fitMag <- lm(consensus.magnitude$consensus.time ~ consensus.magnitude$maginitude)
plot(consensus.magnitude$consensus.time ~ consensus.magnitude$maginitude, asp=0.005)
abline(fitMag, col = 'red')

fitVar <- lm( consensus.variance$consensus.time ~ consensus.variance$variance )
plot(consensus.variance$consensus.time ~ consensus.variance$variance)
abline(fitVar, col = 'red')
