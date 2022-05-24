set title "Consicutive integer checking method  algorithm to find  gcd of 2 positive numbers"
set xrange[10:200]
set yrange[-1:200]
set xlabel "Input range'
set ylabel "Basic operation count'
set style data linespoints
plot 'cbr.txt' title 'Best case ','cwr.txt' title 'Worst case'