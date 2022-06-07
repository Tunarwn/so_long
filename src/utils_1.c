/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturna <tturna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:37:17 by tturna            #+#    #+#             */
/*   Updated: 2022/06/07 16:52:58 by tturna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_read_map(int fd)
{
	char	dizi[2000];
	int		a;
	int		i;
	char	*new;

	i = 0;
	a = read(fd, dizi, 2000);
	dizi[a] = '\0';
	new = strdup(dizi);
	return (new);
}

int	check_map(t_game *tuna, int y, int x)
{
	while (++y < tuna->max_y)
	{
		x = -1;
		if (strlen(tuna->map[y]) != tuna->max_x)
			ft_exit("yamuk puzii");
		while (++x < tuna->max_x)
		{
			if (tuna->map[y][x] != '1' && (y == 0 || y == tuna->max_y - 1))
				ft_exit("Duvarlar hatalı!");
			else if (tuna->map[y][x] != '1' && (x == 0 || x == tuna->max_x - 1))
				ft_exit("Sağ sol kontrol et!");
			else if (strchr("CEP01", tuna->map[y][x]) == 0)
				ft_exit("bozuk map objeleri!");
		}
	}
	return (1);
}

int	ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	ft_init(t_game *tuna, int ac, char **av)
{
	char	*map;
	int		fd;
	int		i;
	int		len;

	i = -1;
	tuna->max_y = 0;
	fd = open(av[1], O_RDONLY);
	map = ft_read_map(fd);
	len = strlen(map);
	close(fd);
	tuna->map = ft_split(map, 0, 0, 0);
	while (tuna->map[++i])
		tuna->max_y++;
	tuna->max_x = ft_strlen(tuna->map[0]);
	check_map(tuna, -1, -1);
	create_map(tuna, -1, -1);
	return (1);
}
