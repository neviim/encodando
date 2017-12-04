/** modulo hello.c para Python
      Inclui os cabeçalhos C do CPython
*/
#include <Python.h>

/** Hello world
 * Hello world, funcao que retorna uma referncia de str para o Python object
 */
static PyObject *
hello (PyObject *self)
{
    /** funcao Py_BuildValue, sua estrutura.

    função chamada Py_BuildValue, que permite de maneira muito simples
    traduzir tipos C ANSI em tipos Python.

    - Essa função utilitária possui a seguinte interface:

        PyObject* Py_BuildValue (const char* format, ...)

            Formato            Tipo C
          ----------------------------------
            c                   char
            f                   float
            i                   int
            d                   double
            u                   Py_UNICODE*
            O                   PyObject*
            [...]               ...
            {...}               ...

    */
    return Py_BuildValue("s", "Hello Pythonista");
}

/** INTERFACES DE FUNÇÕES:

    - Existem 3 assinaturas básicas de funções. Funções sem parâmetros. Funções
      com uma lista de parâmetros. E funções com parâmetros nomeados
      (key, values). O código abaixo exemplifica essas interfaces:

        static PyObject* my_function_with_no_args (PyObject *self);
        static PyObject* my_function (PyObject *self, PyObject *args);
        static PyObject* my_function_with_keywords (PyObject *self, PyObject *args, PyObject *kwargs);

    - EXPORTANDO OS MÉTODOS DO MÓDULO

        Quais funções definidas por seu módulo ficarão públicas quando ele for
        carregado por algum programa Python? A resposta para essa pergunta está
        em uma estrutura (struct C) disponível nos headers. Esssa estrutura é a
        PyMethodDef:

        struct PyMethodDef {
          char *ml_name;         // Nome no módulo Python
          PyCFunction ml_meth;   // Endereço da função
          int ml_flags;          // Opções de assinatura de funções
          char *ml_doc;          // Docstring da função
        };

    - Essa estrutura diz ao mecanismo de criação de módulos que apenas uma
      lista de funções (PyMethodDef) serão públicas. O código abaixo mostra
      uma lista dessa estrutura. No nosso exemplo, iremos exportar apenas uma
      função: hello.

    - O último item da lista abaixo é uma sentinela. Um recurso utilizado em
      programas em C para evitar acessos indevidos a memória quando temos um
      array de structs.
*/
static char docstring[] = "Hello world, modulo para python escrito em C";

/** Lista de métodos de módulo
 */
static PyMethodDef module_methods[] = {
    /* nome , método             , opções     , documentação */
    {"hello", (PyCFunction) hello, METH_NOARGS, docstring},
    {NULL, NULL, 0, NULL} /* sentinela */
};

/* É importante ressaltar que, no exemplo acima,

    - o campo opções possui o valor METH_NOARGS. O que isso significa? Lembra
      dos três tipos de funções? Pois então, é aqui que dizemos que essa função
      deve ser exportada respeitando essa forma de interface. As formas são
      representadas por:

          1. METH_NOARGS
          2. METH_VARARGS
          3. METH_KEYWORDS

      * INICIALIZANDO O MÓDULO:

        Até aqui criamos uma função e definimos a lista de métodos públicos.
        Falta agora criar uma função que inicializa o módulo e dá um nome a ele.
        O código a seguir exemplifica como podemos fazer isso:

        Repare que o retorno dessa função é PyMODINIT_FUNC. Isso define que
        essa é a nossa função de inicialização. Obrigatoriamente, a função de
        inicialização tem que se chamar init + nome_do_módulo. No nosso exemplo
        será: initmodule. Isso varia de acordo com a versão do Python.

        PyMODINIT_FUNC init<yourmodulename>(void)    // Python 2
        PyMODINIT_FUNC PyInit_<yourmodulename>(void) // Python 3

        - Feito isso, no corpo dessa função, basta apenas chamar a função
          Py_InitModule dizendo qual o nome do nosso módulo e passando aquela
          nossa lista de métodos que definimos anteriormente. Estamos utilizando
          seu modo mais simples; com apenas dois parâmetros. No entanto existem
          outras formas de chamar a inicialização com mais opções,
          como no exemplo abaixo:

          PyObject* Py_InitModule( char *name, PyMethodDef *methods)
          PyObject* Py_InitModule3(char *name, PyMethodDef *methods, char *doc)
          PyObject* Py_InitModule4(char *name, PyMethodDef *methods, char *doc, PyObject *self, int apiver)

      - Fechamos aqui o código do nosso módulo simples.
*/
PyMODINIT_FUNC
PyInit_module(void)
{
    PyModule_hello("module", module_methods);
}
