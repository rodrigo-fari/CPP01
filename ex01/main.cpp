/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:46:57 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/25 00:11:51 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	int n = 10;
	Zombie* horde = zombieHorde(n, "zombie");
	
	for(int i = 0; i < n; i++) {
		std::cout << "[ " << (i + 1) << " ] ";
		horde[i].announce();
	}
	delete[] horde;
}
