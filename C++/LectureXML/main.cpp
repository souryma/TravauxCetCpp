#include "PlateformeDOM.h"
#include "RapporteurErreur.h"
#include "TypeNoeudDOM.h"

using namespace std;

void listeParenthesee (QDomNode unNoeudArbre) {

    QDomNode leFils;

    if (unNoeudArbre.nodeName().toStdString()=="Texte"){
        cout<<"(t ";
    }

    for (leFils=unNoeudArbre.firstChild(); !leFils.isNull(); leFils=leFils.nextSibling()) {
        if (!leFils.isNull() && leFils.nodeType()==QDomNode::ElementNode) {
            if (leFils.nodeName().toStdString()=="Liste") {
                cout <<"(l ";
                listeParenthesee(leFils);
                cout<<" ) ";
            }
            else if (leFils.nodeName().toStdString()=="Mot") {
                cout <<"m:";
                QDomNamedNodeMap laListeAttributs = leFils.attributes();
                QDomNode leAttr = laListeAttributs.namedItem(QString("nom"));
                cout << leAttr.nodeValue().toStdString()<<" ";
            }
        }
    }
    if (unNoeudArbre.nodeName().toStdString()=="Texte") {
        cout << ")";
    }
}

int main(void) {
    PlateformeDOM *plateformeDOM=new PlateformeDOM();
    QDomDocument arbreDOM = plateformeDOM->faisArbre("texte.xml");

    listeParenthesee(arbreDOM.documentElement());

    return 0;
}
