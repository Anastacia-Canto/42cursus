/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 11:32:05 by ansilva-          #+#    #+#             */
/*   Updated: 2022/03/08 14:37:51 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);
int		ft_put_di(int n);
int		ft_put_u(unsigned int n);
char	*ft_put_base(unsigned int n, char *base);
int		ft_put_pointer(void *p);
char	*ft_put_base_pointer(unsigned long address, char *base);
int		ft_put_hex(unsigned int n, char format);
char	*ft_put_base_hex(unsigned int nb, char *base);

#endif