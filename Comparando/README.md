# Comparación de implementación del algoritmo de Gauss-Jordan en C++ y Python
## Alan Poisot Palacios

Se implementó el algoritmo de Gauss-Jordan C++ y Python (Sin usar librerías y también usando Numpy).

Para comparar el rendimiento en los distintos lenguajes, los programas generaban una matriz aleatoria con números flotantes con valores entre -100 y 100. 
Posteriormente se cronometró el tiempo que tardaba en ejecutarse el algoritmo en cuestión usando las librerías `chrono` para C++ y `time` para python.

Posteriormente los datos obtenidos se tabularon y se obtuvieron dos gráficas:

En la primer gráfica se puede observar que el uso de la librería `Numpy` casi no afecta el rendimiento del script de Python, aunque sí lo hace ligeramente más lento que sin usar ninguna librería.
Adicionalmente, se puede ver que el programa escrito en C++ es mucho más rápido, pues parece una línea horizontal cercana al cero.

![Gráfica1](/Comparando/GJ1.png)

Sin embargo, sería incorrecto pensar que el programa escrito en C++ tiene un tiempo constante, pues es sabido que el algoritmo de Gauss-Jordan [tiene una complejidad O(n<sup>2</sup>)](http://fourier.eng.hmc.edu/e176/lectures/ch0/node5.html). Esto se vuelve evidente si se usa un facet_wrap para separar las gráficas de cada lenguaje y dejar libre la escala en el eje y, con lo cual se puede ver que todas las implementaciones efectivamente crecen de forma cúbica:

![Gráfica2](/Comparando/GJ2.png)
