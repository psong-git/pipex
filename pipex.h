#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>

# define TRUE 1
# define FALSE 0
# define SUCCESS 1
# define FAIL 0
# define ERROR 0

void	error(void);
char	*find_path(char *cmd, char **envp);
int		get_next_line(char **line);
void	execute(char *argv, char **envp);
char	*ft_strdup(const char *s1);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	**ft_malloc_error(char **dst);
int		ft_count_words(const char *s, char c);
char	**ft_size_words(const char *s, char c, char **dst, int i);
void	ft_do(const char *s, char **dst, char c, int i);
char	**ft_split(const char *s, char c);
size_t	ft_strlen(const char *str);

#endif
