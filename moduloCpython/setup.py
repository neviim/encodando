# -*- coding: utf-8 -*-
# Neviim - 2017
# V-0.1.5

""" Como compilar o modulo.c para Python

    Para compilar um módulo C para Python, nada mais Pythonico do que utilizar o
    próprio setup.py. O distutils possui uma opção chamada ext_modules, que te
    permite passar uma lista de módulos a serem compilados para essa biblioteca
    Python que será gerada. O código do setup.py do nosso módulo pode ser visto
    abaixo:
"""

from distutils.core import setup
from distutils.core import Extension

setup(
    name='module',
    version='1.0',
    ext_modules=[Extension('module', ['hello.c'])]
)

""" Modo de uso:

    Assim, ao executarmos a instrução python setup.py install, nosso módulo será
    compilado e nossa bibliteca disponibilizada para o runtime do Python. Vamos
    ver a saída da execução desse comando:

    $> sudo python setup.py install
    running install
    running build
    running build_ext
    ...

    * se der erro:
        building 'module' extension
        error: Unable to find vcvarsall.bat

        verifica versão do MSC.
            $ Python
            Python 3.6.1 |Anaconda custom (64-bit)| (default, May 11 2017, 13:25:24) [MSC v.1900 64 bit (AMD64)] on win32

            Tabela do compilador usado:

                MSC v.1000 -> Visual C++ 4.x
                MSC v.1100 -> Visual C++ 5
                MSC v.1200 -> Visual C++ 6
                MSC v.1300 -> Visual C++ .NET
                MSC v.1310 -> Visual C++ .NET 2003
                MSC v.1400 -> Visual C++ 2005  (8.0)
                MSC v.1500 -> Visual C++ 2008  (9.0)
                MSC v.1600 -> Visual C++ 2010 (10.0)
                MSC v.1700 -> Visual C++ 2012 (11.0)
                MSC v.1800 -> Visual C++ 2013 (12.0)
                MSC v.1900 -> Visual C++ 2015 (14.0) **
                MSC v.1910 -> Visual C++ 2017 (15.0)
"""
