#include "../push_swap.h"

int	liberty(t_stack *a, t_stack *b, char *joined, char **splited)
{
	if (a && b)
	{
		destroy_stack(a);
		destroy_stack(b);
	}
	else if (a)
		destroy_stack(a);
	else if (b)
		destroy_stack(b);
	if (joined)
		free(joined);
	if (splited)
		free_split(splited);
	return (1);
}

static int	init_stack(char ***av, int *ac, char **joined, t_option *op)
{
	*joined = join_args(*av + 1, *ac - 1);
	*ac = ft_count_words(*joined, ' ');
	*av = ft_split(*joined, ' ');
	return (ft_skip(op, *av, *ac));
}

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	t_option	op;
	int			skip;
	char		*joined;

	skip = init_stack(&av, &ac, &joined, &op);
	if (!av || !joined || ac < 2 || skip == - 1)
		return (liberty(NULL, NULL, joined, av));
	a = ft_verfier(av, ac, skip);
	if (!a)
		return (liberty(a, NULL, joined, av));
	if (a->top < 1 || ft_is_sorted(a))
	{
		destroy_stack(a);
		return (0);
	}
	b = create_stack(ac);
	if (!b)
		return (liberty(a, b, joined, av));
	decide_algorithm(a, b, &op, ac - skip);
	return (liberty(a, b, joined, av));
}

//r --bench --complex 31 5 77 "80 241 "483 1