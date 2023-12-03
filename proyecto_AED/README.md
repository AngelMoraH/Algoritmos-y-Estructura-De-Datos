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
## Descripción caso planteado

Decidimos utilizar la tecnología de blockchain en el ámbito de las criptomonedas, centrándonos en Bitcoin, la criptomoneda más reconocida globalmente y aquella para la cual se creó la innovadora tecnología de blockchain.

## Importancia del blockchain en el rubro de las criptomonedas

Las criptomonedas se fundamentan por completo en la tecnología de blockchain. Sin la existencia del blockchain, las criptomonedas no podrían existir. La blockchain posibilita la validación de transacciones sin depender de una entidad central, en su lugar, se apoya en un sistema distribuido a través de una red Peer-to-Peer.

# Explicación estructuras de datos del blockchain

Las estructuras de datos implementadas por nuestra cuenta fueron las siguientes:

1. Double Linked List: Para almacenar los bloques dentro de la blockchain y guardar algunos otros datos.
2. Heaps: Para la búsqueda de máximo o mínimo.
3. Hash: Para la búsqueda exacta.

Consideraciones:

- La blockchain está compuesta de un conjunto de bloques.
- Cada bloque está compuesta por un conjunto de transacciones.
- Cada transaccion tiene sus propios atributos dependiendo del contexto.
- El primer bloque de la blockchain (el génesis) tiene asignado un código hash previo de "0".
- La información ingresada al bloque es manual.
- El algortimo de ecriptación es el sha-256, es implementado en un archivo .h.
- Al insertar las transacciones en los bloques, también se insertan sus atributos en las estructuras de datos correspondientes.
  

   ## Estrategia para asegurar integridad de su contenido

   La clase bloque tiene un método ```proof_of_work() ``` que compara si el código hash que tiene actualmente el bloque sería el mismo si se vuelve a generar el código hash (el cual toma en cuenta la información de todos los atributos de la clase bloque).

   ## Proof of Work

   El proof of work que utilizamos es que si alguien intenta agregar un bloque, primero debe encontrar un número (nonce) tal que haga que los primeros caracteres del código hash del bloque sean 0, 00, 000, 0000, 00000, según la dificultad de inserción elegida. Si se llega a encontrar ese número, recién se puede agregar el bloque a la cadena.
   ## Analisis de complejidad de los metodos del Blockchain
   
   - En la insercion de las transacciones se utiliza un doublelist para poder almacenarlas obteniendo una complejidad de O(n).  
   
   ## Tabla comparativa del Blockchain con Indices VS sin indices
   
   | Blockchain | Insert | search | 
   | --- | --- | --- |
   | Con índices | Complejidad O(n) | Complejidad O(1) |
   | Sin índices | Complejidad O(n) | Complejidad O(n) |
   ## Estructuras de datos usados para los diferentes criterios de busqueda
   
    1. Igual a X: Hash table
       - Como se hara una simple busqueda de valor optamos por este metodo por la rapidez al acceso a datos teniendo una complejidad en general de O(1).
         
        ![image](https://user-images.githubusercontent.com/82919499/205082437-35298f4e-f6dc-4f99-8433-89ae778110de.png)
       
         
    2. Maximo valor de: Heap
    3. Minimo valor de: Heap
          - Para los últimos 2 casos la estructura heap es la más indicada de todas ya que la forma del maxheap y del minheap mantienen en una raiz(root) al valor mayor y menor, respectivamente. Lo que da una complejidad de O(1).
          
         ![image](https://user-images.githubusercontent.com/82919499/205087704-611831d1-5de4-43d2-a9b7-48b9461b0719.png)

# Conclusion

   En resumen, la Blockchain es un conjunto de bloques que almacenan transacciones, garantizando la seguridad a través del algoritmo de encriptación sha-256. Durante nuestra recreación de este algoritmo, logramos enlazar los bloques utilizando una estructura de datos llamada doublelist y creamos un sistema de gestión de la blockchain mediante comandos en la terminal, brindando al usuario diversas opciones de operaciones. Además, implementamos diferentes métodos de búsqueda utilizando diversas estructuras de datos como hash y maxheap, con el objetivo de lograr la máxima eficiencia en cada caso. Sin embargo, es importante destacar que esta implementación es compleja y el tiempo de respuesta aún es de 0ms solo con un conjunto de datos reducido. A medida que el tamaño de los datos aumenta, la complejidad y el tiempo de respuesta también se incrementan.