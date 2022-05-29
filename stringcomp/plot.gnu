set title 'String comparision'
set xrange[100:1000]
set yrange[0:1847]
set xlabel 'input size'
set ylabel 'basic count'
set style data linespoints
plot 'best.txt' title 'Best case','avg.txt' title 'Average case'