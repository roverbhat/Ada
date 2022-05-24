set title 'binary'
set xrange[10:100]
set yrange[0:5000]
set xlabel 'inputsize'
set ylabel 'basic count'
set style data linespoints
plot 'best.txt' title 'Best case','worst.txt' title 'Worst case'