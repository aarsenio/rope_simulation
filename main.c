#include <rope.h>

static void	update_rope(void)
{
	mlx_mouse_get_pos(data()->mlx, data()->mlx_win, &rope()->endx, &rope()->endy);
	rope()->slope = ((double)rope()->endy - (double)(rope()->y)) / ((double)rope()->endx - (double)(rope()->x));
	rope()->b = (double)(rope()->y) - (rope()->slope * (double)(rope()->x));
}

int	loop(void *param)
{
	(void)param;
	if (rope()->on)
		update_rope();
	render();
	return (1);
}

int main()
{
	data()->mlx = mlx_init();
	data()->mlx_win = mlx_new_window(data()->mlx, WINDOW_RES, WINDOW_RES, "R O P E");
	data()->mlx_img = mlx_new_image(data()->mlx, WINDOW_RES, WINDOW_RES);
	mlx_mouse_hook(data()->mlx_win, mouse, data);
	mlx_loop_hook(data()->mlx, loop, data);
	mlx_loop(data()->mlx);
}
