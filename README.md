# Minishell in C++ | Minishell en C++

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)
![State](https://img.shields.io/badge/State-In_Development-brightgreen?style=for-the-badge)

**[EN]** A minimalist command-line interpreter (shell) built from scratch in C++ for Linux environments. This project is a low-level exploration of how software interacts with the operating system through POSIX system calls.

**[ES]** Un intérprete de comandos (shell) minimalista construido desde cero en C++ para entornos Linux. Este proyecto es una exploración a bajo nivel de cómo interactúa el software con el sistema operativo a través de llamadas al sistema POSIX.

## Current Status | Estado Actual (Day 1 / Día 1)

**[EN]** The main engine of the terminal is built. Currently, the minishell is capable of:
* Maintaining an infinite loop (REPL) without closing, waiting for instructions.
* Capturing full text strings entered by the user.
* **Argument Parsing:** Dynamically separating the main command from its arguments.
* **POSIX Adaptation:** Transforming modern C++ structures (`std::vector<std::string>`) into raw memory pointers (`char**`) compatible with the Linux kernel and terminated by `nullptr`.

**[ES]** El motor principal de la terminal ya está construido. Actualmente, la minishell es capaz de:
* Mantener un ciclo infinito (REPL) sin cerrarse, esperando instrucciones.
* Capturar cadenas completas de texto ingresadas por el usuario.
* **Parseo de argumentos:** Separar el comando principal de sus argumentos de forma dinámica.
* **Adaptación a POSIX:** Transformar estructuras modernas de C++ (`std::vector<std::string>`) en punteros de memoria cruda (`char**`) compatibles con el núcleo de Linux y terminados en `nullptr`.

## How to compile and test | Cómo compilar y probar

**[EN]** If you are in a Linux environment (like Fedora, Mint or Debian), you can compile this project using GCC:
**[ES]** Si estás en un entorno Linux (como Fedora, Mint o Debian), puedes compilar este proyecto usando GCC:

1. Clone this repository | Clona este repositorio:
```bash
git clone https://github.com/Josearturo9034/minishell.git
cd minishell
```

2. Compile the source code | Compila el código fuente:
```bash
g++ main.cpp -o minishell
```

3. Run the shell | Ejecuta la terminal:
```bash
./minishell
```

*> [EN] To exit the terminal, simply type `exit`.*
*> [ES] Para salir de la terminal, simplemente escribe `exit`.*

## Roadmap | Hoja de Ruta (Next steps / Próximos pasos)

**[EN]**
- [ ] Implement child process creation using `fork()`.
- [ ] Execute system binaries (like `ls`, `nmap`, or `python`) using `execvp()`.
- [ ] Control process synchronization with `waitpid()`.
- [ ] Develop built-in commands like `cd` using `chdir()`.

**[ES]**
- [ ] Implementar la creación de procesos hijos usando `fork()`.
- [ ] Ejecutar binarios del sistema (como `ls`, `nmap` o `python`) usando `execvp()`.
- [ ] Controlar la sincronización de procesos con `waitpid()`.
- [ ] Desarrollar comandos integrados (built-ins) como `cd` utilizando `chdir()`.

---
*Developed to explore operating system design and memory management.*
*Desarrollado para explorar el diseño de sistemas operativos y la gestión de memoria.*
