image: rage.c Dockerfile
	docker build -t rage .

rage: rage.c
	gcc -O0 -m32 rage.c \
  -Wl,-Bstatic -lcrypto -Wl,-Bdynamic -ldl -lc \
	-o rage

.PHONY: image
