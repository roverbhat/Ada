set title 'warshel'
set xlabel 'input size'
set ylabel 'basic count'
set xrange [4:12]
set yrange [64:1331]
set style data linespoints
plot 'output.txt' title 'warshel algo'
