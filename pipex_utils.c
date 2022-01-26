#include "pipex.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	int		i;
	int		tmp;

	i = 0;
	tmp = 0;
	while (s1[tmp])
		tmp++;
	if (!(dst = (char *)malloc(sizeof(char) * (tmp + 1))))
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		i;
	int		j;
	size_t	len;

	i = 0;
	j = 0;
	if (s1 == NULL)
		return (NULL);
	len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!(dst = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	ft_strlcpy(dst, s1, (ft_strlen(s1) + 1));
	ft_strlcat(dst, s2, len);
	return (dst);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t dst_len;
	size_t src_len;
	size_t i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	if (dstsize < dst_len + 1)
		return (dstsize + src_len);
	if (dstsize > dst_len + 1)
	{
		while (src[i] != '\0' && dst_len + 1 + i < dstsize)
		{
			dst[dst_len + i] = src[i];
			i++;
		}
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (src == NULL)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}