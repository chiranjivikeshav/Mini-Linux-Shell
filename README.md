# Mini-Linux-Shell
A Unix-style mini shell implemented in C++ that supports complex command parsing and execution using an AST-based architecture.
# Featured Implemented
- Execution of external commands using fork, execvp, and waitpid.
- Abstract Syntax Tree (AST) – based parsing for complex command structures.
- Logical operators:
  - && (AND)
  - || (OR)
- Sequence - ;
- Pipelines using - |
- Input/output/error redirections:
  - <, >, >>, 2>
- Subshell support using parentheses ( ... ) with correct scope isolation.
- Built-in commands like cd, exit, etc.
- Accurate exit-status propagation enabling correct short-circuit logic.
- Parent/child process separation for built-ins and subshells.
# Tech Stack
- Language: C++
- Build System: Cmake
- Platform (OS): Linux/WSL
# Build Instructions
  > 1. *mkdir build*
  > 2. *cd build*
  > 3. *cmake ..*
  > 4. *make*
  > 5. *./minishell*
### Note: While testing commands, make sure put white space between each consecutive tokens. For example (ls) → ( ls ).