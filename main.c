#include "push_swap.h"

void	liberty(t_stack *a, t_stack *b, char *joined, char **splited)
{
	destroy_stack(a);
	destroy_stack(b);
	free(joined);
	free_split(splited);
}

static t_stack	*init_stack(t_option *op, char **av, int ac,
					char ***splited, char **joined)
{
	int	num_count;

	*joined = join_args(av + 1, ac - 1);
	if (!*joined)
		return (NULL);
	num_count = ft_count_words(*joined, ' ');
	*splited = ft_split(*joined, ' ');
	if (!*splited || num_count < 2)
		return (NULL);
	if (ft_skip(op, *splited, num_count) == -1)
		return (NULL);
	return (ft_verfier(*splited, num_count, op));
}

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	t_option	op;
	char		*joined;
	char		**splited;
	int			num_count;
	int			skip;

	joined = join_args(av + 1, ac - 1);
	num_count = ft_count_words(joined, ' ');
	splited = ft_split(joined, ' ');
	skip = ft_skip(&op, splited, num_count);
	if (!splited || !joined || num_count < 2 || skip == -1)
		return (ft_error(NULL, NULL));
	a = ft_verfier(splited, num_count, skip);
	if (!a)
		return (ft_error(NULL, NULL));
	if (a->top < 1 || ft_is_sorted(a))
	{
		destroy_stack(a);
		return (0);
	}
	b = create_stack(num_count);
	if (!b)
	{
		free(joined);
		free_split(splited);
		return (ft_error(a, NULL));
	}
	decide_algorithm(a, b, &op, ac -2);
	liberty(a, b, joined, splited);
	return (0);
}


//r --bench --medium 31 5 77 "80 241" 483 1