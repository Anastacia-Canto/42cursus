/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:29:42 by ansilva-          #+#    #+#             */
/*   Updated: 2022/02/15 14:46:24 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;
	size_t	len_dst;
	size_t	i;
	size_t	a;

	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	if (dstsize == 0 || dstsize <= len_dst)
		return (len_src + dstsize);
	i = 0;
	while (dst[i])
		i++;
	a = 0;
	while (src[a] && (a < (dstsize - len_dst -1)))
	{
		dst[i + a] = src[a];
		a++;
	}
	dst[i + a] = '\0';
	return (len_src + len_dst);
}
