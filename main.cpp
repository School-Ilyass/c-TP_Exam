#include<iostream>
#include<vector>	
#include<math.h>	
#include<limits> //! MAX MIN AVG
#include<chrono> //! Time
#include<ctime> //! Time
#include <iomanip> //! Formating Data

#include "./headers/main.h" //! For classes and methods

using namespace std;



// ! Surprimmer la facture
void supprimerFF(vector<Facture> &F1,int &code)
{
	
	for(int i=0;i<F1.size();i++)
		{
			if(code==(F1.at(i).getCode()))
				{
					F1.erase(F1.begin()+i);
					std::cout<<"La facture a �t� supprime avec succ�s." << endl;
					return;
				}
		}
}


// ! Modifier la facture

void modifierFacture(vector<Facture> &F1, int Code)
{
	int i;
	bool exists=false;
	for(i=0;i<F1.size();i++)
		{
			if(F1.at(i).getCode()== Code )
				{
					exists=true;
					break;
				}
		}
	if(exists)
	{
		std::cout<<"code introuvable"<<endl;
		return;
	}

	int choix;
	int first_time=0;
	do{
		if(first_time == 0)
			{
				first_time++;
				std::cout<<"taper 1 pour modifier le code"<<endl<<"taper 2 pour modifier l etat"<<endl<<"taper 3 pour modifier les Produits"<<endl;
				std::cout<<"taper 4 pour modifier le client"<<endl<<"taper 5 pour modifier tout"<<"TAPER 0 POUR QUITTER"<<endl;
				std::cin>>choix;
			}
		else
			{
				std::cout<<"modifier encore? si oui taper de 1-5 sinon taper 0 pour quitter"<<endl;
				std::cin>>choix;
					
			}
		Client C;
		int CODE;
		int ETAT;
		int ID;
		switch(choix)
			{
			case 0: 
				break;
			case 1: 
					std::cout<<"saisir le nouveau code"<<endl<<endl;
					std::cin>> CODE;
					F1.at(i).setCode(CODE);
					break;
			case 2: 
					std::cout<<"saisir l'etat "<<endl<<endl;
					std::cin>> ETAT;
					F1.at(i).setEtat(ETAT);
					break;
			case 3: 
					std::cout<<"saisir l'ID du produit a modifier"<<endl;
					
					std::cin>>ID;
					F1.at(i).modifierFP(ID);
					break;
			case 4: 
					
					std::cout<<"Modification du client: "<<endl<<endl;
					std::cin>> C;
					F1.at(i).setC(C);
					break;
			case 5: 
					std::cout<<"saisir le nouveau code"<<endl<<endl;
					std::cin>>CODE;
					F1.at(i).setCode(CODE);
					std::cout<<"saisir l'etat "<<endl<<endl;
					std::cin>> ETAT;
					F1.at(i).setEtat(ETAT);
					std::cout<<"saisir l'ID du produit a modifier"<<endl;
					std::cin>>ID;
					F1.at(i).modifierFP(ID);
			 		std::cout<<"Modification du client: "<<endl<<endl;
					F1.at(i).getC().Modifier();
					break;
			default:
				std::cout<<"taper 1 pour modifier le code"<<endl<<"taper 2 pour modifier l etat"<<endl<<"taper 3 pour modifier les Produits"<<endl;
				std::cout<<"taper 4 pour modifier le client"<<endl<<"taper 5 pour modifier tout"<<"TAPER 0 POUR QUITTER"<<endl;
			}
	}while(choix!=0);
	
}





// ! Affichage de tout les factures du vecteur
void afficher_vector_Facture(vector<Facture> const &F1) 
{
	
	system("clear");
	for(int i=0;i<F1.size();i++)
		{
			cout<<"la facture N:"<<i+1<<endl;
			cout<<F1.at(i)<<endl;
		}
}


// !Cherche la facture du client dans le vecteur
bool passer_facture_in_vector(const vector<Facture>& facture,const int &ID)  
	{
    for (int i=0;i<facture.size();i++) 
		{
            if (facture.at(i).getC().getID() == ID)
				{
                	return true; 
            	}
        }
    return false;
    }

// !VOIR L'etat de la facture 
bool Client_Passer_Facture_test(Facture F)
{
	if (F.getEtat()) {
        /*cout << "Le client " << F.getC().getNom() << " a passe une facture d'un montant de " << F.total()  <<endl;*/
		return true;
    } else {
        /*cout << "Le client " << F.getC().getNom() << " n'a pas encore passe de facture." <<endl;*/
		return false;
    }
}



// ! Affichage des client sans paiement
void afficher_clients_sans_paiement( vector<Facture> &facture)
{
	for(int i=0;i<facture.size();i++)
		{
			if(passer_facture_in_vector(facture,facture.at(i).getC().getID()))
				{
					if(!Client_Passer_Facture_test(facture.at(i)))
						{
							cout<<"cette client n a pas encore paye :"<<endl;
							cout<<"nom : "<<facture.at(i).getC().getNom()<<endl;
							cout<<"prenom : "<<facture.at(i).getC().getPrenom()<<endl;
							cout<<"Montant : "<<facture.at(i).total()<<endl;
						}
				}
		}
}
// !Afficher les factures de la meme date qu'aujourdhui
void afficher_Factures_aujourdhui(vector <Facture> const F1)
{
	for(int i=0; i<F1.size();i++)
		{
			if(F1.at(i).aujourdhui())
				{
					cout<< F1.at(i);
				}
		}
}



int main() {
    // Create a vector to store Factures
    vector<Facture> factures;

    int choice;

    do {
        //  menu
        cout << "\n=== Menu ===" << std::endl;
        cout << "1. Ajouter une facture" << std::endl;
        cout << "2. Supprimer une facture" << std::endl;
        cout << "3. Modifier une facture" << std::endl;
        cout << "4. Afficher les factures" << std::endl;
        cout << "5. Afficher les clients sans paiement" << std::endl;
        cout << "6. Afficher les factures d'aujourd'hui" << std::endl;
        cout << "0. Quitter" << std::endl;

        // Get user choice
        cout << "\nChoix : "<<endl;
        cin >> choice;

        // Process user choice
        switch (choice) {
            case 1: // Ajouter une facture
                {
                    Facture nouvelleFacture;
                    factures.push_back(nouvelleFacture);
                    std::cout << "Facture ajoutee avec succes." << std::endl;
                    break;
                }
            case 2: // Supprimer une facture
                {
                    int codeFacture;
                    cout << "Saisir le code de la facture a supprimer : ";
                    cin >> codeFacture;
                    supprimerFF(factures,codeFacture);
                    // Implement logic to delete the specified facture
                    // Example: factures = supprimerFacture(factures, codeFacture);
                    break;
                }
            case 3: // Modifier une facture
                {
                    int codeFacture;
                    cout << "Saisir le code de la facture a modifier : ";
                    cin >> codeFacture;
                    modifierFacture(factures,codeFacture);
                    break;
                }
            case 4: // Afficher les factures
                afficher_vector_Facture(factures);
                break;
            case 5: // Afficher les clients sans paiement
                afficher_clients_sans_paiement(factures);
                break;
            case 6: // Afficher les factures d'aujourd'hui
                afficher_Factures_aujourdhui(factures);
                break;
            case 0: // Quitter
                cout << "Programme termine." << std::endl;
                break;
            default:
                cout << "Choix invalide. Veuillez reessayer." << std::endl;
        }

    } while (choice != 0);
return 1;
}
