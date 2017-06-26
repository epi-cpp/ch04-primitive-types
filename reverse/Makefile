CXX=clang++-3.5
CXXFLAGS=-g
TGT = reverse_int

all: $(TGT)

$(TGT): $(TGT).cc
	$(CXX) $^ $(LOADLIBS) $(LDLIBS) -o $@

clean:
	@rm $(TGT)
