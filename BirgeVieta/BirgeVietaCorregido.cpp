//Progama Biege-Vieta
//Equipo:
//Jose Carmelo Ramirez Beltran
//Miguel Cuellar Gauna
//Carlos Serret Heredia
//Fecha: 11/02/2016

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


double Vieta(vector<double> vPolinomio, int iGrado, double dX, bool bDiv)
{
    vector<double> vDerivada;
    double dRes = vPolinomio[iGrado];
    for (int i=iGrado-1; i>=0; i--) {
        dRes *= dX;
        dRes += vPolinomio[i];
        vDerivada.insert(vDerivada.begin(), dRes);
    }
    if (bDiv) {
        double dRes2 = vPolinomio[iGrado];
        for (int i=iGrado-1; i>=1; i--) {
            dRes2 *= dX;
            dRes2 += vDerivada[i];
        }
        return dRes/dRes2;
    } else {
        return dRes;
    }
}

int main() {
    char cDesicion; //Decision de seguir o no
    double dError, dRaiz; //Error y Raiz
    int iGrado, iIteracionesMax; //Grado Polinomio e Iteraciones Maximas
    vector<double> vPolinomio; //Polinomio
    
    do {
        cout << "Grado Polinomio: ";
        cin >> iGrado;
        
        for (int i=iGrado; i>=0; i--) {
            cout << "Coeficiente del Grado: " << i << "? ";
            double dCoef;
            cin >> dCoef;
            vPolinomio.insert(vPolinomio.begin(), dCoef);
        }
        
        cout << "Numero maximo de Iteraciones: ";
        cin >> iIteracionesMax;
        cout << "Tolerancia de Error: ";
        cin >> dError;
        
        int dR = 1;
        while (iGrado>0) {
            int iIte = iIteracionesMax;
            dRaiz = rand() % 100;
            do {
                dRaiz = dRaiz - Vieta(vPolinomio, iGrado, dRaiz, 1);
            } while ((dError<fabs(Vieta(vPolinomio, iGrado, dRaiz, 0))) && (0<iIte));
            if (0<iIte){
                cout << "Raiz" << dR++ << " es: " << dRaiz << endl;
                double y = vPolinomio[iGrado];
                for (int i=iGrado-1; i>=1; i--) {
                    y *= dRaiz;
                    y += vPolinomio[i];
                    vPolinomio[i] = y;
                }
                vPolinomio.erase(vPolinomio.begin());
                iGrado--;
            }
            else{
                cout << "No hay mas raices";
                iGrado=0;
            }
        }
        vPolinomio.clear();
        
        cout << "Resolver otro Polinomio (s = si , n = no): ";
        cin >> cDesicion;
    } while (cDesicion == 's');
}
