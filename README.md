INSTRUCCIONES PARA LA SIMULACIÓN Y CONTROL DE LOS ELEMENTOS DE UNA CALLE DE LA SUBESTACIÓN LA FARGA PARA RED ELÉCTRICA DE ESPAÑA:

Los elementos que contiene este repositorio son los siguientes:

- models1: contiene todos los modelos de las piezas de la calle de la subestación. Son las piezas relacionadas con los soportes y aparamenta

- models2: más elementos de la calle de la subestación, además de modelos a medida del asfalto de la calle y posibles zonas de almacenamiento de los soportes y pórticos

- models3: contiene exclusivamente el modelo de tower_crane, grúa principal encargada de mover los elementos de una zona a otra de la calle de la subestación

- models4: resto de los elementos, así como el modelo del suelo (césped), y el sistema robótico a utilizar

- husky_and_arm: modelo general del sistema robótico. Debe ir en el mismo directorio que el resto de modelos.

- husky_sdf_description: paquete para arrancar todos los elementos en gazebo, se describirá más adelante.

Todos estos modelos deben en una misma carpeta. Puede ser la carpeta en la que se almacenan los modelos por defecto en gazebo (~/.gazebo/models/) o bien otra carpeta cualquiera. En este último caso habrá que indicarle a Gazebo que mire también en esa carpeta para buscar los modelos. Esto se consigue escribiendo:

	export GAZEBO_MODEL_PATH=/ruta/a_mi/carpeta_de/modelos:$GAZEBO_MODEL_PATH
	(ejemplo: export GAZEBO_MODEL_PATH=/home/juan/.gazebo/modelos_REE:$GAZEBO_MODEL_PATH)

La segunda opción es la preferible.

Paquete husky_sdf_description: formada por las siguientes carpetas:

- HUSKY: No hacer caso a esta carpeta. Eliminar si se desea.

- launch: contiene el .launch desde el que ejecutar toda la subestación. Es importante que el usuario cambie todas aquellas sentencias en las que ponga /home/juan/.gazebo/models... por el nombre correspondiente del usuario:

	/home/juan/.gazebo/models.. --> /home/fulanito/.gazebo/models...

Esto solo es así si el usuario ha incluido los modelos en ~/.gazebo/models/ como se ha indicado más arriba.

- src: archivo para mover el husky de forma completamente autónoma. No modificar

- worlds: archivo que contiene información relativa al entorno. No modificar

- CMakeLists.txt y package.xml: no modificar

Para simulación:

- abrir terminal y ejectar roscore

- abrir otra terminal y añadir las sentencias source correspondientes o bien añadirlas en el .bashrc

- ejecutar en esa terminal:

roslaunch husky_sdf_description husky.launch

NOTA: Dependiendo de las prestaciones del ordenador, la simulación puede que no se termine de ejecutar debido a los recursos necesarios para ella. En ese caso, comentar en el .launch lo elementos necesarios para que haya menos y así poderse ejecutar).

PROBLEMAS ENCONTRADOS:

- Por alguna extraña razón que desconozco, el sistema robótico me da error y no se termina de ejecutar, tengo que comentarlo en el .launch. Tiene que ser problema de algún modelo o de algún paquete que me hace falta.
