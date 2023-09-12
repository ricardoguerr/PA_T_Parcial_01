# Parcial 01

## Instrucciones

1. Para iniciar el laboratorio, debe crear un *Fork* del repositorio:

![fork button](images/fork.png)

2. Clone el nuevo repositorio en su computadora y ábralo en Visual Studio.

3. Abra el archivo **PA_T_Parcial_01.cpp** que se encuentra en el folder de **PA_T_Parcial_01** y modifíquelo para que imprima su nombre y carnet.

4. En el menú de Visual Studio, en la sección de Tests, seleccione *Run All Tests*

5. La mayoría de las pruebas deberían fallar.

### Notas

- A continuación encontrará los enunciados de cada uno de los ejercicios. Su nota en cada uno de los ejercicios será la relación entre la cantidad de pruebas que sí pasen sobre la cantidad total de pruebas para ese ejercicio.
- Puede hacer `git push` de sus commits tantas veces como quiera, pero no se calificará ningún commit hecho después del horario de curso.
- Si el código original de un ejercicio no se modifica o la intención de su resolución no es clara, la nota del ejercicicio será de 0 puntos aún si hay pruebas que sí pasen para dicho ejercicio.

## Ejercicio 1 (30 puntos)

Se considera **palíndroma** a una frase si, después de convertir todas sus letras mayúsculas en minúsculas y después de quitar todos los carácters no alfanuméricos, la frase se lee de la misma manera al derecho y al revés. Los carácteres alfanuméricos incluyen tanto letras como números.

Dado un string, `phrase`, y su longitud, `length`, retorne `true` si la frase es un palíndromo o `false` en caso contrario.

### Ejemplo 1.1

    phrase = "Roma ni se conoce sin oro, ni se conoce sin amor."
    resultado = true

**Explicación:** "romaniseconocesinoroniseconocesinamor" es un palíndromo.
___

## Ejemplo 1.2

    phrase = "race a car"
    resultado = false

**Explicación:** "raceacar" no es un palíndromo.

## Ejemplo 1.3

    phrase = " "
    resultado = true

**Explicación:** Al eliminar todos los carácteres no alfanuméricos, queda un string vacío (""). Un string vacío se lee igual al derecho y al revés.

### Restricciones

- `1 <= length <= 10`<sup>5</sup>
- `phrase` tendrá solo carácteres imprimibles.

___

### Pistas

- Puede utilizar la función `lower()` para convertir un caracter de mayúscula a minúscula.
- Utilice la [Tabla ASCII](https://www.ascii-code.com/ASCII) como referencia.

___

## Ejercicio 2 (40 puntos)

Imagine que usted es un ladrón profesional y está planeando robar casas en una calle. En cada una de las casas, hay cierta cantidad de dinero acumulado. Lo único que lo detiene de robar cada una de ellas es que las casas contiguas tienen sistemas de seguridad conectadas entre ellas. **Si dos casas contiguas son robadas en la misma noche, entonces se alertará a la policía**.

Dado un arreglo de enteros `houses` que representa la cantidad de dinero en cada una de las casas y un número `n` de casas, retorne la *cantidad máxima de dinero que puede robar esta noche **sin alertar a la policía***.

### Ejemplo 2.1

    houses = [1,2,3,1]
    resultado = 4

**Explicación:** Roba la casa 0 (dinero = **1**), luego roba la casa 2 (dinero = **3**). El total de lo que puede robar = 1 + 3 = **4**.
___

### Ejemplo 2.2

    houses = [2,7,9,3,1]
    resultado = 12

**Explicación:** Roba la casa 0 (dinero = **2**), roba la casa 2 (dinero = **9**) y roba la casa 4 (dinero = **1**). El total de lo que puede robar = 2 + 9 + 1 = **12**.
___

### Ejemplo 2.3

    houses = [2,1,1,2]
    resultado = 4

**Explicación:** Roba la casa 0 (dinero = **2**), podría robar la casa 2 (dinero = **1**) que no es contigua a la 0, pero le conviene más robar la casa 3 (dinero = **2**) que tampoco es contigua a la casa 0. El total de lo que puede robar = 2 + 2 = **4**.
___

### Restricciones

- `1 <= n <= 100`
- `0 <= nums[i] <= 400`

___

### Pistas

- La casa 0 no debe ser robada obligatoriamente.
- Si roba la casa `n` no necesariamente robará la casa `n+2` simplemente porque es la siguiente casa no contigua.
- La función `std::fill_n` puede llenar un arreglo con un valor constante por defecto. En el siguiente ejemplo, llenamos `arr` con -1:

```c++
int arr[4];
std::fill_n(arr, 4, -1);
```

___
