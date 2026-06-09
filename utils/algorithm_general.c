#include "../push_swap.h"

void	ft_bzero(void *p, size_t size)
{
	char	*s;

	s = (char *)p;
	while (size--)
		*(s++) = '\0';
}

int	ft_disorder(t_stack *a)
{
	float	mistakes;
	float	total_pairs;
	int		i;
	int		j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i <= (a->top))
	{
		j = i + 1;
		while (j <= (a->top))
		{
			total_pairs += 1;
			if (a->tab[i] > a->tab[j])
				mistakes += 1;
			j++;
		}
		i++;
	}
	return ((mistakes / total_pairs) * 10000);
}

static t_benchmark	*intiat_bench(t_stack *a, t_option *op)
{
	t_benchmark	*bench;

	bench = malloc(sizeof(*bench));
	if (!bench)
		return (NULL);
	ft_bzero(bench, sizeof(*bench));
	bench->disorder = ft_disorder (a);
	if (op->simple)
		bench->startegy = "Simple / O(n^2)";
	else if (op->medium)
		bench->startegy = "medium / O(n√n)";
	else if (op->complx)
		bench->startegy = "Complex /  O(n log(n))";
	//else if(op->adaptive)
		//we implent late bench->startegy
	//else
		//we implent later
	return (bench);
}

void	decide_algorithm(t_stack *a, t_stack *b, t_option *op, int argc)
{
	t_benchmark	*bench;

	bench = intiat_bench(a, op);
	ft_coordinate(a);
	if (op->simple)
		ft_simple(a, b, bench);
	else if (op->medium)
		ft_medium(a, b, bench, argc);
	else if (op->complx)
		radix_sort(a,b,bench);
	//else if (op->adaptive)
		//we implement later ft_adaptive
	//else 
		//we implement later ft_adaptive (default)
	if (op->bench)
		display_bench (bench);
}
