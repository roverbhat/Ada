set title 'String comparision'
set xrange[100:1000]
set yrange[0:3500]
set xlabel 'input_size'
set ylabel 'basic_count'
set style data linespoints
plot 'best.txt' title 'Best_case','worst.txt' title 'Worst_case'