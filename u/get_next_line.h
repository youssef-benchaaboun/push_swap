/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoben-ch <yoben-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 19:37:49 by yoben-ch          #+#    #+#             */
/*   Updated: 2026/05/26 20:37:24 by yoben-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		ft_strlennew(char *s);
void	ft_strcpy(char *rest, char *buffer);
void	ft_shift(char *buffer);
char	*ft_strjoin(char *line, char *buffert);
#endif
