/* RapporteurErreur.h ----------------------------
 * IUT La Rochelle, Département Informatique
 * Enseignements de programmation (version C++)
 * Farid AMMAR-BOUDJELAL & Co.
 * version 3.3 Novembre 2019
 */

#ifndef RAPPORTEUR_H
#define RAPPORTEUR_H

#include <QXmlErrorHandler>
#include <QXmlParseException>
#include <QString>

class RapporteurErreur : public QXmlErrorHandler
{
        bool    sesErreursVues;
	public:
        RapporteurErreur();
    // -----------------------------------------------------------------------
    //  Implementation de l'interface ErrorHandler
    // -----------------------------------------------------------------------
        bool warning(const QXmlParseException & );
        ~RapporteurErreur();
        bool error(const QXmlParseException & );
        bool fatalError(const QXmlParseException & );
        QString errorString () const;
        void resetErrors();
    // -----------------------------------------------------------------------
        bool lesErreursVues() const;
};

#endif
