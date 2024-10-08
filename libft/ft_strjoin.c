/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkiflema <mkiflema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 14:02:39 by mkiflema          #+#    #+#             */
/*   Updated: 2022/12/24 14:02:39 by mkiflema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined_str;
	int		len;

	if (s1 == NULL)
	{
		joined_str = malloc(sizeof(char) * (ft_strlen(s2) + 1));
		ft_strlcpy(joined_str, s2, (ft_strlen(s2) + 1));
		return (joined_str);
	}
	if (!s2)
		return ((char *)s1);
	len = ft_strlen(s1) + ft_strlen(s2);
	joined_str = (char *)malloc((len + 1) * sizeof(char));
	if (!joined_str)
		return (0);
	ft_strlcpy(joined_str, s1, len + 1);
	ft_strlcat(joined_str, s2, len + 1);
	free(s1);
	return (joined_str);
}

// int main()
// {

// 	char *s2 = "Hello";
// 	char *s1 = NULL;

// 	printf("%s", ft_strjoin(s1, s2));
// }