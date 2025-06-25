/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:45:18 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/25 18:01:43 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main(void) {
	{
		Weapon pt = Weapon("Glockada adaptada");
		HumanA menor("menor", pt);
		menor.attack();
		pt.setType("quadrada");
		menor.attack();
	}
	{
		Weapon oitao = Weapon("oitao");
		HumanB jorgin("Jorgin");
		jorgin.attack();
		jorgin.setWeapon(oitao);
		jorgin.attack();
		oitao.setType("facao cego");
		jorgin.attack();
	}
}