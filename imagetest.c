#include "so_long.h"

int	main(void)
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*relative_paths[] = {"./images/1.xpm", "./images/2.xpm", "./images/3.xpm", "./images/4.xpm"};
	int		img_width;
	int		img_height;
	int	 i;

	mlx = mlx_init();
	if (mlx == NULL) {
		fprintf(stderr, "Failed to initialize mlx\n");
		return 1;
	}

	win = mlx_new_window(mlx, 10 * 64, 64, "My Image Window");
	if (win == NULL) {
		fprintf(stderr, "Failed to create window\n");
		return 1;
	}

	for (i = 0; i < 10; i++) {
		img = mlx_xpm_file_to_image(mlx, relative_paths[i % 2], &img_width, &img_height);
		if (img == NULL) {
			fprintf(stderr, "Failed to load image\n");
			return 1;
		}
		mlx_put_image_to_window(mlx, win, img, i * img_width, 0);
	}

	mlx_loop(mlx);

	return 0;
}