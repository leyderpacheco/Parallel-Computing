#!/usr/bin/perl

#############################################
# Fecha: 17 Febrero 2022
# Autor: Leyder Pacheco
# Materia: COmputacion paralela
# Tema: DIseño de experimentos , Automatizacion de ejecucion (promedio y desviacion estandar)
# Permisos del archivo: chmod +x lanzador.pl
# Ejecutable: ./lanzador.pl
#############################################

$PATH = `pwd`;
chomp($PATH);

#VARIABLE QUE REPRESENTA LA CANTIDAD DE REPETICIONES

$N =10;
#SE CREA UN VECTOR DE EJECUTABLES

@Ejecutables = ("ejecutable_bench01","ejecutable_bench02");

@Dimension = ("100", "200");

foreach $exe (@Ejecutables){
	foreach $size (@Dimension){
		$File = "$PATH/"."Soluciones/"."$exe"."-$size".".txt";

		#print("$File\n");
		for ($i=0; $i<$N;$i++){
			system "$PATH/$exe $size >> $File";

			#print("$PATH/$exe $size  \n");
		}
		close ($File);
	}
}
exit(0);