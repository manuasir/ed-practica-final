SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c --std=c++11


all:$ $(BIN)/prueba_Ontologias_PreguntasED

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Compilación de módulos ************

$(BIN)/prueba_Ontologias_PreguntasED: $(OBJ)/prueba_Ontologias_PreguntasED.o
	$(CXX) -o $(BIN)/prueba_Ontologias_PreguntasED $(OBJ)/prueba_Ontologias_PreguntasED.o

$(OBJ)/prueba_Ontologias_PreguntasED.o: $(SRC)/prueba_Ontologias_PreguntasED.cpp $(INC)/Ontologias.h $(INC)/ArbolGeneral.h
	$(CXX) $(CPPFLAGS)  $(SRC)/prueba_Ontologias_PreguntasED.cpp -o  $(OBJ)/prueba_Ontologias_PreguntasED.o

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
