CC = g++

CFLAGS = -std=c++11

SOURCE1 = Communication/Server.cpp Communication/SocketIO.cpp Communication/StandardIO.cpp Communication/CLI.cpp \
		  Communication/ClientInfo.cpp Files/FileReader.cpp Files/FileWriter.cpp Correctness.cpp Distance/Knn.cpp \
	      Distance/Manhattan.cpp Distance/Euclidean.cpp Distance/Chebyshev.cpp Distance/Canberra.cpp Distance/Minkowski.cpp \
          Command/Server/PrintMenuServer.cpp Command/Server/UploadDataServer.cpp Command/Server/AlgorithmServer.cpp \
          Command/Server/ClassifyDataServer.cpp Command/Server/DisplayResultsServer.cpp Command/Server/DownloadResultsServer.cpp

SOURCE2 = Communication/Client.cpp Communication/SocketIO.cpp Communication/StandardIO.cpp \
		  Files/FileReader.cpp Files/FileWriter.cpp Correctness.cpp \
          Command/Client/PrintMenuClient.cpp Command/Client/UploadDataClient.cpp Command/Client/AlgorithmClient.cpp \
          Command/Client/ClassifyDataClient.cpp Command/Client/DisplayResultsClient.cpp Command/Client/DownloadResultsClient.cpp

OBJECT1 = $(SOURCE1:.cpp=.o)
OBJECT2 = $(SOURCE2:.cpp=.o)

EXECUTABLE1 = server.out
EXECUTABLE2 = client.out

all: $(EXECUTABLE1) $(EXECUTABLE2)

$(EXECUTABLE1): $(OBJECT1)
	$(CC) $(CFLAGS) $(OBJECT1) -o $(EXECUTABLE1) -pthread

$(EXECUTABLE2): $(OBJECT2)
	$(CC) $(CFLAGS) $(OBJECT2) -o $(EXECUTABLE2) -pthread

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECT1) $(OBJECT2) $(EXECUTABLE1) $(EXECUTABLE2)
