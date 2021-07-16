SERVER = server
 
CLIENT = client
 
LIBFT = ./libft/libft.a
 
CC = gcc
 
CFLAGS = -Wall -Wextra -Werror
 
 
all : $(SERVER) $(CLIENT)


$(SERVER) : server.o utils.o minitalk.h
	@$(CC) server.o utils.o -o $@

$(CLIENT) : client.o utils.o minitalk.h
	@$(CC) client.o utils.o -o $@

%.o : %.c *.h
	@$(CC) $(FLAGS) -c $<
 
clean :
	rm -rf client.o server.o utils.o

fclean : clean
	rm -rf $(SERVER) $(CLIENT)

re : fclean all