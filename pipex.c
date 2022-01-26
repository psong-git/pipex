#include "pipex.h"

char	*find_path(char *cmd, char **envp)
{
	char	**envp_paths;
	char	*cmd_slash_path;
	char	*tmp;
	int		i;

	i = 0;
	while (ft_strncmp("PATH=", envp[i], 5) != 0)
		i++;
	envp_paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (envp_paths[i])
	{
		tmp = ft_strjoin(envp_paths[i], "/");
		cmd_slash_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(cmd_slash_path, F_OK) == 0)
			return (cmd_slash_path);
		i++;
	}
	return (0);
}

void	execute(char *argv, char **envp)
{
	char	**cmd;

	cmd = ft_split(argv, ' ');
	if (execve(find_path(cmd[0], envp), cmd, envp) == -1)
		error();
}

void	child_process(char **argv, char **envp, int *fd)
{
	int		filein;

	filein = open(argv[1], O_RDONLY, 0644);
	if (filein == -1)
		error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	close(fd[0]);
	execute(argv[2], envp);
}

void	parent_process(char **argv, char **envp, int *fd)
{
	int		fileout;

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fileout == -1)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fd[1]);
	execute(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error();
		pid = fork();
		if (pid == -1)
			error();
		if (pid == 0)
			child_process(argv, envp, fd);
		else
		{
			waitpid(pid, NULL, 0);
			parent_process(argv, envp, fd);
		}
	}
	else
		write(2, "ERROR\n", 6);
	return (0);
}
