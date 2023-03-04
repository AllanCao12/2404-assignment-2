CC := g++ -Wall -g3

all: a2

a2: Date.o Photo.o PhotoArray.o Album.o AlbumArray.o PhotoGram.o Client.o TestView.o TestControl.o main.o 
	$(CC) -o a2 Date.o Photo.o PhotoArray.o Album.o AlbumArray.o PhotoGram.o Client.o TestView.o TestControl.o main.o 

Date.o: Date.cc Date.h
	$(CC) -c Date.cc

Photo.o: Photo.cc Photo.h Date.h
	$(CC) -c Photo.cc

PhotoArray.o: PhotoArray.cc PhotoArray.h Photo.h Date.h defs.h
	$(CC) -c PhotoArray.cc

Album.o: Album.cc Album.h PhotoArray.h Photo.h Date.h defs.h
	$(CC) -c Album.cc

AlbumArray.o: AlbumArray.cc AlbumArray.h Album.h PhotoArray.h Photo.h Date.h defs.h
	$(CC) -c AlbumArray.cc

PhotoGram.o: PhotoGram.cc PhotoGram.h AlbumArray.h Album.h PhotoArray.h Photo.h Date.h defs.h
	$(CC) -c PhotoGram.cc

Client.o: Client.cc Client.h PhotoGram.h AlbumArray.h Album.h PhotoArray.h Photo.h Date.h defs.h
	$(CC) -c Client.cc

TestView.o: TestView.cc TestView.h
	$(CC) -c TestView.cc

TestControl.o: TestControl.cc TestControl.h TestView.h Client.h PhotoGram.h AlbumArray.h Album.h PhotoArray.h Photo.h Date.h defs.h
	$(CC) -c TestControl.cc

main.o: main.cc TestControl.h TestView.h Client.h PhotoGram.h AlbumArray.h Album.h PhotoArray.h Photo.h Date.h defs.h
	$(CC) -c main.cc

test: a2
	valgrind --leak-check=full -s ./a2




clean:
	rm -rf a2 *.o *.bak
