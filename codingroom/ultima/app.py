import matplotlib
import matplotlib.pyplot as plt

#Generamos una grafica lineal para una recta en X
plt.plot([100,1000,10000,100000,1000000],[4, 11, 60, 577, 6686], label='Inocente')
#Generamos otra grafica lineal para una X cuadratica
plt.plot([100,1000,10000,100000,1000000],[8, 11, 23, 142, 1423], label='BoyerMoore')
#Generamos una grafica lineas para una X Cubica
#Agregamos las etiquetas y añadimos una leyenda.
plt.xlabel('cantidad (n)')
plt.ylabel('tiempo (ms)')
plt.title("Grafica de tiempo")
plt.legend()
plt.yscale('log')
plt.savefig('grafica_lineal.png')
plt.show()