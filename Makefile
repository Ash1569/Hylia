objects := $(patsubst %.cpp,%.o,$(shell find src/ -type f -name '*.cpp'))

all: out/hyliaDEV

clean:
	rm -f $(objects)
	rm -rf out/

out/hyliaDEV: $(objects)
	mkdir -p out/
	$(CXX) -o $@ $(CPPFLAGS) $(CXXFLAGS) $(objects)
