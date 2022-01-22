all:
	"g++" ".\src\main.cpp" ".\src\hylia\init.cpp" ".\src\hylia\cpu\fetch.cpp" ".\src\hylia\cpu\decode.cpp" ".\src\hylia\cpu\execute.cpp" -o ".\bin\hyliaDEV"