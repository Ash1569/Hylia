@echo Compiling Hylia
@"D:\MinGW\bin\g++" -o ".\bin\hyliaDEV" ".\src\main.cpp" ".\src\hylia\init.cpp" ".\src\hylia\cpu\fetch.cpp" ".\src\hylia\cpu\decode.cpp" ".\src\hylia\cpu\execute.cpp"
@echo Running Hylia
@cls
@.\bin\hyliaDEV
@pause