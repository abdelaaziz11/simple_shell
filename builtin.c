#include "shell.h"

/**
 * _my_exit - exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: exits with a given exit status
 *         (0) if info.argv[0] != "exit"
 */
int _my_exit(info_t *info)
{
	int exitcheck;

	if (info->argv[1])
	{
		exitcheck = _erratoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			print_error(info, "Its an Illegal number: ");
			_eputs(info->argv[1]);
			_eput_char('\n');
			return (1);
		}
		info->err_num = exitcheck;
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}
/**
 * _my_cd - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _my_cd(info_t *info)
{
	char *cur_dir, *tag_dir, buffer[1024];
	int chdir_ret;

	cur_dir = getcwd(buffer, 1024);
	if (!cur_dir)
	_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		tag_dir = _get_env(info, "HOME=");
		if (!tag_dir)
			chdir_ret = chdir((tag_dir = _get_env(info, "PWD=")) ? tag_dir : "/");
		else
			chdir_ret = chdir(tag_dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_get_env(info, "OLDPWD="))
		{
			_puts(cur_dir);
			_putchar('\n');
			return (1);
		}
		_puts(_get_env(info, "OLDPWD="));
		_putchar('\n');
		chdir_ret = chdir((tag_dir = _get_env(info, "OLDPWD=")) ? tag_dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]);
		_eput_char('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _get_env(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
