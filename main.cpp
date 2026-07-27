#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    std::string input;

    while (true) {
        std::cout << "minishell> ";
        
        if (!std::getline(std::cin, input)) { break; }
        if (input.empty()) { continue; }
        if (input == "exit" || input == "Exit") {
            std::cout << "Closing minishell...\n";
            break;
        }

        std::vector<std::string> arguments;
        std::stringstream ss(input);
        std::string word;

        while(ss >> word) { arguments.push_back(word); }
        if (arguments.empty()) { continue; }

        std::vector<char*> c_arguments;
        for (size_t i = 0; i < arguments.size(); i++) {
            c_arguments.push_back(const_cast<char*>(arguments[i].c_str()));
        }
        c_arguments.push_back(nullptr);

        pid_t pid = fork();

        if (pid < 0) {
            std::cerr << "Error: Failed to create child process.\n";
        } 
        else if (pid == 0) {
            execvp(c_arguments[0], c_arguments.data());
            
            std::cerr << "minishell: command not found\n";
            exit(1);
        } 
        else {
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}
