#!/usr/bin/perl

#   Date: 08/03/2022
#   Author: Juan Camilo Rodriguez
#   Subjebt: Paralell Computation.
#   Topic: Diseño de experimentos, 

$PATH = `pwd`;
chomp($PATH);
print("Source: ".$PATH. "\n\n");

#Varaible who represents the number of repetitions for each executable file   
$N = 31;
#Vector of executable benchmarks
@ejecutables = ("ejecutable_MM1c", "ejecutable_MM1f";

#Vector NxN for matrix
@matrix_size = ("100", "100");

foreach $exe (@ejecutables){
    foreach $size (@matrix_size){
        $file = "$PATH/"."experimentos/"."$exe"."-$size".".txt";
        #print($file."\n");
        for ($i = 0; $i < $N; $i++){
            #print("$PATH/$exe $size \n");
            system "$PATH/$exe $size >> $file";
        }
        close $file; 
    }
}
exit(0);

# To make this file executable
#   chmod +x launcher.pl