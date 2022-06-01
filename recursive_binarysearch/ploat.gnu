set title "Binary search using recursion'
set xlabel 'input size'
set ylabel 'Basic operation count'
set xrange [10:100]
set yrange [0:8]
set style data linespoints
plot 'best.txt' title 'Best case','worst.txt' title 'Worst case','avg.txt' title 'Average case'