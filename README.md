# KNNClassifier

**files:** four folders: Command, Communication, Distance and Files. Correctness.cpp and Correctness.h.

**How to compile:** 'make all' (using the MAKEFILE) - compiles both "Server" and "Client".

Use 'make clean' to remove the compilated files and run file from the folder.

**How to run:** After writing 'make file' in the terminal, open another terminal (or more, one for each client). In the first one, which will be the server, write "./server.out port", port - the wanted port. In the others, which will be the clients, write "./client.out ip port", ip - the IP and port - the server's port. 

**What it does:**
The server is able to communicate (TCP) with several clients simultaneously (using threads). When a client connects to the server, the server sends it a welcome message and the menu with all of the options. The menu looks like this:

Welcome to the KNN Classifier Server. Please choose an option:
1. upload an unclassified csv data file
2. algorithm settings
3. classify data
4. display results
5. download results
8. exit (8 and not 6 but the README keeps changing it)

Each choice will execute the relevant command functions (more details later) in the client and server.
The main goal of this program is to upload two files - classified and unclassified and classify the unclassified file using the knn algorithm (settings can be changed).
After that, the user can see the results and even download them to a given local path.
Note that when a client exists it does not affect the server and it keeps running.

**The commands**:
For each option on the menu there are two commands - one for the client and one for the server and they communicate with one another during the whole process.
The commands for each option are:

1. UploadData - the user enters a classified file and an unclassified file - if they are both valid the client will send the data in the files to the server. The server saves them in the 'testFile' and 'trainFile' in the CLientInfo (explained in "Special implementations and design patterns") if they are valid. If the path isn't valid sends the user "invalid input" which then prints it to the screen. If the vectors in the two files aren't the same length, a message is printed to the screen saying that they aren't they same length (like the TA specified). In addition, the data uploaded is discarded.
If the vectors in one file aren't the same length or the data isn't valid we exit the program.

2. Algorithm - the current 'k' an metric are printed by the client and the user can change them. If one of the inputs by the user isn't valid, whether it's a non-natural number (or no number at all) for k or a distance metric unknown from previous exercises (has to be in CAPSLOCK), no changes will occur and the client will print the error message. The default values are 'K' = 5 and metric = AUC.

3. ClassifiyData - the server classifies the data using the train file and the 'k' and metric
settings and creates a data set containing it. 

4. DisplayResults - first of all, the server checks if the test or train file don't exist in the ClientInfo or if the data hasn't been classified yet. If so, it sends the client a message asking to upload/classify the data and the client prints it. If the data exists and was classified, the server sends the client the classified data and he prints it to the user.

5. DownloadResults - The client receives a path from the user and makes sure that it's valid. Then, the server runs the same checks as it runs in "DisplayResultsServer". If the data exists and was classified, the server sends the client the classified data and he saves it in a new file in the given path.

8. exit (8 and not 6 but the README keeps changing it) - the client exits the program, but as said in the begginning the server keeps running.

**Assumptions and Integration checks regarding the arguments:**
We made several Assumptions and integration checks for the user's input vector.

Arguments:
1. We make sure that the user receives two arguments and the server receives one.
2. If 'K' is larger than the number of rows in the file we act as if they are the same number.
3. In the classified file, an empty line will be ignored and an empty cell will be filled with the number zero. After that, if vectors in the file are not the same size,
 an error is thrown.

**Special implementations and design patterns:**
The commands were implemented with the "Command" design pattern.
ClientInfo - a class which holds the data for each user - the files and the algorithm settings ('k' and metric).
CLI - a class that manages the program and commands for a specific client. Is called in the thread the server opens for each client.
DefaultIO - a class that has two extensions: SocketIO and StandardIO. It has two main functions, "read" and "write" that are implemented differently in each extension.
SocketIO is for communicating using sockets (Server -> Client and vice versa) while StandardIO is between the user and client (cout, cin).

**Optimizations:**
We decided to save the vectors from the file in a map so that each vector will be inserted in to the 'map dataset' on time only and there won't be any duplicates.
Furthermore, we created a map called 'kDataset' which will save the KNN by sorting them by their distance from the input vector as it sorts by values automatically.
By doing that, we save memory - since we only need the 'kDataset' size to be K as we erase the K+1 element (sorted by distance) each iteration, 
and time - since the map sorts itself and its size is only K instead of sorting all of the vectors in the file.
Furthermore, the downloading of the results file occurs in a different thread so during the downloading the user can perform other options from the menu.
