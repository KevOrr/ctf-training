image: epa.c Dockerfile
	docker build -t epa .

epa: epa.c
	gcc -O1 -m32 epa.c -o epa

.PHONY: image
