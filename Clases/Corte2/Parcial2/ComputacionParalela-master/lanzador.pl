#!/usr/bin/perl

#############################################
# Fecha: 12/04/2022
# Autor: Leyder Pacheco
# Materia: COmputacion paralela
# Tema: Para la evaluación se dispone de:
# -Algoritmo_1: benchmark multiplicación de matrices clásica filas por columnas con OpenMP (MM1cOMP).
# -Algoritmo_2: benchmark multiplicación de matrices filas por fila con OpenMP (MM1fOMP)
# -Algoritmo_3: benchmark multiplicación de matrices clásica filas por columnas Pthreads (MM1cPosix)
# Permisos del archivo: chmod +x lanzador.pl
# Ejecutable: ./lanzador.pl
#############################################

$PATH = `pwd`;
chomp($PATH);

#VARIABLE QUE REPRESENTA LA CANTIDAD DE REPETICIONES

$N =5;
#SE CREA UN VECTOR DE EJECUTABLES

@Ejecutables = ("MM1cOMP","MM1fOMP","MMPosix");

@Cores = ("1","2","4","8");

@Dimension = ("100","200","300","400","500","600","700","800","900","1000","1100","1200","1300","1400","1500","1600","1700","1800","1900","2000","2100","2200","2300","2400","2500","2600","2700","2800","2900","3000","3100","3200");

foreach $exe (@Ejecutables){
	foreach $core (@Cores){
		foreach $size (@Dimension){
			$File = "$PATH/"."Soluciones/"."$exe"."-$core"."-$size".".csv";

			#print("$File\n");
			for ($i=0; $i<$N;$i++){
				system "$PATH/$exe $size $core >> $File";

				#print("$PATH/$exe $size  \n");
			}
			close ($File);
		}
	}
}
exit(0);