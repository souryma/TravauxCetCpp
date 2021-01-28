/* TypeNoeudDOM.h ----------------------------
 * IUT La Rochelle, Département Informatique
 * Enseignements de programmation (version C++)
 * Farid AMMAR-BOUDJELAL & Co.
 * version 3.3 Novembre 2019
 */

#ifndef TYPENOEUD_H
#define TYPENOEUD_H

#include <iostream>

class TypeNoeudDOM
{
		short sonType;
	public :
        TypeNoeudDOM(const short t);
        short getType() const;
};

std::ostream & operator << (std::ostream & s, const TypeNoeudDOM);

#endif
