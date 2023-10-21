# Circular Array
********************

El circular array es una estructura de datos que simula un array de forma circular, y algunos de sus métodos pueden ser muy eficientes y cómodos.

![Circular Array](https://1.bp.blogspot.com/-CVGL_rXjkEI/XiwJ-NQls4I/AAAAAAAAAas/xznbOX1xJRsSr56pb_iSoN4nul0Lmp3EwCLcBGAsYHQ/s1600/circularqueues123.png)

## COMPLEJIDAD
***

|    Métodos    | Complejidad de tiempo | 
|:-------------:|:---------------------:|
| `push_front`  |         O(1)          |                
|  `push_back`  |         O(1)          |                   
|  `pop_front`  |         O(1)          |                   
|  `pop_back `  |         O(1)          |                   
|   `insert `   |         O(k)          |                   
|  `is_empty `  |         O(1)          |                   
|   `clear `    |         O(1)          |                   
|   `resize `   |         O(n)          |                   
|   `sort  `    |  O(nlogn) (mergeSort)  |                   
| `reverse  `   |         O(n)          |       


## COMENTARIOS ADICIONALES
***

- Se implementaron todos los métodos, y el método `sort` se complementó con la librería `algorithm`, aunque se podría implementar nuestro propio método.
- Para ejecutar el código y conocer las funcionalidades de los métodos, se utilizó `tester.h`.
- Se agregaron las complejidades de los métodos para determinar cuándo es conveniente utilizar CircularArray.
- La implementación puede aceptar tipos de datos como `int`, `float` y `char`.
-

### MEJORAS
*****

- Se podrían incluir las complejidades espaciales.
- En algunos casos, el redimensionamiento podría ser un problema.
- ¡GENIAL...!!!!

# STACK
******

- Con los métodos heredados de CircularArray, se implementó el Stack.
- Sigue el principio de "último en entrar, primero en salir" (LIFO).

![Stack](https://media.geeksforgeeks.org/wp-content/cdn-uploads/20230726165552/Stack-Data-Structure.png)

# QUEUE
******

- Con los métodos heredados de CircularArray, se implementó el Queue.
- Sigue el principio de "primero en entrar, primero en salir" (FIFO).
