#include "push_swap.h"

int	liberty(t_stack *a, t_stack *b, char *joined, char **splited)
{
	destroy_stack(a);
	destroy_stack(b);
	free(joined);
	free_split(splited);
	return (1);
}

static int	init_stack(char ***av, int ac, char **joined, t_option *op)
{
	*joined = join_args(*av + 1, ac - 1);
	ac = ft_count_words(*joined, ' ');
	*av = ft_split(*joined, ' ');
	return (ft_skip(op, *av, ac));
}

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	t_option	op;
	int			skip;
	char		*joined;

	skip = init_stack(&av, ac, &joined, &op);
	a = ft_verfier(av, ac, skip);
	if (!av || !joined || ac < 2 || !a || !skip)
		return (ft_error(NULL, NULL));
	if (a->top < 1 || ft_is_sorted(a))
	{
		destroy_stack(a);
		return (0);
	}
	b = create_stack(ac);
	if (!b)
	{
		free(joined);
		free_split(av);
		return (ft_error(a, NULL));
	}
	decide_algorithm(a, b, &op, ac -2);
	return (liberty(a, b, joined, av));
}


//r --bench --medium 31 5 77 "80 241" 483 1