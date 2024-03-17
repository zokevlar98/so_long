#include <mlx.h>
#include <string.h>
//#include <stdlib.h>

//int main(void)
//{
//	void *mlx_ptr;
 
//	mlx_ptr = mlx_init();
//	if (!mlx_ptr)
//		return (1);
//	free(mlx_ptr);
//	return (0);
//}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	void *img;


	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
	img = mlx_new_image(mlx, 500, 500);
	//memset(img, 16, 10);
	int i = 0;
	int j = 0;

	while (j < 300)
	{
		i = 0;
		while (i < 300)
		{
			mlx_pixel_put(mlx,mlx_win, j, i, 0x00FFFF);
			i++;
		}
		j++;
	}
	//mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	mlx_loop(mlx);
}

//int	main(void)
//{
//	void	*mlx;
//	void	*mlx_win;

//	mlx = mlx_init();
//	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
//	mlx_loop(mlx);
//}