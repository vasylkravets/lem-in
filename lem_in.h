/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 16:09:59 by vkravets          #+#    #+#             */
/*   Updated: 2018/03/31 16:10:04 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define BUFF_SIZE 1

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>

typedef	struct		s_data
{
	int				flag;
	int				ants;
	int				error;
	int				start;
	int				end;
	int				flag_start;
	int				flag_end;
	char			*line;
	int				value;
	int				invalid_link;
	struct s_data	*next;
}					t_data;

typedef struct		s_rooms
{
	char			*name;
	int				x;
	int				y;
	int				status;
	int				set;
	int				set_rec;
	int				is_way;
	int				id_ants;
	int				position;
	struct s_rooms	*next;
	struct s_links	*next_link;
	struct s_rooms	*prev;
}					t_rooms;

typedef struct		s_links
{
	t_rooms			*down_room;
	struct s_links	*next;

}					t_links;

typedef struct		s_way
{
	int				value;
	int				step;
	struct s_rooms	*way;
	struct s_way	*next;
}					t_way;

int					check_hash(t_data *data);
int					check_error(t_data *data, char *line);
void				print_ants(t_way *stack);
void				ft_full_way(t_way *st, t_data *da, t_data *p, t_rooms *ro);
void				ft_set_id_ants(t_way *stack);
t_way				*ft_new_mode(t_rooms *new, t_rooms *room);
t_way				*return_all_way(t_rooms *room);
void				ft_swap_ants(t_data *data, t_way *stack, int *i);
void				ft_count_step(t_way *stack);
int					ft_set(t_rooms *room, t_data *data, t_data *print);
t_rooms				*function_for_copy_stack(t_rooms *copy);
void				print_ants_all_in(t_data *data, t_data *prin, t_rooms *roo);
void				ft_count_value(t_way *stack);
int					ft_check_join(t_rooms *room);
void				ft_recursion(t_links *current2, int i);
t_links				*ft_search(char *down, t_rooms *room);
void				function_for_rec(t_rooms *room);
int					ft_break(t_way *stack);
int					check_room_after_start(char *li, t_data *da, t_rooms **ro);
int					check_room_after_end(char *line, t_data *da, t_rooms **ro);
int					check_the_end(t_data *data);
int					ft_check_list(t_rooms *queue, char *name);
void				ft_check_dublicate(t_rooms *down, t_way *stack);
void				check_for_remove(t_way *stack);
void				list_remove_if_two(t_way **begin_list);
void				ft_remove_down(t_way *del);
void				ft_remove_down_room(t_rooms *del);
void				list_remove_all(t_way **beg_li, t_data **bl_, t_rooms **bl);
int					ft_sub_fun_digit_two(char *line, size_t *i, t_data *data);
int					ft_sub_fun_digit(t_data *data);
void				ft_reset_flag(t_data *data);
int					ft_check_digit(char *line, t_data *data);
int					check_invalid_link(t_data *data);
void				free_mas(char **mas);
void				lst_back_way(t_way **alst, t_way *new);
void				ft_free(t_rooms **begin_list);
t_way				*new_list_way(t_rooms *lst);
void				ft_sort(t_rooms *room);
t_links				*ft_new(char *str, t_rooms **room);
void				ft_check_link(char *line, t_data *data, t_rooms **room);
void				ft_pushback(t_links **alst, t_links *new);
void				lst_back_data(t_data **alst, t_data *new);
t_data				*new_list_data(char *str);
t_rooms				*sub_func_lst_add(char **mas, t_data *data);
void				ft_lstdel_func(t_rooms **alst);
void				func_check_room(char *line, t_data *data, t_rooms **room);
void				ft_check_end(char *line, t_data *data);
void				ft_check_start(char *line, t_data *data);
void				func_check_ants(char *line, t_data *data);
int					ft_atoi_mod(const char *str, t_data *data);
int					get_next_line(int fd, char **line);
void				ft_print_error(t_data *data);
t_rooms				*new_list(t_rooms *lst);
void				lst_back(t_rooms **alst, t_rooms *new);

#endif
