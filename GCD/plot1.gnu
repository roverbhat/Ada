set title "Uclid algorithm for gcd"
set xrange[10:200]
set yrange[0:15]
set xlabel "Input range'
set ylabel "Basic operation count'
set style data linespoints
plot 'ubr.txt' title 'Best case ','uwr.txt' title 'Worst case'