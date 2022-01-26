#include "pipex.h"

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
	dst = (char *)malloc(sizeof(char) * len);
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, s1, (ft_strlen(s1) + 1));
	ft_strlcat(dst, s2, len);
	return (dst);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

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
