set title 'Linear Search'
set xrange[10:100]
set yrange[0:100]
set xlabel 'Input size (n)'
set ylabel 'Operation Count'
set style data linespoints 
plot 'worstresult.txt' title 'worst case', 'bestresult.txt' title 'best case'
