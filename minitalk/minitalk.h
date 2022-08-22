/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:31:46 by ansilva-          #+#    #+#             */
/*   Updated: 2022/06/07 15:53:41 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
# include "printf/ft_printf.h"

int		ft_atoi(const char *str);
char	*ft_put_base(unsigned int n, char *base);
void	*ft_memset(void *b, int c, size_t len);
size_t	ft_strlen(char *s);

#endif
