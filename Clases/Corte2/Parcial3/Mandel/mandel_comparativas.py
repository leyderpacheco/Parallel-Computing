import numpy as np
import matplotlib.pyplot as plt
import sys
from mandel import compute_mandel as compute_mandel_py
from mandel_cyt import compute_mandel as compute_mandel_cyt
import csv


def plot_mandel(mandel):
    plt.imshow(mandel)
    plt.axis('off')
    #plt.show()

def main_python(kwargs):
    #Python#
    mandel_set, runtime = compute_mandel_py(**kwargs)
    return mandel_set, runtime
    
def main_cython(kwargs):
    #Cyton#
    mandel_set, runtime = compute_mandel_cyt(**kwargs)
    return mandel_set, runtime
    
    
if __name__ == '__main__':
#*******************************CSV*************************************************#

    #inicializacion de vector que será la cabecera de un archivo csv
    cabecera = ['n_steps','tiempo_python','tiempo_cython','speedup']

    #Inicializamos el archivo csv para escribir los resultados
    myFile = open('resultados.csv', 'w',encoding='utf8')
    writer = csv.writer(myFile)

    #En el archivo csv escribimos la cabecera
    writer.writerow(cabecera)
#***********************************************************************************#    

    kwargs = dict(cr=0.285, ci=0.01, N=200, bound=1.5) 
    for i in range(100,1300,100):
        kwargs["N"] = i

        mandel_set, runtime_python = main_python(kwargs)
        print('Python Mandelbrot set generated in {0:5.2f} seconds'.format(runtime_python))
        mandel_set, runtime_cython = main_cython(kwargs)
        print('cython Mandelbrot set generated in {0:5.2f} seconds'.format(runtime_cython))


        #speed_up es cuantas veces cyton es mas rapido que python
        speed_up = runtime_python/runtime_cython
        print(speed_up)
        #Guardamos los resultados en un vector
        resultados = [i,runtime_python,runtime_cython,speed_up]
            
        #Escribimos los resultados en el archivo csv
        writer.writerow(resultados)
    myFile.close()