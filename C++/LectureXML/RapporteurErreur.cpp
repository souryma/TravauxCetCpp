/* RapporteurErreur.cpp ----------------------------
 * IUT La Rochelle, Département Informatique
 * Enseignements de programmation (version C++)
 * Farid AMMAR-BOUDJELAL & Co.
 * version 3.3 Novembre 2019
 */

#include <QXmlParseException>
#include "RapporteurErreur.h"
#include <iostream>
#include <cstdlib>
#include <string>

RapporteurErreur::RapporteurErreur()
: sesErreursVues(false)
{}

RapporteurErreur::~RapporteurErreur(){}

bool RapporteurErreur::warning(const QXmlParseException & e)
{
    sesErreursVues = true;
    std::cerr
                << "Avertissement dans le fichier \"" << e.systemId().toStdString() << "\""
                << ", ligne " << e.lineNumber()
                << ", colonne " << e.columnNumber() << std::endl
                << "Message : " << e.message().toStdString()
		<< std::endl
	;
    return sesErreursVues;
}

bool RapporteurErreur::error(const QXmlParseException & e)
{
    sesErreursVues = true;
    std::cerr
                << "Erreur dans le fichier \"" << e.systemId().toStdString() << "\""
                << ", ligne " << e.lineNumber()
                << ", colonne " << e.columnNumber() << std::endl
                << "Message : " << e.message().toStdString()
		<< std::endl
	;
    return sesErreursVues;
}

bool RapporteurErreur::fatalError(const QXmlParseException & e)
{
    sesErreursVues = true;
    std::cerr
                << "Erreur fatale dans le fichier \"" << e.systemId().toStdString() << "\""
                << ", ligne " << e.lineNumber()
                << ", colonne " << e.columnNumber() << std::endl
                << "Message : " << e.message().toStdString()
		<< std::endl
	;
    return sesErreursVues;
}

QString RapporteurErreur::errorString () const
{
        return QString("Erreur non identifie par le processeur XML !!!");
}

void RapporteurErreur::resetErrors()
{
    sesErreursVues = false;
}

bool RapporteurErreur::lesErreursVues() const
{
    return sesErreursVues;
}



