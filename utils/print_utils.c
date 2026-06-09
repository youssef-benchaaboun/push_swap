#include "../push_swap.h"

int	ft_print_number(int nb)
{
	long	n;
	char	c;
	int		re;

	n = nb;
	re = 0;
	if (n < 0)
	{
		n = -1 * n;
		re += write(2, "-", 1);
	}
	if (n > 9)
		re += ft_print_number(n / 10);
	c = n % 10 + '0';
	re += write(2, &c, 1);
	return (re);
}

int	ft_print_string(char *s)
{
	return (write(2, s, ft_strlen(s)));
}

int	ft_print(char c, va_list *ar)
{
	if (c == 'd')
		return (ft_print_number(va_arg(*ar, int)));
	return (ft_print_string(va_arg(*ar, char *)));
}

int	ft_printf(const char *s, ...)
{
	va_list	ar;
	int		i;
	int		re;

	if (!s)
		return (-1);
	re = 0;
	i = 0;
	va_start(ar, s);
	while (s[i])
	{
		if (s[i] == '%' && (s[i + 1] == 's' || s[i + 1] == 'd'))
		{
			re += ft_print(s[i + 1], &ar);
			i += 2;
		}
		else
			re += write(2, &s[i++], 1);
	}
	va_end(ar);
	return (re);
}
