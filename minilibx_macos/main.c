#include <stdio.h>
#include "mlx.h"
 
int        main(void)
{
    void    *mlx;
    void    *mlx_win;
 
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "HelloWorld!");
    mlx_loop(mlx);
    return (0);
}

/* int	main(int argc, char **argv)
{
	t_mlx		*mlx;
	t_map		map;
	t_bresenham	b;

	// 에러 처리
	if (argc == 1)
		ft_error("Error: no input\n");
	else if (argc > 2)
		ft_error("Error: too many input\n");
	mlx = ft_init();
	if (mlx == NULL)
		ft_error("Error: mlx_init error");
	
    // 맵 파싱
	read_map(&map, argv[1]);
	mlx->map = &map;
	
    // 등축투영
	iso_projection(mlx, mlx->map);
	size_control(mlx, mlx->map);
	
    // 직선 알고리즘
	draw(mlx, &b);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image->image, 0, 0);
	ft_free(mlx);
    
    // 이벤트 관리
	mlx_key_hook(mlx->window, key_control, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
*/
