# The solution constains a pdf and a cpp file 
# Makefile for Windows (PowerShell / CMD) with correct PDF opening

CXX = g++
SRC = P2.cpp
OUT = P2.exe
PDF = Hw10_ads.pdf

all: $(OUT)
	$(OUT)
	@echo Opening the PDF...
	cmd /C start "" "$(PDF)"

$(OUT): $(SRC)
	$(CXX) $(SRC) -o $(OUT)

clean:
	del /Q $(OUT)
