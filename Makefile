all:
	"g++" ".\src\main.cpp" ".\src\hylia\init.cpp" ".\src\hylia\cpu\fetchdecode.cpp" ".\src\hylia\cpu\execute.cpp" -o ".\bin\hyliaDEV"