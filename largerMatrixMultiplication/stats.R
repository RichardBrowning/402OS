macOS.8c8t.appleSilicon <- c(4513305, 2503207, 1314020, 1263112, 1207410, 1138060, 1146194, 1158409, 1297107)
linux.6c6t.intelCore <- c(9830040, 4175220,3079806, 1328057, 2156867, 2615748, 1376672, 2589154, 2644351)
wsl.8t16t.amdRyzen <- c(4272792,2359084, 1269868, 946311, 743075, 638274, 576330, 518119, 489460)

threads <- c(1, 2, 4, 6, 8, 10, 12, 14, 16)

fitApple <- lm(macOS.8c8t.appleSilicon ~ poly(threads, 8, raw = TRUE))
plot(macOS.8c8t.appleSilicon ~ threads)
lines(threads, predict(fitApple, data.frame(x = threads)), col = 'green')

fitIntel <- lm(linux.6c6t.intelCore ~ poly(threads, 8, raw = TRUE))
plot(linux.6c6t.intelCore ~ threads,)
lines(threads, predict(fitIntel, data.frame(x = threads)), col = 'blue')

fitAmd <- lm(wsl.8t16t.amdRyzen ~ poly(threads, 8, raw = TRUE))
plot(wsl.8t16t.amdRyzen ~ threads)
lines(threads, predict(fitAmd, data.frame(x = threads)), col = 'orange')
