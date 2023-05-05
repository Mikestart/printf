// int	ft_printf(const char *str, ...)
// {
// 	int		i;
// 	va_list args;

// 	va_start(args, str);

// 	va_arg(args, int);
// 	i = 0;

// 	va_end(args);
// }

// void	print_c(int nb, ...)
// {
// 	va_list	args;
// 	int		i;
// 	char	c;

// 	i = 0;
// 	va_start(args, nb);
// 	while (i < nb)
// 	{
// 		c = va_arg(args, int);
// 		printf("%c ", c);
// 		i++;
// 	}
// 	printf("\n");
// 	va_end(args);
// }
// void ft_print_str(char* str)
// {
// 	int	i;
// 	i = 0;

// 	while (str[i])
// 	{
// 		write(1, &str[i], 1);
// 		i++;
// 	}
// }
