#include <iostream>
#include <string>
#include <vector>
#include <sstream>

int main(){
    std::string entrada;

    while (true){
        std::cout << "minishell> ";
        
        if (!std::getline(std::cin, entrada)){
            break;
        }

        if (entrada.empty()){
            continue;
        }

        if (entrada == "exit" || entrada == "Exit"){
            std::cout << "Cerrando minishell...\n";
            break;
        }

        std::vector<std::string> argumentos;
        std::stringstream ss(entrada);
        std::string palabra;

        while(ss >> palabra){
            argumentos.push_back(palabra);
        }

        if (argumentos.empty()) {
            continue;
        }
        // ----------------------------------------

        std::vector<char*> c_argumentos;
        for (size_t i = 0; i < argumentos.size(); i++){
            c_argumentos.push_back(const_cast<char*>(argumentos[i].c_str()));
        }
        c_argumentos.push_back(nullptr);

        std::cout << "Comando Detectado: " << c_argumentos[0] << "\n";
        std::cout << "Numero de Argumentos: " << argumentos.size() << "\n\n";
    }

    return 0;
}
