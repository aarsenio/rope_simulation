#include <rope.h>

int	mouse(int event, void *param)
{
	(void)param;
	if (event == 1 && !rope()->on)
		new_obstacle();
	if (event == 2)
	{
		rope()->on = 0;
		destroy_obs();
	}
	if (event == 3 && !rope()->on)
	{
		rope()->on = 1;
		mlx_mouse_get_pos(data()->mlx, data()->mlx_win, &(spawn()->x), &(spawn()->y));
		rope()->x = spawn()->x;
		rope()->y = spawn()->y;
	}
	return (1);
}
