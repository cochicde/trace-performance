.PHONY: build install run-improvements run-scaling run plot-improvements plot-scaling plot

build:
	./buildAll.sh

install:
	pip install matplotlib seaborn

run-improvements:
	./executeTests.sh tests/oneGeneratorOneConsumer_1x.fboot -- ./bin/performanceAnotherThread ./bin/performanceBinary ./bin/performanceClassic ./bin/performanceImprovements ./bin/performanceNotTraced ./bin/performanceNoTypeOrClock ./bin/performanceOnlySIFB

run-scaling:
	./executeTests.sh ./tests/SIFB_3.fboot ./tests/SIFB_6.fboot ./tests/SIFB_12.fboot ./tests/SIFB_25.fboot ./tests/SIFB_50.fboot ./tests/SIFB_100.fboot ./tests/ManyOutputsSIFB_3.fboot ./tests/ManyOutputsSIFB_6.fboot ./tests/ManyOutputsSIFB_12.fboot ./tests/ManyOutputsSIFB_25.fboot ./tests/ManyOutputsSIFB_50.fboot ./tests/ManyOutputsSIFB_100.fboot ./tests/oneGeneratorOneConsumer_10x.fboot ./tests/oneGeneratorOneConsumer_100x.fboot -- ./bin/performanceNotTraced/ ./bin/performanceImprovements/

run: run-improvements run-scaling

plot-improvements:
	python3 ./createImprovementGraphs.py

plot-scaling:
	python3 ./createScalingGraphs.py

plot: plot-improvements plot-scaling