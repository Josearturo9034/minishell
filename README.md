# Minishell in C++ | Minishell en C++

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)
![State](https://img.shields.io/badge/State-In_Development-brightgreen?style=for-the-badge)

**[EN]** A minimalist command-line interpreter (shell) built from scratch in C++ for Linux environments. This project is a low-level exploration of how software interacts with the operating system through POSIX system calls.

**[ES]** Un intérprete de comandos (shell) minimalista construido desde cero en C++ para entornos Linux. Este proyecto es una exploración a bajo nivel de cómo interactúa el software con el sistema operativo a través de llamadas al sistema POSIX.

## Current Status | Estado Actual (Day 2 / Día 2)

**[EN]** The main engine of the terminal is built and capable of executing system commands. Currently, the minishell features:
* Maintaining an infinite loop (REPL) without closing, waiting for instructions.
* **Argument Parsing:** Dynamically separating the main command from its arguments and transforming modern C++ structures (`std::vector`) into raw memory pointers (`char**`) compatible with the Linux kernel.
* **Process Execution:** Creating child processes with `fork()` to handle execution without crashing the main shell.
* **System Binaries:** Using `execvp()` to seamlessly run external programs like `ls`, `pwd`, or network scanners like `nmap`.
* **Synchronization:** Utilizing `waitpid()` to ensure the parent process safely waits for the child to finish before prompting the user again.

**[ES]** El motor principal de la terminal ya está construido y es capaz de ejecutar comandos del sistema. Actualmente, la minishell cuenta con:
* Mantener un ciclo infinito (REPL) sin cerrarse, esperando instrucciones.
* **Parseo de argumentos:** Separar el comando principal de forma dinámica y transformar estructuras modernas de C++ (`std::vector`) en punteros de memoria cruda (`char**`) compatibles con el núcleo de Linux.
* **Ejecución de Procesos:** Creación de procesos hijos con `fork()` para manejar la ejecución sin cerrar la terminal principal.
* **Binarios del Sistema:** Uso de `execvp()` para ejecutar limpiamente programas externos como `ls`, `pwd` o escáneres de red como `nmap`.
* **Sincronización:** Utilización de `waitpid()` para garantizar que el proceso padre espere de forma segura a que el hijo termine antes de volver a solicitar un comando.

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
