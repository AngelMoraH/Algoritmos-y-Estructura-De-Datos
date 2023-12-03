[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/XlowQkA5)
# Proyecto de Algoritmos y Estructuras de Datos

## Integrantes:
- Diego Rivadeneyra
- Sebastian Chu
- Sergio Cortez
- Angel Mora
- Angel Mucha

# BlockChain Proyect
# Introducción
En el ámbito de la programación y la seguridad de datos, el desarrollo de aplicaciones transaccionales ha sido un área de interés constante y evolución. En la actualidad, el concepto de blockchain ha ganado prominencia como una solución innovadora para garantizar la seguridad, integridad y transparencia en las transacciones de datos. La implementación de una estructura de datos de cadena de bloques en un solo host ofrece un enfoque fascinante para construir aplicaciones transaccionales robustas.

El objetivo de este trabajo de investigación es explorar el desarrollo de una aplicación transaccional que utilice una estructura de datos de cadena de bloques en un solo host como base de seguridad. A través de esta metodología, se busca proporcionar un ambiente confiable para la interacción de datos, donde la integridad y la confidencialidad estén garantizadas.

En este estudio, se examinarán los fundamentos de la cadena de bloques, incluyendo sus conceptos clave, como los bloques, los hashes criptográficos y la descentralización. Se analizarán las ventajas y desafíos de implementar una cadena de bloques en un solo host, considerando aspectos como la escalabilidad, la seguridad y la eficiencia en comparación con las implementaciones tradicionales de blockchain.

Además, se explorarán diferentes enfoques y técnicas de programación para desarrollar una aplicación transaccional utilizando esta estructura de datos. Se abordarán aspectos como la creación y validación de bloques, la gestión de transacciones y la seguridad de los datos almacenados en la cadena de bloques.

A lo largo de este trabajo, se examinarán casos de uso relevantes para esta aplicación transaccional basada en una estructura de datos de cadena de bloques en un solo host, considerando áreas como la gestión de activos digitales, la trazabilidad de productos y la autenticación de usuarios.

Finalmente, se analizarán las perspectivas futuras de este enfoque de desarrollo y su potencial para impulsar la innovación en la interacción de datos y la seguridad. Este estudio servirá como base para futuras investigaciones y como guía práctica para aquellos interesados en utilizar una estructura de datos de cadena de bloques en un solo host para desarrollar aplicaciones transaccionales seguras y eficientes.

