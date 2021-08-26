# Analizador Lexico

Universidad de Guadalajara 

Carrera: Ingeniería en Computación

Clase: Seminario de Traductores de Lenguajes 2

Sección: D02 

Profesor: López Franco Michel Emanuel

Alumno: Oscar Daniel Ramirez Salazar 

Código: 214448462 

La forma en que captura los identificadores es si solo tiene una letra o si tiene letras y numeros, en caso de tener mas de una letra es considerado como una cadena.

Si el identificador tiene un punto y mas caracteres se le considera como un error, tambien pasa si se quiere escribir reales con solo el punto y agregando numeros;
Para escribir un real se tiene que agregar algun numero del 0-9 seguido de un punto y mas numeros.

En el caso de los tipos de varible y las palabras reservadas se hace una comparacion de la cadena, si esta coincide con alguno de los casos antes mencionados se toma
como tipo de variable o palabra reservada, en caso de no ser ninguno se toma como cadena o identificador.

El signo de pesos "$" se toma como fin de la entrada y es señal de que ya no hay mas caracteres que analizar.

# Pruebas
![image](https://user-images.githubusercontent.com/73807285/131043481-1c31856a-cf4e-41c7-a600-ffa955510679.png)





