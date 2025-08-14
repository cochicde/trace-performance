# trace-performance
Tools to execute performance analysis on tracing in 4diac FORTE

# Performance Tests
There are two types of tests: 
- improving the tracing configuration
- scaling performance

The first one refers to the tracing configuration in 4diac FORTE. Different improvements were done in the existing tracing mechanism. Each improvements is in its own branch, and the same test is performed for each binary and then compared.

Scaling performance is about checking how the best of the tracing configuration scales in two dimensions:
- increasing the amount of Function Blocks (1x, 10x, 100x)
- increasing the percentage of Service Interface Function Blocks in respect to the total amount of FBs. SIFB are the ones being traced, therefore increasing the ratio of them should show an impact in performance.

# Build all trace configurations
Build all 4diac FORTE configurations.

```
make build
```

Grab a coffee, It will take some time. 

# Install all needed python package 

```
make install
```

# Run the tests
## Improving the tracing configuration
```
make run-improvements
make plot-improvements
```

## Scaling tests

```
make run-scaling
make plot-scaling
```

## Run all
If you want to run all, you can do

```
make run
make plot
```

# Results

The plots are stored under `results`. The main graphs are shown here.

## Config Improvements

### Not traced vs Classic trace

![Not Traced vs Classic Trace - Time](results/oneGeneratorOneConsumer_1x/NotTracedvsClassic_Time.png)
![Not Traced vs Classic Trace - Size](results/oneGeneratorOneConsumer_1x/NotTracedvsClassic_Size.png)

### Classic vs SIFB Only

![Classic vs SIFB Only - Time](results/oneGeneratorOneConsumer_1x/ClassicvsOnlySIFB_Time.png)
![Classic vs SIFB Only - Size](results/oneGeneratorOneConsumer_1x/ClassicvsOnlySIFB_Size.png)

### String vs Binary

![String vs Binary - Time](results/oneGeneratorOneConsumer_1x/OnlySIFBvsBinary_Time.png)
![String vs Binary - Size](results/oneGeneratorOneConsumer_1x/OnlySIFBvsBinary_Size.png)

### Binary vs Without clock and type

![Binary vs Without Clock and Type - Time](results/oneGeneratorOneConsumer_1x/BinaryvsNoTypeOrClock_Time.png)
![Binary vs Without Clock and Type - Size](results/oneGeneratorOneConsumer_1x/BinaryvsNoTypeOrClock_Size.png)

### Without clock and type vs With memory optimizations

![Without Clock and Type vs with memory optimization - Time](results/oneGeneratorOneConsumer_1x/NoTypeOrClockvsImprovements_Time.png)
![Without Clock and Type vs with memory optimization - Size](results/oneGeneratorOneConsumer_1x/NoTypeOrClockvsImprovements_Size.png)

### All configs

![All Configs - Time](results/oneGeneratorOneConsumer_1x/ClassicvsOnlySIFBvsBinaryvsNoTypeOrClockvsImprovementsvsNotTraced_Time.png)
![All Configs - Size](results/oneGeneratorOneConsumer_1x/ClassicvsOnlySIFBvsBinaryvsNoTypeOrClockvsImprovementsvsNotTraced_Size.png)

### All configs without classic

![All Configs without classic - Time](results/oneGeneratorOneConsumer_1x/OnlySIFBvsBinaryvsNoTypeOrClockvsImprovementsvsNotTraced_Time.png)
![All Configs without classic - Size](results/oneGeneratorOneConsumer_1x/OnlySIFBvsBinaryvsNoTypeOrClockvsImprovementsvsNotTraced_Size.png)

## Scaling

## Increasing amount of FBs

![Increasing amount of FBs - Time](results/IncreaasinAmountOfFBs_line_graph.png)
![Increasing amount of FBs - Size](results/IncreaasinAmountOfFBs_trace_size_graph.png)

## Scaling SIFBs

![Scaling SIFBs - Time](results/ScalingSIFBs_line_graph.png)
![Scaling SIFBs - Size](results/ScalingSIFBs_trace_size_graph.png)

## Scaling Heavier SIFBs

![Scaling Heavier SIFBs - Time](results/ScalingHeavierSIFBs_line_graph.png)
![Scaling Heavier SIFBs - Size](results/ScalingHeavierSIFBs_trace_size_graph.png)
