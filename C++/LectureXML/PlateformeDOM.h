/* PlateformeDOM.h ----------------------------
 * IUT La Rochelle, Département Informatique
 * Enseignements de programmation (version C++)
 * Farid AMMAR-BOUDJELAL & Co.
 * version 3.3 Novembre 2019
*/

#ifndef PLATEFORME_H
#define PLATEFORME_H

#include <QDomImplementation>
#include <QDomDocument>

class PlateformeDOM
{
                QDomImplementation sonImplementationDOM;
	public :		
                QDomDocument faisDocumentVideDTD
                        (const std::string & unNomRacine, const std::string & uneURL_dtd);

                QDomDocument faisDocumentVideSVG();
			
                QDomDocument faisArbre(const std::string & uneEntiteXML);
    
                void serialiseArbre(QDomDocument unArbreDOM, const std::string & uneEntiteXML);
};

#endif
