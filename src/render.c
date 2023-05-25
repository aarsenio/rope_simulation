#include <rope.h>

static void	mlx_draw_pixel(t_img *mlx_img, int x, int y, int color)
{
	char			*target;

	target = mlx_img->data + (x * mlx_img->bpp / 8 + y * mlx_img->size_line);
	*(unsigned int *)target = color;
}

static void	draw_black(void)
{
	int	i = -1;
	int	j = -1;

	while (++j < WINDOW_RES)
	{
		i = -1;
		while (++i < WINDOW_RES)
			mlx_draw_pixel(data()->mlx_img, i, j, 0x00000000);
	}
}

static void	draw_line(double x1, double y1, double x2, double y2)
{
	double slope,b;

	slope = (y2 - y1) / (x2 - x1);
	b = y1 - (slope * x1);
	if (x2 >= x1)
	{
		while (x1 <= x2)
		{
			y1 = slope * x1 + b;
			mlx_draw_pixel(data()->mlx_img, x1, y1, 0xFFFFFF);
			x1 = x1 + 0.01f;
		}
	}
	else
	{
		while (x1 >= x2)
		{
			y1 = slope * x1 + b;
			mlx_draw_pixel(data()->mlx_img, x1, y1, 0xFFFFFF);
			x1 = x1 - 0.01f;
		}
	}
}

static void	draw_rope(void)
{
	draw_line((double)rope()->x, (double)rope()->y, (double)rope()->endx, (double)rope()->endy);
}

static void draw_obs(void)
{
	t_obs	*tmp;

	tmp = obs()->next;
	while (tmp)
	{
		mlx_draw_pixel(data()->mlx_img, tmp->x, tmp->y, 0xFFFFFF);
		tmp = tmp->next;
	}
}

void	render(void)
{
	draw_black();
	draw_obs();
	if (rope()->on)
		draw_rope();
	mlx_put_image_to_window(data()->mlx, data()->mlx_win, data()->mlx_img, 0, 0);
}
