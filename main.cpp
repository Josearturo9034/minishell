#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unistd.h>
#include <sys/wait.h>

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


        std::vector<char*> c_argumentos;
        for (size_t i = 0; i < argumentos.size(); i++){
            c_argumentos.push_back(const_cast<char*>(argumentos[i].c_str()));
        }
        c_argumentos.push_back(nullptr);

        pid_t pid = fork();
		if (pid < 0){
			std::cerr << "Error: no se pudo crear el proceso hijo.\n";
			exit(1);
		}
		else if(pid == 0){
			execvp(c_argumentos[0], c_argumentos.data());

			std::cerr << "minishell: comando no encontrado\n";
			exit(1);
		}
		else {
		int estado;
		waitpid(pid, &estado, 0);
		}
    }

    return 0;
}
