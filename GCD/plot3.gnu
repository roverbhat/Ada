set title "Modified uclid algorithm to find  gcd of 2 positive numbers"
set xrange[10:200]
set yrange[0:200]
set xlabel "Input range'
set ylabel "Basic operation count'
set style data linespoints
plot 'mubr.txt' title 'Best case ','muwr.txt' title 'Worst case'