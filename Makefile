CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# Названия целей
CLIENT = client
SERVER = server

# Исходные файлы для каждой программы
CLIENT_SRCS = client.c
SERVER_SRCS = server.c

# Объектные файлы для каждой программы
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

# Правило для компиляции объектных файлов без заголовочных файлов
%.o: %.c Makefile
	$(CC) $(CFLAGS) -c $< -o $@

# Цель по умолчанию
all: $(CLIENT) $(SERVER)

# Сборка клиента
$(CLIENT): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) -o $(CLIENT)

# Сборка сервера
$(SERVER): $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) -o $(SERVER)

# Чистка
clean:
	$(RM) $(CLIENT_OBJS) $(SERVER_OBJS)

# Полная чистка
fclean: clean
	$(RM) $(CLIENT) $(SERVER)

# Пересборка
re: fclean all

.PHONY: all clean fclean re