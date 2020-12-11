# HUFFMAN PROJECT

Project performs compression of text file using huffman coding.
## Link

[Subject](https://docs.google.com/document/d/1OUURID_qB3oDBcD7CSMamJLHXSZrWsKi3olc_nWZEvU/edit)

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

You only need a computer and some intelectual skill. 

### Running program

A step by step series of examples that tell you how to get a development env running

Copy the text you want to encode in the input.txt file.

Then you can use the following command to launch the program : 

```
make
```
And execute using ('exec' is the default executable file, you can change it in the makefile):
```
./exec
```

If you want to clean all text files except the input.txt, use the command : 
```
make clean
```
### Performances 

#### Performed on Linux Core i5

| Characters | 143 826 | 575 312 | 1 150 622 | 2 588 884 | 9 061 095 |
| :--------: | :-----: | :-----: | :-------: | :-------: | :-------: |
| Seconds    | 1.25000 |  4.800  |  9.50000  |   20.000  |   71.000  |

![Alt text](img/graph.png?raw=true "graph")

We're constantly trying to beat these performances.

### Contributing 

Pull requests are welcome. For major changes, <br />
please open an issue first to discuss what you would like to change. <br />

### Authors

Facqueur Bastien - [bastien707](https://github.com/bastien707) <br />
Kylian Artu-Lequint - [KA-L](https://github.com/KA-L) <br />
Quentin Noiriel - [QuentinNoiriel](https://github.com/QuentinNoiriel) <br />


