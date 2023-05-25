#include <rope.h>

void	new_obstacle(void)
{
	int	x,y;

	mlx_mouse_get_pos(data()->mlx, data()->mlx_win, &x, &y);
	add_node(new_node(x, y), obs());
}