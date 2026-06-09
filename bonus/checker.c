#include "push_swap.h"
#include "get_next_line.h"
int ft_opration(char *s,t_stack *a,t_stack *b)
{
	if(!ft_strcmp(s,"pa\n"))
		return push_in(a,b,0);
	else if(!ft_strcmp(s,"pb\n"))
		return push_in(b,a,0);
	else if(!ft_strcmp(s,"ra\n"))
		return rotate_stack(a,0);
	else if(!ft_strcmp(s,"rb\n"))
		return rotate_stack(b,0);
	else if(!ft_strcmp(s,"rr\n"))
        return  (rotate_stack(a,0) && rotate_stack(b,0));
    else if(!ft_strcmp(s,"rra\n"))
		return re_rotate_stack(a,0);
	else if(!ft_strcmp(s,"rrb\n"))
		return re_rotate_stack(b,0);
	else if(!ft_strcmp(s,"rrr\n"))
       return (re_rotate_stack(a,0) && re_rotate_stack(b,0));
	else if(!ft_strcmp(s,"sa\n"))
		return swap_stack(a,0);
	else if(!ft_strcmp(s,"sb\n"))
		return swap_stack(b,0);
	else if(!ft_strcmp(s,"ss\n"))
        return (swap_stack(a,0) && swap_stack(b,0));
	return 0;
}
int check_opration(t_stack *a,t_stack *b)
{
	char *s;
	s=get_next_line(0);
	while(s)
	{
		if(ft_opration(s,a,b))
			s=get_next_line(0);
		else
		{
			ft_error(a,b);
			return 0;
		}
	}
	if(ft_is_sorted(a) && b->top==-1) //after opration check if sorted and b empty not ony sorted
		return write(1,"ok\n",3);
	return write(1,"ko\n",3);
}
int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;


	if (ac < 2)
		return (0);
	a = ft_verfier(av, ac,0);
	if (!a)
		return (ft_error(NULL, NULL));
	if (a->top < 1 || ft_is_sorted(a))
		return (destroy_stack(a),write(1,"ok\n",3));
	b = create_stack(ac - 1);
	if (!b)
		return (ft_error(a, NULL));
    check_opration(a,b);
	return (0);
}
