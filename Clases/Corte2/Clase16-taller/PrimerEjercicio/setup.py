from setuptools import setup
from Cython.Build import cythonize
#se realiza el setup que inicializa holamundo.pyx mediante cython
setup(
    ext_modules = cythonize("holamundo.pyx")
)