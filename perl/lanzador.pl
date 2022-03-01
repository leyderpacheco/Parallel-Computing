#!/usr/bin/perl

################################################
# Fecha: 17 febrero 2022
# Autor:    Leyder Pacheco
# Materia:  Parallel Computing
# Tema: Diseño de Expermientos, Automatixacion
# de ejecucion (promedio y desviacion)
################################################

$PATH = `pwd`;
chomp($PATH);
# Variable que represente la cantidad de repeticiones
$N = 2;
#Se crea un vector de Ejecutables
@Ejecutables = ("Bench01","Bench02");
#Se crea un vector de Dimensiones NxN
@Dimension = ("100","200");

foreach $exe (@Ejecutables){
    foreach $size (@Dimension){
            $File = "$PATH/"."soluciones/"."$exe"."-$size".".txt";
            print "$File \n";
    }
}
exit(0);
