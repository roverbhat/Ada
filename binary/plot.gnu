set title "Binary search"
set xrange[10:100]
set yrange[0:15]
set xlabel "Input size of the array'
set ylabel "Basic operation count'
set style data linespoints
plot 'best.txt' title 'Best case ','worst.txt' title 'Worst case'