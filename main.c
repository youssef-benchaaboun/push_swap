#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	t_option	op;

	if (ac < 2 || ft_skip(&op, av, ac) == -1)
		return (0);
	a = ft_verfier(av, ac, ft_skip(&op, av, ac));
	if (!a)
		return (ft_error(NULL, NULL));
	if (a->top < 1 || ft_is_sorted(a))
		return (destroy_stack(a), 0);
	b = create_stack(ac - 1);
	if (!b)
		return (ft_error(a, NULL));
	decide_algorithm(a, b, &op);
	destroy_stack(a);
	destroy_stack(b);
	return (0);
}