![image](https://redclara.net/images/blockchain-lacnet-article.png)

## Descripción caso planteado

Decidimos utilizar la tecnología de blockchain en el ámbito de las criptomonedas, centrándonos en Bitcoin, la criptomoneda más reconocida globalmente y aquella para la cual se creó la innovadora tecnología de blockchain.

## Importancia del blockchain en el rubro de las criptomonedas

Las criptomonedas se fundamentan por completo en la tecnología de blockchain. Sin la existencia del blockchain, las criptomonedas no podrían existir. La blockchain posibilita la validación de transacciones sin depender de una entidad central, en su lugar, se apoya en un sistema distribuido a través de una red Peer-to-Peer.

# Explicación estructuras de datos del blockchain

Las estructuras de datos implementadas por nuestra cuenta fueron las siguientes:

1. Foward Linked List: Esta estructura es la que nos ayuda a el enlazado de los bloques en un solo sentido.
2. Heaps: Estructura implementada para la búsqueda de máximo o mínimo.
3. Hash: Implementado para la búsqueda exacta de un valor.
4. Binary Seaarch Tree: Usamos esta estructura para obtener la busqueda por rango.
5. Trie: Busqueda de valores de tipo string en nuestras transacciones.

Consideraciones:

- La blockchain es un conjunto de bloques compuesto por un conjunto de transacciones.
- Las trasacciones tienes variedad de atributos de los cuales usamos 4 de ellos para nuestra implementacion.
- El iniciar eel programa see crea un bloque primncipal llamado genesis que inicia con el index 0 y se mantiene vacio.
- El algortimo de ecriptación es el SHA-256 proporcionado por el profesor, es implementado en un archivo .h.
- Al insertar las transacciones en los bloques, también se insertan sus atributos en las estructuras de datos correspondientes.
  
   ## Proof of Work

   El Proof of work es un mecanismo de conseso para poder elegir cuales de los mineros de la red logran cumplir la tarea de   
   verificacion de datos y los mineros son rencompensados con nuevas criptomonedas.

   El proof of work que utilizamos es que si alguien intenta agregar un bloque, primero debe encontrar un número (nonce) tal que haga     que los primeros caracteres del código hash del bloque sean 0, 00, 000, 0000, 00000, según la dificultad de inserción elegida. Si      se llega a encontrar ese número, recién se puede agregar el bloque a la cadena.

  La clase bloque tiene un método ```proof_of_work() ``` que compara si el código hash que tiene actualmente el bloque sería el          mismo si se vuelve a generar el código hash (el cual toma en cuenta la información de todos los atributos de la clase bloque).
  
   ## Analisis de complejidad de los metodos del Blockchain
   
   - En la insercion de las transacciones se utiliza un doublelist para poder almacenarlas obteniendo una complejidad de O(n).  
   
   ## Tabla comparativa del Blockchain con Indices VS sin indices
   
   | Blockchain | Insert | search | 
   | --- | --- | --- |
   | Con índices | O(1)  | O(1)  |
   | Sin índices | O(n) | O(n)  |

  Con índices la insercion es O(1) pues se localiza eficientemente la posición adecuada. Sin índices en el peor de los casos recorreria linealmente la lista por lo que sería O(n). La busqueda con indices con la estructura hash permite un acceso de O(1). Sin índices tendríamos que recorrer linealmente por lo cual la complejidad es O(n).

   ## Estructuras de datos usados para los diferentes criterios de busqueda
   
    1. Igual a X: Hash table
       - La estructura de tabla hash se utiliza debido a su eficiencia y rapidez en el acceso a los datos. Al emplear una función de hash, se puede buscar rápidamente el tiempo de una transacción o su índice, con una complejidad constante de O(1). Esta estructura es especialmente ventajosa en conjuntos de datos grandes, ya que su tiempo de acceso no se ve afectado por el tamaño de los datos.
         
        ![image](https://www.tutorialspoint.com/data_structures_algorithms/images/hash_function.jpg)
         
    2. Maximo valor de y Mínimo valor de: Heap
          - La estructura heap es la más indicada de todas ya que la forma del maxheap y del minheap mantienen en una raiz(root) al valor mayor y menor, respectivamente. Esta estructura nos permite obtener el maximo y mínimo del tiempo y monto de la transacción en complejidad de O(1).
            
         ![image](https://media.geeksforgeeks.org/wp-content/cdn-uploads/20221220165711/MinHeapAndMaxHeap1.png)

    3. entre x y : BSTree
       - Como se realizará una búsqueda entre un rango delimitado por dos valores (X & Y), optamos por usar esta estructura teniendo una complejidad de O(log n) para el caso de tener un árbol balanceado y en el caso que el árbol esté desbalanceado la complejidad sería O(n).
         
        ![image](https://media.geeksforgeeks.org/wp-content/cdn-uploads/20221215114732/bst-21.png)
       
    4. Search Word: Trie
       - Se hace una busqueda de los atributos strings del bloque. Estos strings son la fecha y el open. El open es el monto con el que se abrio el blockchain ese día. Este valor fue convertido a string para poder buscarlo. En inserción la complejidad es O(N), donde n es el tamaño del string. La complejidad de busqueda es lineal, siendo O(N) y N es el tamaño del string buscado.

         ![image](https://media.geeksforgeeks.org/wp-content/uploads/20220828232752/Triedatastructure1.png)

 
# Conclusión

   Finalmente, la Blockchain es un conjunto de bloques que contiene diferentes transacciones y garantiza la seguirdad por medio del algoritmo de encriptamiento SHA-256. Luego de implementar esta estructura logramos ver que tuvimos limitaciones como el tiempo y dinero durante el proceso. Dinero para los almuerzos que no llegamos a consumir y tiempo porque lo hicimos a ultima hora y con pocas ideas sobre programación. Además, implementamos las diferentes estructuras creadas durante el ciclo que nos permitieron conseguir la mejor eficiencia para cada criterio pedido dentro del proyecto. Sin embargo, nos damos cuenta que la implementación de toda la Blockchain es más compleja y el tiempo de respuestas es de 0ms para los poco datos que hemos implementado, mientras que, una Blockchain real almacena millones de transacción y incrementan con el paso del tiempo.
   
