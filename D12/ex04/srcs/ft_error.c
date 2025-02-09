#include "ft.h"

void	ft_error(char *prog_name, char *arg)
{
	if (errno == EACCES)
	{
		ft_putstr(prog_name);
		ft_putstr(": ");
		ft_putstr(arg);
		ft_putstr(": Permission Denied\n");
	}
	else if (errno == EISDIR)
	{
		ft_putstr(prog_name);
		ft_putstr(": ");
		ft_putstr(arg);
		ft_putstr(": Is a directory\n");
	}
	else
	{
		ft_putstr(prog_name);
		ft_putstr(": ");
		ft_putstr(arg);
		ft_putstr(": No such file or directory\n");
	}
}