#include "../push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	already_option(t_option *p)
{
	if (p->adaptive)
		return (0);
	else if (p->complx)
		return (0);
	else if (p->medium)
		return (0);
	else if (p->simple)
		return (0);
	else if (p->bench)
		return (2);
	return (1);
}

int	ft_option(char *s, t_option *p)
{
	if (!ft_strcmp(s, "--adaptive") && already_option(p))
		p->adaptive++;
	else if (!ft_strcmp(s, "--complex") && already_option(p))
		p->complx++;
	else if (!ft_strcmp(s, "--medium") && already_option(p))
		p->medium++;
	else if (!ft_strcmp(s, "--simple") && already_option(p))
		p->simple++;
	else if (!ft_strcmp(s, "--bench") && already_option(p) != 2)
		p->bench++;
	else
		return (0);
	return (1);
}

int	ft_skip(t_option *op, char **av, int ac)
{
	int	skip;

	ft_bzero(op, sizeof(t_option));
	skip = ft_option(av[0], op);
	if (1 + skip >= ac)
		return (-1);
	skip += ft_option(av[skip], op);
	if (1 + skip >= ac)
		return (-1);
	return (skip);
}
