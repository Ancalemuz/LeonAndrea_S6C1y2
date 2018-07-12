#hello.mk
#$ touch *.dat
plot.py : dat.txt
	python plot.py
dat.txt : LeonAndrea_S6C1y2.cpp
	g++ LeonAndrea_S6C1y2.cpp
	./a.out LeonAndrea_S6C1y2.cpp > dat.txt

