macOS.8c8t.appleSilicon <- c(4513305, 2503207, 1314020, 1263112, 1207410, 1138060, 1146194, 1158409, 1297107)
linux.6c6t.intelCore <- c(83629287, 44414419, 36138871,39909160, 33613634, 37518551)
wsl.8t16t.amdRyzen <- c(28652192, 13034974, 9231794, 7346610)

threads <- c(2, 4, 6, 8, 12, 16)

fitApple <- lm(macOS.8c8t.appleSilicon ~ poly(threads, 6, raw = TRUE))
plot(macOS.8c8t.appleSilicon ~ threads)
lines(threads, predict(fitApple, data.frame(x = threads)), col = 'green')

fitIntel <- lm(linux.6c6t.intelCore ~ poly(threads, 6, raw = TRUE))
plot(linux.6c6t.intelCore ~ threads,)
lines(threads, predict(fitIntel, data.frame(x = threads)), col = 'blue')

fitAmd <- lm(wsl.8t16t.amdRyzen ~ poly(threads, 6, raw = TRUE))
plot(wsl.8t16t.amdRyzen ~ threads)
lines(threads, predict(fitAmd, data.frame(x = threads)), col = 'orange')
