# FORWARD LIST
********************


### CLASIFICACION LISTA ENLAZADAS

#### LISTA SIMPLEMENTE ENLAZADA
- Eficientes ene recorridos directos.

#### LISTA DOBLEMENTE ENLAZADAS
- Eficiente en recorridos directos y hacia atras.

#### LISTA SIMPLEMENTE ENLAZADA
- El ultimos elemento se enlaza con el primer elemento, por ello hace un recorrido circular.

#### LISTA DOBLEMENTE  ENLAZADA
- El ultimos elemento se enlaza con el primer elemento, por ello hace un recorrido circular.
- El primer elemento se enlaza con el ultimo elemento.

![forwardList]()
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