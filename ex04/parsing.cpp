/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:28:09 by rde-fari          #+#    #+#             */
/*   Updated: 2025/07/01 15:43:48 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"

bool	validateArgumentsContent(const std::string& str) {
	if (str.empty())
		return (ERRO);
	return (SUCCESS);
}

bool	validateArguments(int ac, char **av) {
	if (ac != 4) {
		std::cerr << RED << "[ ✗ ] " << RESET << "Invalid number of arguments." << std::endl;
	}
	for(int i = 1; av[i]; i++) {
		if (!validateArgumentsContent(av[i])) {
			std::cerr << RED << "[ ✗ ] " << RESET << "One of the arguments is empty." << std::endl;
			return (ERRO);
		}
	}
	return (SUCCESS);
}
