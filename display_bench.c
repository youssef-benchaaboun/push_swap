#include"push_swap.h"

int	count_total(t_benchmark *bench)
{
	int	totale;

	totale = bench->sa + bench->sb + bench->ss;
	totale += bench->ra + bench->rb + bench->rr;
	totale += bench->rra + bench->rrb + bench->rrr;
	totale += bench->pa + bench->pb;
	return (totale);
}

void	display_bench(t_benchmark *bench)
{
	ft_printf("[bench] disorder : %d.%d%\n",
		(bench->disorder) / 100, ((bench->disorder) % 100));
	ft_printf("[bench] strategy: %s\n", bench->startegy);
	ft_printf("[bench] total_ops: %d\n", count_total(bench));
	ft_printf("[bench] sa: %d sb: %d pa: %d pb: %d\n",
		bench->sa, bench->sb, bench->pa, bench->pb);
	ft_printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n", 
		bench->ra, bench->rb, bench->rr, bench->rra, bench->rrb, bench->rrr);
	free(bench);
}
