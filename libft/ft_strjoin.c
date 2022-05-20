/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:34:44 by gyumpark          #+#    #+#             */
/*   Updated: 2022/05/20 11:37:38 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*save;
	int		i;
	int		j;

	if (!s1)
		s1 = ft_calloc(1, 1);
	if (!s1 || !s2)
		return (NULL);
	save = malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!save)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		save[j++] = s1[i];
	i = -1;
	while (s2[++i])
		save[j++] = s2[i];
	save[j] = 0;
	free(s1);
	return (save);
}
