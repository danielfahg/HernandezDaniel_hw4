#el nivel de la cabeza
Resultados_hw4.pdf:Resultados_hw4.tex GraficaProyectil45.jpg GraficaProyectilTodAng.jpg PDEcondIniCaso1.jpg PDEEstadoInt1Caso1.jpg PDEEstadoInt2Caso1.jpg PDEConEquiCaso1.jpg PDEcondIniCaso2.jpg PDEEstadoInt1Caso2.jpg PDEEstadoInt2Caso2.jpg PDEConEquiCaso2.jpg PDEcondIniCaso3.jpg PDEEstadoInt1Caso3.jpg PDEEstadoInt2Caso3.jpg PDEConEquiCaso3.jpg PDETemProTie3Casos.jpg
	pdflatex Resultados_hw4.tex
#revisar si el comando si es pdflatex Resultados_hw4.tex en http://nokyotsu.com/latex/pdflatex.html dice que si

#1 nivel abajo de la cabeza

#Resultados_hw4.tex no depende de otro archivo

GraficaProyectil45.jpg:Plots_hw4.py PosVelTie45.txt
	python Plots_hw4.py
   
GraficaProyectilTodAng.jpg:Plots_hw4.py PosVelTieTodAng.txt
	python Plots_hw4.py

PDEcondIniCaso1.jpg:Plots_hw4.py PDEcondIniCaso1.txt
	python Plots_hw4.py

PDEEstadoInt1Caso1.jpg:Plots_hw4.py PDEEstadoInt1Caso1.txt
	python Plots_hw4.py

PDEEstadoInt2Caso1.jpg:Plots_hw4.py PDEEstadoInt2Caso1.txt
	 python Plots_hw4.py

PDEConEquiCaso1.jpg:Plots_hw4.py PDEConEquiCaso1.txt
	python Plots_hw4.py

PDEcondIniCaso2.jpg:Plots_hw4.py PDEcondIniCaso2.txt
	python Plots_hw4.py

PDEEstadoInt1Caso2.jpg:Plots_hw4.py PDEEstadoInt1Caso2.txt 
	python Plots_hw4.py

PDEEstadoInt2Caso2.jpg:Plots_hw4.py PDEEstadoInt2Caso2.txt
	python Plots_hw4.py

PDEConEquiCaso2.jpg:Plots_hw4.py PDEConEquiCaso2.txt 
	python Plots_hw4.py

PDEcondIniCaso3.jpg:Plots_hw4.py PDEcondIniCaso3.txt
	python Plots_hw4.py

PDEEstadoInt1Caso3.jpg:Plots_hw4.py PDEEstadoInt1Caso3.txt
	python Plots_hw4.py

PDEEstadoInt2Caso3.jpg:Plots_hw4.py PDEEstadoInt2Caso3.txt 
	python Plots_hw4.py

PDEConEquiCaso3.jpg:Plots_hw4.py PDEConEquiCaso3.txt
	python Plots_hw4.py

PDETemProTie3Casos.jpg:Plots_hw4.py PDETemProTie3Casos.txt 
	python Plots_hw4.py

#2 niveles abajo de la cabeza

#Plots_hw4.py no depende de otro archivo

PosVelTie45.txt:EjecutableDeODE
	./EjecutableDeODE

PosVelTieTodAng.txt:EjecutableDeODE
	./EjecutableDeODE

PDEcondIniCaso1.txt:EjecutableDePDE
	./EjecutableDePDE

PDEEstadoInt1Caso1.txt:EjecutableDePDE
	./EjecutableDePDE

PDEEstadoInt2Caso1.txt:EjecutableDePDE
	./EjecutableDePDE

PDEConEquiCaso1.txt:EjecutableDePDE
	./EjecutableDePDE

PDEcondIniCaso2.txt:EjecutableDePDE	
	./EjecutableDePDE

PDEEstadoInt1Caso2.txt:EjecutableDePDE
	./EjecutableDePDE

PDEEstadoInt2Caso2.txt:EjecutableDePDE
	./EjecutableDePDE

PDEConEquiCaso2.txt:EjecutableDePDE
	./EjecutableDePDE

PDEcondIniCaso3.txt:EjecutableDePDE
	./EjecutableDePDE

PDEEstadoInt1Caso3.txt:EjecutableDePDE
	./EjecutableDePDE

PDEEstadoInt2Caso3.txt:EjecutableDePDE
	./EjecutableDePDE

PDEConEquiCaso3.txt:EjecutableDePDE
	./EjecutableDePDE

PDETemProTie3Casos.txt:EjecutableDePDE
	./EjecutableDePDE

#3 niveles abajo de la cabeza

EjecutableDeODE:ODE.cpp
	g++ ODE.cpp -o EjecutableDeODE 

EjecutableDePDE:PDE.cpp
	g++ PDE.cpp -o EjecutableDePDE

#4 niveles abajo de la cabeza

#ODE.cpp no depende de otro archivo

#PDE.cpp no depende de otro archivo

 






#el comando de la terminal va a ser g++ ODE.cpp -o EjecutableDeODE		









 



	 






	 
