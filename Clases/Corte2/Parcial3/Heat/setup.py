import numpy
from distutils.core import setup, Extension
from Cython.Build import cythonize

exts=(cythonize("heat_cyt.pyx"))
setup(ext_modules=exts,include_dirs=[numpy.get_include()])

#python3 setup.py build_ext --inplace
