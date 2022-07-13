set title 'heap sort'
set xlabel 'input size'
set ylabel 'basic count'
set xrange [10:90]
set yrange [16:570]
set style data linespoints
plot 'best.txt' title 'best case','avg.txt' title 'avg case','worst.txt' title 'worst case'