CXX=g++
OBJS = bmp_ns.o datatypes.o main.o
TARGET=main
$(TARGET): $(OBJS)
	$(CXX) -o $@ $(OBJS)
%.o: %.c
	$(CXX) -c $< -o $@
