#include "pipex.h"

void	error(void)
{
	perror("Error");
	exit(1);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	int		i;
	int		tmp;

	i = 0;
	tmp = 0;
	dst = 0;
	while (s1[tmp])
		tmp++;
	dst = (char *)malloc(sizeof(char) * (tmp + 1));
	if (dst == 0)
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	else
	{
		while (s1[i] != 0 && s2[i] != 0 && s1[i] == s2[i] && i < n - 1)
			i++;
	}
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
