/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:34:37 by gyumpark          #+#    #+#             */
/*   Updated: 2022/05/20 11:37:17 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *s, int c)
{
	char	*str;

	if (!s)
		return (0);
	str = (char *)s;
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (*str != (char)c && *str != 0)
		str++;
	if (*str == (char)c)
		return (str);
	else
		return (NULL);
}
