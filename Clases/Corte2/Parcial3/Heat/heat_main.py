from __future__ import print_function
import time
import argparse
import csv

from heat import init_fields, write_field, iterate
from heat_cyt import init_fields_cyt, write_field_cyt, iterate_cyt

def main(input_file='bottle.dat', a=0.5, dx=0.1, dy=0.1, 
         timesteps=200, image_interval=4000):

    # Initialise the temperature field
    field, field0 = init_fields(input_file)

#*******************************CSV*************************************************#

    #inicializacion de vector que será la cabecera de un archivo csv
    cabecera = ['n_steps','tiempo_python','tiempo_cython','speedup']

    #Inicializamos el archivo csv para escribir los resultados
    myFile = open('resultados.csv', 'w',encoding='utf8')
    writer = csv.writer(myFile)

    #En el archivo csv escribimos la cabecera
    writer.writerow(cabecera)

#************************Testing***************************************************#
    #Bucle en diferentes n_steps para la funcion step_time
    vector_time_span = [x for x in range (50,1200,50)]

    for timesteps in vector_time_span: 
    #************************************Python****************************************#
        # Plot/save initial field
        write_field(field, 0)
        # Iterate
        initTimePython = time.time()
        iterate(field, field0, a, dx, dy, timesteps, image_interval)
        endTimePython = time.time()
        # Plot/save final field
        write_field(field, timesteps)

        TotalTimePy = endTimePython - initTimePython
        print("Simulation in PYTHON finished in {0} s".format(TotalTimePy))

    #************************************Cython****************************************#

        # Plot/save initial field
        write_field_cyt(field, 0)
        # Iterate_cyt
        initTimeCython = time.time()
        iterate_cyt(field, field0, a, dx, dy, timesteps, image_interval)
        endTimeCython = time.time()
        # Plot/save final field
        write_field_cyt(field, timesteps)
        TotalTimeCy= endTimeCython - initTimeCython

        print("Simulation in CYTHON finished in {0} s".format(TotalTimeCy))

        #speed_up es cuantas veces cyton es mas rapido que python
        speed_up = TotalTimePy/TotalTimeCy

        #Guardamos los resultados en un vector
        resultados = [timesteps,TotalTimePy,TotalTimeCy,speed_up]
        
        #Escribimos los resultados en el archivo csv
        writer.writerow(resultados)
    
    myFile.close()



if __name__ == '__main__':

    # Process command line arguments
    parser = argparse.ArgumentParser(description='Heat equation')
    parser.add_argument('-dx', type=float, default=0.01,help='grid spacing in x-direction')
    parser.add_argument('-dy', type=float, default=0.01,help='grid spacing in y-direction')
    parser.add_argument('-a', type=float, default=0.5,help='diffusion constant')
    parser.add_argument('-n', type=int, default=200,help='number of time steps')
    parser.add_argument('-i', type=int, default=4000,help='image interval')
    parser.add_argument('-f', type=str, default='bottle.dat',help='input file')

    args = parser.parse_args()

    main(args.f, args.a, args.dx, args.dy, args.n, args.i)

