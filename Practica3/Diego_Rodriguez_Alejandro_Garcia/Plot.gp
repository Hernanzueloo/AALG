set title "Comparación algóritmos de búsqueda para n times=1 con generación de claves uniforme"
set xlabel "Tamaño"
set ylabel "AvOB"
set xrange [1000:10000]
set yrange [0: 5010]
set term jpeg
set output "CompUniform_Key_n_times=1AvOB.jpeg"
plot "Lin_Search_Uniform_KeyN_times=1.log" using 1:3 lt rgb "blue" title "Lin Search AvOB" with l,"Lin_Auto_Search_Uniform_KeyN_times=1.log" using 1:3 lt rgb "violet" title "Lin Auto Search AvOB" with l, "Bin_Search_Uniform_KeyN_times=1.log" using 1:3 lt rgb "green" title "Bin Search AvOB" with l, log(x)/log(2) title "Log(N)", x title "N"

set title "Comparación algóritmos de búsqueda para n times=1000 con generación de claves uniforme"
set xlabel "Tamaño"
set ylabel "AvOB"
set xrange [1000:10000]
set yrange [0: 5010]
set term jpeg
set output "CompUniform_Key_n_times=1000AvOB.jpeg"
plot "Lin_Search_Uniform_KeyN_times=1000.log" using 1:3 lt rgb "blue" title "Lin Search AvOB" with l,"Lin_Auto_Search_Uniform_KeyN_times=1000.log" using 1:3 lt rgb "violet" title "Lin Auto Search AvOB" with l, "Bin_Search_Uniform_KeyN_times=1000.log" using 1:3 lt rgb "green" title "Bin Search AvOB" with l, log(x)/log(2) title "Log(N)", x title "N"

set title "Comparación algóritmos de búsqueda para n times=100 con generación de claves uniforme"
set xlabel "Tamaño"
set ylabel "AvOB"
set xrange [1000:10000]
set yrange [0: 5010]
set term jpeg
set output "CompUniform_Key_n_times=100AvOB.jpeg"
plot "Lin_Search_Uniform_KeyN_times=100.log" using 1:3 lt rgb "blue" title "Lin Search AvOB" with l,"Lin_Auto_Search_Uniform_KeyN_times=100.log" using 1:3 lt rgb "violet" title "Lin Auto Search AvOB" with l, "Bin_Search_Uniform_KeyN_times=100.log" using 1:3 lt rgb "green" title "Bin Search AvOB" with l, log(x)/log(2) title "Log(N)", x title "N"

set title "Comparación algóritmos de búsqueda para n times=1 con generación de claves potencial"
set xlabel "Tamaño"
set ylabel "AvOB"
set xrange [1000:10000]
set yrange [0: 5010]
set term jpeg
set output "CompPotential_Key_n_times=1AvOB.jpeg"
plot "Lin_Search_Potential_KeyN_times=1.log" using 1:3 lt rgb "blue" title "Lin Search AvOB" with l,"Lin_Auto_Search_Potential_KeyN_times=1.log" using 1:3 lt rgb "violet" title "Lin Auto Search AvOB" with l, "Bin_Search_Potential_KeyN_times=1.log" using 1:3 lt rgb "green" title "Bin Search AvOB" with l, log(x)/log(2) title "Log(N)", x title "N"

set title "Comparación algóritmos de búsqueda para n times=1000 con generación de claves potencial"
set xlabel "Tamaño"
set ylabel "AvOB"
set xrange [1000:10000]
set yrange [0: 5010]
set term jpeg
set output "CompPotential_Key_n_times=1000AvOB.jpeg"
plot "Lin_Search_Potential_KeyN_times=1000.log" using 1:3 lt rgb "blue" title "Lin Search AvOB" with l,"Lin_Auto_Search_Potential_KeyN_times=1000.log" using 1:3 lt rgb "violet" title "Lin Auto Search AvOB" with l, "Bin_Search_Potential_KeyN_times=1000.log" using 1:3 lt rgb "green" title "Bin Search AvOB" with l, log(x)/log(2) title "Log(N)", x title "N"

set title "Comparación algóritmos de búsqueda para n times=100 con generación de claves potencial"
set xlabel "Tamaño"
set ylabel "AvOB"
set xrange [1000:10000]
set yrange [0: 5010]
set term jpeg
set output "CompPotential_Key_n_times=100AvOB.jpeg"
plot "Lin_Search_Potential_KeyN_times=100.log" using 1:3 lt rgb "blue" title "Lin Search AvOB" with l,"Lin_Auto_Search_Potential_KeyN_times=100.log" using 1:3 lt rgb "violet" title "Lin Auto Search AvOB" with l, "Bin_Search_Potential_KeyN_times=100.log" using 1:3 lt rgb "green" title "Bin Search AvOB" with l, log(x)/log(2) title "Log(N)", x title "N"


set title "Comparación de lin search y lin auto search en tiempos con n_times=100 con generación de claves uniforme"
set xlabel "Tamaño"
set ylabel "Tiempo"
set xrange [1000:10000]
set yrange [0: 10]
set term jpeg
set output "CompLinYLinAutoUniform_Key_n_times=100Tiempos.jpeg"
plot "Lin_Search_Uniform_KeyN_times=100.log" using 1:2 lt rgb "blue" title "Lin Search Tiempo" with l,"Lin_Auto_Search_Uniform_KeyN_times=100.log" using 1:2 lt rgb "violet" title "Lin Auto Search Tiempo" with l

