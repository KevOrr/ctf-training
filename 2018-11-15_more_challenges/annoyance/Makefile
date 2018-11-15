image: annoyance.c Dockerfile
	docker build -t annoyance .

annoyance: annoyance.c
	gcc -O0 -m32 annoyance.c -o annoyance

.PHONY: image
