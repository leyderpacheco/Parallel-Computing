# Punto 2 taller
# Serie Fibonacci Python
# Autor: Leyder Pacheco
# computacion paralela 

#Se realiza el setup del programa en cython
from distutils.core import setup, Extension
from Cython.Build import cythonize

exts=(cythonize("fibCy.pyx"))
setup(ext_modules=exts)

#python setup.py build_ext --inplace