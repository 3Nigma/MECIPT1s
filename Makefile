PROJ_NAME     = mecipt1s

BIN_DIR       = bin
MSRC_DIR      = src
TSRC_DIR      = tst
OBJ_DIR       = obj

MSRCS_CXX     = $(MSRC_DIR)/instructie.cpp \
                $(MSRC_DIR)/main.cpp \
                $(MSRC_DIR)/memorie.cpp \
                $(MSRC_DIR)/mecipt1.cpp
MOBJS         = $(OBJ_DIR)/instructie.o \
                $(OBJ_DIR)/memorie.o \
                $(OBJ_DIR)/mecipt1.o \
                $(OBJ_DIR)/instrexcept.o
TSRCS_CXX     = $(TSRC_DIR)/main.cpp \
                $(TSRC_DIR)/testmemorie.cpp
TOBJS         = $(OBJ_DIR)/testmemorie.o
CXX           = g++
LDFLAGS       = -std=c++0x -ldl -lcppunit 

all: $(PROJ_NAME)

$(PROJ_NAME): $(MOBJS) $(OBJ_DIR)/mmain.o
	@echo "Compilez mecipt1s ..."
	$(CXX) $(LDFLAGS) $^ -o $(BIN_DIR)/$@

$(OBJ_DIR)/instructie.o: $(MSRC_DIR)/instructie.cpp $(MSRC_DIR)/instructie.hpp
	$(CXX) $(LDFLAGS) -c $< -o $@
	
$(OBJ_DIR)/mecipt1.o: $(MSRC_DIR)/mecipt1.cpp $(MSRC_DIR)/mecipt1.hpp
	$(CXX) $(LDFLAGS) -c $< -o $@
	
$(OBJ_DIR)/memorie.o: $(MSRC_DIR)/memorie.cpp $(MSRC_DIR)/memorie.hpp
	$(CXX) $(LDFLAGS) -c $< -o $@

$(OBJ_DIR)/instrexcept.o: $(MSRC_DIR)/instrexcept.cpp $(MSRC_DIR)/instrexcept.hpp
	$(CXX) -c $< -o $@

$(OBJ_DIR)/mmain.o: $(MSRC_DIR)/main.cpp
	$(CXX) $(LDFLAGS) -c $< -o $@

.PHONY: tests
tests:  $(MOBJS) $(TOBJS) $(OBJ_DIR)/tmain.o
	@echo "Compilez testele cppunit ..."
	$(CXX) $(LDFLAGS) $^ -o $(TSRC_DIR)/eval
	
$(OBJ_DIR)/testmemorie.o: $(TSRC_DIR)/testmemorie.cpp
	$(CXX) $(LDFLAGS) -c $< -o $@

$(OBJ_DIR)/tmain.o: $(TSRC_DIR)/main.cpp
	$(CXX) $(LDFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJ_DIR)/*.o