set title "Bin Search en tiempos con n_times=100 con generación de claves uniforme"
set xlabel "Tamaño"
set ylabel "Tiempo"
set xrange [1000:10000]
set yrange [0: 0.15]
set term jpeg
set output "BinUniform_Key_n_times=100Tiempos.jpeg"
plot "Bin_Search_Uniform_KeyN_times=100.log" using 1:2 lt rgb "blue" title "Bin Search Tiempo" with l



set title "Comparación de bin search y lin auto search en tiempos con n times=100 con generación de claves potencial"
set xlabel "Tamaño"
set ylabel "Tiempo"
set xrange [1000:10000]
set yrange [0: 2]
set term jpeg
set output "CompBinYLinAutoUniform_Key_n_times=100Tiempos.jpeg"
plot "Bin_Search_Potential_KeyN_times=100.log" using 1:2 lt rgb "blue" title "Bin Search Tiempo" with l,"Lin_Auto_Search_Potential_KeyN_times=100.log" using 1:2 lt rgb "violet" title "Lin Auto Search Tiempo" with l,"Lin_Search_Potential_KeyN_times=100.log" using 1:2 lt rgb "blue" title "Lin Search Tiempo" with l

set title "Lin Search en tiempos con n times=100 con generación de claves uniforme"
set xlabel "Tamaño"
set ylabel "Tiempo"
set xrange [1000:10000]
set yrange [0: 10]
set term jpeg
set output "LinSUniform_Key_n_times=100Tiempos.jpeg"
plot "Lin_Search_Potential_KeyN_times=100.log" using 1:2 lt rgb "blue" title "Lin Search Tiempo" with l




set title "Comparación de lin search y lin auto search en tiempos con n times=1000 con generación de claves uniforme"
set xlabel "Tamaño"
set ylabel "Tiempo"
set xrange [1000:10000]
set yrange [0: 15]
set term jpeg
set output "CompLinYLinAutoUniform_Key_n_times=1000Tiempos.jpeg"
plot "Lin_Search_Uniform_KeyN_times=1000.log" using 1:2 lt rgb "blue" title "Lin Search Tiempo" with l,"Lin_Auto_Search_Uniform_KeyN_times=1000.log" using 1:2 lt rgb "violet" title "Lin Auto Search Tiempo" with l

set title "Bin Search en tiempos con n times=1000 con generación de claves uniforme"
set xlabel "Tamaño"
set ylabel "Tiempo"
set xrange [1000:10000]
set yrange [0: 0.15]
set term jpeg
set output "BinUniform_Key_n_times=1000Tiempos.jpeg"
plot "Bin_Search_Uniform_KeyN_times=1000.log" using 1:2 lt rgb "blue" title "Bin Search Tiempo" with l



set title "Comparación de bin search y lin auto search en tiempos con n times=1000 con generación de claves potencial"
set xlabel "Tamaño"
set ylabel "Tiempo"
set xrange [1000:10000]
set yrange [0: 1]
set term jpeg
set output "CompBinYLinAutoPotential_Key_n_times=1000Tiempos.jpeg"
plot "Bin_Search_Potential_KeyN_times=1000.log" using 1:2 lt rgb "blue" title "Bin Search Tiempo" with l,"Lin_Auto_Search_Potential_KeyN_times=1000.log" using 1:2 lt rgb "violet" title "Lin Auto Search Tiempo" with l

set title "Lin Search en tiempos con n times=1000 con generación de claves uniforme"
set xlabel "Tamaño"
set ylabel "Tiempo"
set xrange [1000:10000]
set yrange [0: 10]
set term jpeg
set output "LinSearchPotential_Key_n_times=1000Tiempos.jpeg"
plot "Lin_Search_Potential_KeyN_times=1000.log" using 1:2 lt rgb "blue" title "Lin Search Tiempo" with l

###################################################################################################################################################3
set title "Comparación algóritmos de búsqueda para OB con generación de claves potencial"
set xlabel "Tamaño"
set ylabel "AvOB"
set xrange [100:1000]
set yrange [0: 20]
set term jpeg
set output "CompPotential_KeyAvOBTam1000.jpeg"

f(x)=a*log(x)/log(2)+b
fit f(x) "Bin_Search_Potential_KeyN_times=1000.log" using 1:3 via a,b
g(x)=d*log(x)/log(2)+c
fit g(x) "Lin_Auto_Search_Potential_KeyN_times=1000.log" using 1:3 via d, c
plot "Bin_Search_Potential_KeyN_times=1000.log" using 1:3 lt rgb "blue" title "Bin Search Tiempo" with l,f(x) title sprintf("f(x)=%.2f*log(N)+%.2f",a,b),"Lin_Auto_Search_Potential_KeyN_times=1000.log" using 1:3 lt rgb "violet" title "Lin Auto Search Tiempo" with l,g(x) title sprintf("g(x)=%.2f*log(N)+%.2f",d,c), log(x)/log(2)
