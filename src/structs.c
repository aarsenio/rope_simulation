#include <rope.h>

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

t_spawn	*spawn(void)
{
	static t_spawn	spawn;

	return (&spawn);
}

t_rope	*rope(void)
{
	static t_rope	rope;

	return (&rope);
}

t_obs	*obs(void)
{
	static t_obs	obs;

	return (&obs);
}

void	add_node(t_obs *new, t_obs *x)
{
	while (x)
	{
		if (!x->next)
		{
			x->next = new;
			break ;
		}
		x = x->next;
	}
}

t_obs	*new_node(int x, int y)
{
	t_obs	*new;

	new = malloc(sizeof(t_obs));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->x = x;
	new->y = y;
	return (new);
}

void	destroy_obs(void)
{
	t_obs	*tmp;

	while (obs()->next)
	{
		tmp = obs()->next;
		obs()->next = obs()->next->next;
		free (tmp);
	}
}
