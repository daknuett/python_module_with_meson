// This is just for testing purposes.
// I got the code from there:
// https://jonathanhamberg.com/post/meson-python-modules/


// This includes all the requried Python definitions.
#include <Python.h>

// Definition of the add function in the external module interface.
static PyObject* add(PyObject *self, PyObject *args) {
    long long a, b, result;
    // PyArg_ParseTuple is a var args type function that behaves
    // similarlly to scanf by passing in a format string and the
    // pointers to the variables that are requsted.
    if(!PyArg_ParseTuple(args, "LL", &a, &b))
        return NULL;

    // Calculate the result of the add function.
    result = a + b;
    
    // Use Python's helper function to convert long long to
    // python return type.
    return PyLong_FromLong(result);
}

// Array that contains all the methods defined by this externel module.
static PyMethodDef MymathMethods[] = {
    {"add",  add, METH_VARARGS,
     "Add two numbers."},
    {NULL, NULL, 0, NULL}
};

// Structure that contains the definition of the external module.
static struct PyModuleDef mymathmodule = {
   PyModuleDef_HEAD_INIT,
   "mymath",
   NULL,
   -1,
   MymathMethods
};

// Function that gets called on load.  This creates a module with
// the PyModule_Create function.
PyMODINIT_FUNC PyInit_mymath(void) {
    return PyModule_Create(&mymathmodule);
}
