#include "../minishell.h"

void define_flag(int *shield_count, int *flag)
{
	if ((*shield_count) % 2 == 0)
	{
		if ((*flag) == 0)
			(*flag) = 1;
		else
			(*flag) = 0;
	}
	else
		*flag = 1;
	(*shield_count) = 0;
}

int		find_redir(char *str, char c)
{
	int	iter;
	int	shield_count;
	int	position;
	int	flag;
	int	check_flag;

	check_flag = 0;
	iter = 0;
	shield_count = 0;
	position = -1;
	flag = 0;
	while (str[iter])
	{
		iter += skip_symbol(str + iter, &shield_count, '\\');
		if (str[iter] && is_quote(str[iter]) && flag == 0)
			define_flag(&shield_count, &flag);
		else if (str[iter] && is_quote(str[iter]) && flag == 1)
			define_flag(&shield_count, &flag);
		else if (str[iter] == c)
		{
			define_flag(&shield_count, &flag);
			if (flag == 0)
			{
				position = iter;
				while (str[iter] && str[iter] == c)
				{
					iter++;
					check_flag++;
				}
				if (c == '<' && check_flag > 1)
					printf("error near <");
				else if (c == '>' && check_flag > 2)
					printf("error near >");
				//else
				//	iter -= check_flag;
				return (position);
			}
		}
		iter++;
	}
	return (position);
}
