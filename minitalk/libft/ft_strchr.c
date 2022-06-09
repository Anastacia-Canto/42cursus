/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:27:39 by ansilva-          #+#    #+#             */
/*   Updated: 2022/03/03 10:36:10 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	b;

	b = c;
	i = 0;
	while (s && s[i] && (s[i] != b))
		i++;
	if (s[i] == b)
		return ((char *)s + i);
	else
		return (NULL);
}
