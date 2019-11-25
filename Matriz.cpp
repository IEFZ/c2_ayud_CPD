#include "Matriz.h"
#include <string>
Matriz::Matriz() {
    for (int i = 0; i < LARGO; i++) {
        for (int j = 0; j < LARGO; j++) {
            // Inicializamos con valores que no sean cuadrados mágicos
            this->matriz[i][j] = (i * j);
	    this->matriz0[i][j] = (i * j);
        }
    }
}


Matriz::Matriz(const std::string& orig) {
    try {
        Matriz();
        std::string linea(orig.c_str());
	std::string linea2(orig.c_str());
        if (!linea.empty()) {
	    
            // Quitamos caracters innecesarios
            linea.erase(std::remove(linea.begin(), linea.end(), '['), linea.end());
            linea.erase(std::remove(linea.begin(), linea.end(), ']'), linea.end());

            // Obtenemos un token
            std::replace(linea.begin(), linea.end(), ';', ' ');

            std::vector<std::string> arreglo;
            std::stringstream ss(linea);
            std::string temp;
            while (ss >> temp) {
                arreglo.push_back(temp);
            }

            for (int i = 0; i < LARGO; i++) {
                std::string fila = arreglo[i];
                std::replace(fila.begin(), fila.end(), ',', ' ');

                std::vector<std::string> columnas;
                std::stringstream sf(fila);
                std::string tmp;
                while (sf >> tmp) {
                    columnas.push_back(tmp);
                }

                for (int j = 0; j < LARGO; j++) {
                    std::string valor = columnas[j];
                    int numero = atoi(valor.c_str());
                    this->matriz[i][j] = numero;
                }
            }
        ///////////////////////
	
        }
	if (!linea.empty()) {
	    std::size_t pos = linea.find(':');      // posicion de ':' en str
  	    std::string linea2 = linea.substr (pos);     // obtener desde ':' hasta el final de linea 
            // Quitamos caracters innecesarios
	    linea2.erase(std::remove(linea2.begin(), linea2.end(), ':'), linea2.end());
            linea2.erase(std::remove(linea2.begin(), linea2.end(), '['), linea2.end());
            linea2.erase(std::remove(linea2.begin(), linea2.end(), ']'), linea2.end());
	    

            // Obtenemos un token
            std::replace(linea2.begin(), linea2.end(), ';', ' ');

            std::vector<std::string> arregloo;
            std::stringstream sss(linea2);
            std::string tempp;
            while (sss >> tempp) {
                arregloo.push_back(tempp);
            }

            for (int i = 0; i < LARGO; i++) {
                std::string filaa = arregloo[i];
                std::replace(filaa.begin(), filaa.end(), ',', ' ');

                std::vector<std::string> columnass;
                std::stringstream sff(filaa);
                std::string tmpp;
                while (sff >> tmpp) {
                    columnass.push_back(tmpp);
                }

                for (int j = 0; j < LARGO; j++) {
                    std::string valorr = columnass[j];
                    int numeroo = atoi(valorr.c_str());
                    this->matriz0[i][j] = numeroo;
                }
            }
        ///////////////////////
	
        }
	
    } catch (...) {
        Matriz();
    }
}

Matriz::Matriz(const Matriz& orig) {
    for (int i = 0; i < LARGO; i++) {
        for (int j = 0; j < LARGO; j++) {
            this->matriz[i][j] = orig.matriz[i][j];
        }
    }
    for (int i = 0; i < LARGO; i++) {
        for (int j = 0; j < LARGO; j++) {
            this->matriz0[i][j] = orig.matriz0[i][j];
        }
    }
}

Matriz::~Matriz() {
}




void Matriz::multiplicar() {
    
   
    matriz_mult[0][0] = ((this->matriz[0][0] * this->matriz0[0][0])+(this->matriz[0][1] * this->matriz0[1][0])+ (this->matriz[0][2] * this->matriz0[2][0]));
    matriz_mult[0][1] = ((this->matriz[0][0] * this->matriz0[0][1])+(this->matriz[0][1] * this->matriz0[1][1])+ (this->matriz[0][2] * this->matriz0[2][1]));
    matriz_mult[0][2] = ((this->matriz[0][0] * this->matriz0[0][2])+(this->matriz[0][1] * this->matriz0[1][2])+ (this->matriz[0][2] * this->matriz0[2][2]));
    matriz_mult[1][0] = ((this->matriz[1][0] * this->matriz0[0][0])+(this->matriz[1][1] * this->matriz0[1][0])+ (this->matriz[1][2] * this->matriz0[2][0]));
    matriz_mult[1][1] = ((this->matriz[1][0] * this->matriz0[0][1])+(this->matriz[1][1] * this->matriz0[1][1])+ (this->matriz[1][2] * this->matriz0[2][1]));
    matriz_mult[1][2] = ((this->matriz[1][0] * this->matriz0[0][2])+(this->matriz[1][1] * this->matriz0[1][2])+ (this->matriz[1][2] * this->matriz0[2][2]));
    matriz_mult[2][0] = ((this->matriz[2][0] * this->matriz0[0][0])+(this->matriz[2][1] * this->matriz0[1][0])+ (this->matriz[2][2] * this->matriz0[2][0]));
    matriz_mult[2][1] = ((this->matriz[2][0] * this->matriz0[0][1])+(this->matriz[2][1] * this->matriz0[1][1])+ (this->matriz[2][2] * this->matriz0[2][1]));
    matriz_mult[2][2] = ((this->matriz[2][0] * this->matriz0[0][2])+(this->matriz[2][1] * this->matriz0[1][2])+ (this->matriz[2][2] * this->matriz0[2][2]));
   
}

std::string Matriz::toString() {
    std::stringstream ss;
    ss << '[' << this->matriz_mult[0][0] << ',' << this->matriz_mult[0][1] << ',' << this->matriz_mult[0][2] << ';' << this->matriz_mult[1][0] << ',' << matriz_mult[1][1] << ',' << this->matriz_mult[1][2] << ';' << this->matriz_mult[2][0] << ',' << this->matriz_mult[2][1] << ',' << this->matriz_mult[2][2] << ']' << std::endl;
    return ss.str();
}
