set title 'meerge sort'
set xlabel 'input size'
set ylabel 'basic count'
set xrange [0:100]
set yrange [20:700]
set style data linespoints
plot 'best.txt' title 'best case','avg.txt' title 'average case','worst.txt' title 'Worst case'