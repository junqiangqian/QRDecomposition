qr: QR.o Vector.o Matrix.o input_output.o QRHelper.o
	g++ -o qr Vector.o Matrix.o input_output.o QRHelper.o QR.o

Vector.o: Vector.cpp
	g++ -c Vector.cpp

Matrix.o: Matrix.cpp
	g++ -c Matrix.cpp

input_output.o: input_output.cpp
	g++ -c input_output.cpp

QRHelper.o: QRHelper.cpp
	g++ -c QRHelper.cpp

QR.o: QR.cpp
	g++ -c QR.cpp

clean:
	rm -rf qr *.o results.txt

.PHONY: clean
