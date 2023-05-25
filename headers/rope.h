#ifndef ROPE_H
# define ROPE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <mlx.h>
# include <mlx_int.h>

# define WINDOW_RES 800

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	t_img	*mlx_img;
}t_data;

typedef struct s_rope
{
	int		on;
	int		endx;
	int		endy;
	int		x;
	int		y;
	double	slope;
	double	b;
}t_rope;

typedef struct s_spawn
{
	int			x;
	int			y;
}t_spawn;

typedef struct s_obs
{
	int			x;
	int			y;
	struct s_obs	*next;
}t_obs;

//STRUCT
t_data	*data(void);
t_spawn	*spawn(void);
t_rope	*rope(void);
t_obs	*obs(void);
void	add_node(t_obs *new, t_obs *x);
t_obs	*new_node(int x, int y);
void	destroy_obs(void);

//HOOK
int	mouse(int event, void *param);

//RENDER
void	render(void);

//OBSTACLES
void	new_obstacle(void);

#endif