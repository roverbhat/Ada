set title 'meerge sort'
set xlabel 'input size'
set ylabel 'basic count'
set xrange [0:100]
set yrange [16:1740]
set style data linespoints
plot 'worst.txt' title 'worstcase','best.txt' title 'bestcase'