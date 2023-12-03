import random
import matplotlib.pyplot as plt
import time
start_time = 0
end_time = 0
def countingSort(array):
    start_time = time.time()
    size = len(array)
    output = [0] * size
    count = [0] * (max(array)+1)
    for i in range(size):
        count[array[i]] += 1
    for i in range(1, 10):
        count[i] += count[i - 1]
    i = size - 1
    while i >= 0:
        output[count[array[i]] - 1] = array[i]
        count[array[i]] -= 1
        i -= 1
    for i in range(0, size):
        array[i] = output[i]
    end_time = time.time()
    return end_time - start_time

def selectionSort(array, size):
    start_time = time.time()
    for step in range(size):
        min_idx = step
        for i in range(step + 1, size):
            if array[i] < array[min_idx]:
                min_idx = i
        (array[step], array[min_idx]) = (array[min_idx], array[step])
    end_time = time.time()
    print(end_time - start_time)
    return end_time - start_time



lista_tiempo1 = []
lista_tiempo2=[]
data1 = [random.randint(1,10) for i in range(10)]
data2 = [random.randint(1,100) for i in range(100)]
data3 = [random.randint(1,1000) for i in range(1000)]
data4 = [random.randint(1,10000) for i in range(10000)]


for i in range(4):
    array=[]
    if i == 0:
        array = data1
    elif i == 1:
        array = data2
    elif i == 2:
        array = data3
    elif i == 3:
        array = data4
    
    lista_tiempo1.append(countingSort(array))
    lista_tiempo2.append(selectionSort(array, len(array)))

fig, ax = plt.subplots()
ax.plot()
ax.plot([10,100,1000,10000],lista_tiempo1, "r",marker = "o", markersize = 5, label='counting sort')
ax.plot([10,100,1000,10000],lista_tiempo2,"b", marker = "o", markersize = 5, label='selection sort')
plt.xlabel('Cantidad de Datos')
plt.ylabel('Tiempo (s)')
plt.legend()
plt.show()