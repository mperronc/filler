/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 18:39:33 by mperronc          #+#    #+#             */
/*   Updated: 2016/09/03 18:39:46 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

void	print_specs(t_specs *specs)
{
	printf("- flag : %d\n", specs->minus);
	printf("+ flag : %d\n", specs->plus);
	printf("' ' flag : %d\n", specs->space);
	printf("# flag : %d\n", specs->sharp);
	printf("0 flag : %d\n", specs->zero);
	printf("\n");
	printf("minimum field width : %d\n", specs->width);
	printf("precision : %d\n", specs->precision);
	printf("\n");
	printf("length flag : %c\n", specs->length);
	printf("type flag : %c\n", specs->type);
	printf("is just percent ? : %d\n", specs->percent);
	printf("is valid ? : %d\n", specs->valid);
}
