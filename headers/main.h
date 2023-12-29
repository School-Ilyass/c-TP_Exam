#include<iostream>
#include<vector>	
#include<math.h>	
#include<limits>
#include<chrono>
#include<ctime>
#include <iomanip>
#include <string>


using namespace std;



class Produit{
	private:
		int *ID;
		string *nom,*description;
		float * prix,*qte;
		
	public:
		// * Contrusteur
		Produit(int ID=0, string nom=" ",string description=" ",float prix=0,float qte=0)
		{
			this->ID=new int(ID);
			this->nom=new string(nom);
			this->description=new string(description);
			this->prix=new float(prix);
			this->qte=new float(qte);
			
		}

    	//* constructeur de copie (reference)
		Produit(const Produit &other) 
		{
    		this->ID = new int(*other.ID);
   			this->nom = new string(*other.nom);
   			this->description = new string(*other.description);
   			this->prix = new float(*other.prix);
    		this->qte = new float(*other.qte);
		}

		// * Destructeur
		~Produit()
		{
			delete ID;
			delete nom;
			delete description;
			delete prix;
			delete qte;
			
		}

		// * Operateur pour comparer 2 objet produit
		Produit& operator=(const Produit &other) {
		// pour qu on peut faire produit1=produit2
		if (this != &other) 
		{	//pour eviter des problemes potentielle de l'allocation de la memoire
			delete ID;
			delete nom;
			delete description;
			delete prix;
			delete qte;
			ID = new int(*other.ID);
			nom = new string(*other.nom);
			description = new string(*other.description);
			prix = new float(*other.prix);
			qte = new float(*other.qte);
		}
		return *this;
		}

		// * Operateur pour cin un objet
		friend istream &operator>>(istream &input, Produit &produit) {
			//pour ajouter la possibiliter de faire cin>>Produit;
			cout << "Saisir l'ID du produit:"<<endl;
			input >> *produit.ID;

			cout << "Saisir le nom du produit:"<<endl;
			input.ignore();
			getline(input, *produit.nom);

			cout << "Saisir la description du produit: "<<endl;
			getline(input, *produit.description);

			cout << "Saisir le prix du produit: "<<endl;
			input >> *produit.prix;

			cout << "Saisir la quantite du produit: "<<endl;
			input >> *produit.qte;

			return input;
		}

		// * Operateur pour cout un objet
		friend ostream &operator <<(ostream &output, const Produit &produit)
		{ //pour cout<<Produit;
			output<<"l ID du Produit : "<<*produit.ID <<endl;
			output<<"le nom du Produit : "<<*produit.nom<<endl;
			output<<"la description du Produit : "<<*produit.description<<endl;
			output<<"le prix du Produit : "<<*produit.prix<<endl;
			output<<"la quantite du Produit : "<<*produit.qte<<endl;
			return output;
		}

		// * Getters
		int getID() const {
			return *ID;
		}
		string getNom() const {
			return *nom;
		}
		string getDescription() const {
			return *description;
		}
		float getPrix() const {
			return *prix;
		}
		float getQte() const {
			return *qte;
		}


		// * Setters
		void setID(int ID){
			*this->ID=ID;
		}
		void setNom(string nom){
			*this->nom=nom;
		}
		void setDescription(string description){
			*this->description=description;
		}
		void setPrix(float prix){
			*this->prix=prix;
		}
		void setQte(float qte){
			*this->qte=qte;
		}

		// *Modifier le produit 
		void modifier(){

			int V=1;
			int first_time=0;
			do{	
				
				if(first_time==0)
				{
					cin.ignore();
					cout<<"taper 1 pour modifier l ID"<<endl<<"taper 2 pour modifier le nom"<<endl<<"taper 3 pour modifier la description"<<endl;
					cout<<"taper 4 pour modifier le prix"<<endl<<"taper 5 pour modifier la qte"<<endl<<"taper 6 pour modifier tout"<<endl;
					cout<<"TAPER 0 POUR QUITTER"<<endl;
					cin>>V;
					first_time++;
				}
				else
				{
					cout<<"modifier encore? taper de 1 a 6 sinon taper 0"<<endl;
					cin>>V;
				}
				
			switch(V)
			{
				case 0: //quitter
					break;
				case 1: cout<<"saisir la nouvelle ID"<<endl<<endl;
						cin>>*this->ID;
						break;
				case 2: cout<<"saisir le nouveau nom"<<endl<<endl;
						cin.ignore();
						getline(cin,*this->nom);
						
						break;
				case 3: cout<<"saisir la nouvelle description"<<endl<<endl;
						cin.ignore();
						getline(cin,*this->description);
						break;
				case 4: cout<<"saisir le nouveau prix"<<endl<<endl;
						cin>>*this->prix;
						break;
				case 5: cout<<"saisir la nouvelle qte"<<endl<<endl;
						cin>>*this->qte;
						break;
				case 6: 
						cout<<"saisir la nouvelle ID"<<endl<<endl;
						cin>>*this->ID;
						cout<<"saisir le nouveau nom"<<endl<<endl;
						cin.ignore();
						getline(cin,*this->nom);
						cout<<"saisir la nouvelle description"<<endl<<endl;
						getline(cin,*description);
						cout<<"saisir le nouveau prix"<<endl<<endl;
						cin>>*this->prix;
						cout<<"saisir la nouvelle qte"<<endl<<endl;
						cin>>*this->qte;
						cout<<"Modification terminer! tapper 0 si vous voulez quitter"<<endl<<endl;
				break;
				default:
					cout<<"taper 1 pour modifier l ID, taper 2 pour modifier le nom, taper 3 pour modifier la description"<<endl;
					cout<<"taper 4 pour modifier le prix, taper 5 pour modifier la qte,taper 6 pour modifier tout"<<endl;
					cout<<"TAPER 0 POUR QUITTER"<<endl;
				}
			}while(V!=0);
	}

		// * Verifie 2 products using id
		bool verifie(vector<Produit> P1)
		{
			for(int i=0;i<P1.size();i++)
				{
					if(*P1.at(i).ID==*this->ID)
					{
						return true;
					}
				}
			return false;
		}

		// * lister les produits
		void listerP(vector<Produit> P1)
			{ //afficher toutes les produits
				for(int i=0;i<P1.size();i++)
					{
						cout<<endl;
						cout<<"le produit numero :"<<i+1<<endl;
						
						cout<<P1.at(i);
					}
			}

		};

// * Operateur pour suprimmer le produit par reference 
vector<Produit>& supprimer(vector<Produit>& P1, int ID) 
{
		Produit P(ID); //just testing if the ID exists or not
		if (!P.verifie(P1)) {
			cout << "ID introuvable" << endl;
			return P1;
		}

		for (int i = 0; i < P1.size(); i++) {
			if (P1.at(i).getID() == ID) {
				P1.erase(P1.begin() + i);
				cout << "Le Produit ID=" << ID << " est supprime" << endl;
				break;
			}
		}
		return P1;
}

class Client{
	private:
	int *ID;
	string *nom,*prenom,*AD;
	// static int cp_Client;
	public:

		// * Contructeur d'initialisation de la class Client
		Client(int ID=0,string nom=" ",string prenom=" ",string AD=" ")
		{
			this->ID=new int(ID);
			this->nom=new string(nom);
			this->prenom=new string(prenom);
			this->AD=new string(AD);
			// cp_Client++;
		}

		// * Contructeur de copie de la class Client
		Client(const Client &other) 
		{
    // constructeur de copie
    		this->ID = new int(*other.ID);
   			this->nom = new string(*other.nom);
   			this->prenom = new string(*other.prenom);
   			this->AD = new string(*other.AD);
		}

		// * Operateur qui compare 2 Client
        Client& operator=(const Client &other) 
		{
			// pour qu on peut faire client1=client2
			if (this != &other) 
			{	//pour eviter des problemes potentielle de l'allocation de la memoire
				delete ID;
				delete nom;
				delete prenom;
				delete AD;
				ID =new int(*other.ID);
				nom =new string(*other.nom);
				prenom =new string(*other.prenom);
				AD=new string(*other.AD);
			return *this; 
			}
    	}

		// * Operateur qui permet l'insertion des valuers au Client::obj
		friend istream &operator>>(istream &input, Client &client) 
			{
			//pour ajouter la possibiliter de faire cin>>Client;
			cout << "ID du Client: "<<endl;
			input >> *client.ID;
			input.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "nom du Client: "<<endl;
			input.ignore();
			getline(input, *client.nom);

			cout << "prenom du Client: "<<endl;
			getline(input, *client.prenom);

			cout << "AD du Client: "<<endl;
			getline(input, *client.AD);
			return input;
			}

		
		// * Operateur qui permet l'affichage des valuers au Client::obj
		friend ostream &operator <<(ostream &output, const Client &client)
		{ //pour cout<<Client;
			output<<"Entree l ID du Client : "<<*client.ID <<endl;
			output<<"Entree le nom du Client : "<<*client.nom<<endl;
			output<<"Entree le prenom du Client : "<<*client.prenom<<endl;
			output<<"Entree l AD du Client : "<<*client.AD<<endl;
			return output;
		}
		
		// * Destructeur
		~Client()
			{
			delete ID;
			delete nom;
			delete prenom;
			delete AD;
			// cp_Client--;
			}

		// * Getters
		int getID() const
			{
			return *ID;
			}
		string getNom() const
			{
			return *nom;
			}
		string getPrenom() const
			{
			return *prenom;
			}
		string getAD() const
			{
			return *AD;
			}

		
		// * Setters
		void setID(int ID)
			{
			*this->ID=ID;
			}
		void setNom(string Nom)
			{
			*this->nom=Nom;
			}
		void setPrenom(string prenom)
			{
			*this->prenom=prenom;
			}
		void setAD(string AD)
			{
			*this->AD=AD;
			}

		// * Modifuer le client
		void Modifier()
		{
		int choice;
			int index=0;
			do{
				
				if(index==0)
				{
				cout<<"taper 1 pour modifier l ID"<<endl<<"taper 2 pour modifier le nom"<<endl<<"taper 3 pour modifier le prenom"<<endl;
				cout<<"taper 4 pour modifier l AD"<<endl<<"taper 5 pour modifier tout"<<endl;
				cout<<"TAPER 0 POUR QUITTER"<<endl;
				cin>>choice;
				index++;
				}
				else
				{
				cout<<"modifier encore? retapper 1 a 5 sinon taper 0"<<endl;
				cin>>choice;
				}
				
			switch(choice)
			{
				case 0: //quitter
					break;
				case 1: cout<<"saisir la nouvelle ID"<<endl<<endl;
						cin>>*this->ID;
						break;
				case 2: cout<<"saisir le nouveau nom"<<endl<<endl;
						cin.ignore();
						getline(cin,*this->nom);
						
						break;
				case 3: cout<<"saisir le nouveau prenom"<<endl<<endl;
						cin.ignore();
						getline(cin,*this->prenom);
						break;
				case 4: cout<<"saisir la nouvelle AD"<<endl<<endl;
						cin.ignore();
						getline(cin,*this->AD);
						break;
				case 5: 
						cout<<"saisir la nouvelle ID"<<endl<<endl;
						cin>>*this->ID;
						cout<<"saisir le nouveau nom"<<endl<<endl;
						cin.ignore();
						getline(cin,*this->nom);
						cout<<"saisir le nouveau prenom"<<endl<<endl;
						getline(cin,*this->prenom);
						cout<<"saisir la nouvelle AD"<<endl<<endl;
						cin>>*this->AD;
						cout<<"Modification terminer! tapper 0 si vous voulez quitter"<<endl<<endl;
				break;
				default:
					cout<<"taper 1 pour modifier l ID"<<endl<<"taper 2 pour modifier le nom"<<endl<<" taper 3 pour modifier le prenom"<<endl;
					cout<<"taper 4 pour modifier l AD"<<endl<<"taper 5 pour modifier tout"<<endl;
					cout<<"TAPER 0 POUR QUITTER"<<endl;
				}
			}while(choice!=0);
}
};
// int Client::cp_Client=0;

class Facture{
	private:
		int *code;
		Client *C;
		vector<Produit> P;
		struct tm *date;
		bool *etat;
	public:
		//  * Constructeur d'initialisation
		Facture(int code=0,bool etat=false)
			{
				
				
				int V=1,i=0;
				this->code=new int(code);
				this->C=new Client;
				cin >> *(this->C);
				

    			chrono::system_clock::time_point now = chrono::system_clock::now();
				
    			time_t now_c = chrono::system_clock::to_time_t(now);

				this->date=new struct tm();
				*this->date=*localtime(&now_c);
				this->etat=new bool(etat);

				int Index=0;
				do{
					if(Index==0)
						{	
						cout<<"taper 1 si vous voulez inserer le produit N:"<<i+1<<endl<<"sinon taper 0 pour quitter"<<endl;
						cin>>V;
						Index++;
						}
					else
						{
						cout<<"taper 1 si vous voulez inserer un autre produit N:"<<i+1<<endl<<"sinon taper 0 pour quitter"<<endl;
						cin>>V;
						}
					switch(V)
						{
						case 0:
						break;
						case 1:cout<<"Pour le produit N:"<<i+1<<endl;
								Produit produit;
								cin>>produit;
								P.push_back(produit);
								break;
						}
					i++;
				}while(V!=0);
			
			}
		
		// * Constructeur de copie
		Facture(const Facture &other) 
		{
    // constructeur de copie
    		this->code = new int(*other.code);
			// Get the current system time
    		chrono::system_clock::time_point now = chrono::system_clock::now();
			// Convert the system time to a time_t object
    		time_t now_c = chrono::system_clock::to_time_t(now);
   			this->date = new struct tm();
			*this->date=*localtime(&now_c);
   			this->etat = new bool(*other.etat);
   			this->C = new Client(*other.C);
			this->P.assign(other.P.begin(), other.P.end());
		}
		
		
		// * Destricteur
		~Facture()
		{
			delete code;
			delete C;
			P.clear();
			delete date;
			delete etat;
		
		}
		
		
		// * Operateur pour comparer 2 facture
		Facture& operator=(const Facture &other) 
		{
		// pour qu on peut faire Facture1=Facture2
		if (this != &other) 
			{	//pour eviter des problemes potentielle de l'allocation de la memoire
			delete code;
			delete C;
			P.clear();
			delete date;
			delete etat;
			this->code = new int(*other.code);
			// Get the current system time
			chrono::system_clock::time_point now = chrono::system_clock::now();
			// Convert the system time to a time_t object
			time_t now_c = chrono::system_clock::to_time_t(now);
			this->date = new struct tm();
			*this->date=*localtime(&now_c);
			this->etat = new bool(*other.etat);
			this->C = new Client(*other.C);
			this->P.assign(other.P.begin(), other.P.end());
			}
			return *this;
		}
		
		// * Operateur d'input
		friend	istream &operator >>(istream& input, const Facture &facture) 
		{
			cout << "saisir le code de la facture: ";
			input >> *facture.code;
			input.ignore();

			// temp actuelle
			chrono::system_clock::time_point now = chrono::system_clock::now();
			// Convert the system time to a time_t object
			time_t now_c = chrono::system_clock::to_time_t(now);
			*facture.date= *localtime(&now_c);

			cout << "saisir l etat de la facture:(0:non paye; 1:paye) " << endl;
			cin >> *facture.etat;
			return input;
		}
		
		
		// * Operateur d'output
		friend ostream &operator <<(ostream &output, const Facture &facture)
		{ 	//pour cout<<Facture;
			output<<"le code de la Facture : "<<*facture.code <<endl;
			char buffer[80]; //put_time n a pas march� sur mon compilateur j ai utiliser cette methode
    		strftime(buffer, sizeof(buffer), "%Y-%m-%d", facture.date); 
			cout << "Current Date and Time: " << buffer << endl;
    		output<<"l etat de la facture :"<<*facture.etat<<endl;
    		output<<"le client : "<<*facture.C<<endl;
			if (!facture.P.empty())
			{
			for(int i=0;i< facture.P.size();i++)
				{
					output<<"pour le produit P"<<i+1<<" :"<<facture.P.at(i)<<endl;
				}
			}
			else
			{
				output <<"aucun Produit"<<endl;
			}
			
			return output;
		}
		
		// * Getters
		int getCode()const {
			return *code;
		}
		
		Client getC() const {
			return *C;
		}
		
		struct tm getDate() const{
			return *date;
		}
		bool getEtat() const{
			return *etat;
		}
		
		//  * Setters
		void setCode(int code) {
			*this->code=code;
		}
		void setEtat(bool etat){
			*this->etat=etat;
		}
		void setC(Client C){
			*this->C=C;
		}


		bool verifieFP(int const &ID) const
			{
				for(int i=0;i<P.size();i++)
				{
					if(P.at(i).getID()==ID)
					{
						return true;
					}
				}
				return false;
			}	


		void ajouterFP(Produit const  &P1)
		{
			if(this->verifieFP(P1.getID()))
			this->P.push_back(P1);
			else
			cout<<"l'ID de cette produit deja existe"<<endl;
		}
		void modifierFP(int const ID)
		{
			if(!(this->verifieFP(ID)))
				{
					cout<<"le produit n existe pas"<<endl;
				}
			else
				{	int i;
					for(i=0;i<this->P.size();i++)
						{
							if(P.at(i).getID()==ID)
								{
									break;
								}
						}//la position du produit a chercher
					P.at(i).modifier();
				}
		}
		void modifierFC()
		{
			this->C->Modifier(); //easiest function of my life
		}
		double total()
		{
			double T=0;
			for(int i=0;i < P.size();i++)
				{
					T=T + P.at(i).getPrix();
				}
			return T;
		}
		void rechercher_Prix(double const &Prix)
		{	int first_time=0;
			for(int i=0;i<P.size();i++)
				{
					if(P.at(i).getPrix() < Prix)
						{	if(first_time==0)
							{
								cout<<"les produits qui ont un prix inferieur a "<<Prix<<" sont :"<<endl;
								first_time++;
							}
							
							cout<<"Produit : "<<P.at(i).getNom()<<" Prix : "<<P.at(i).getPrix()<<endl;
						}
				}
		}
		bool verifieF(vector<Facture> F1)
		{
			for(int i=0;i<F1.size();i++)
				{
					if(*F1.at(i).code==*this->code)
					{
						return true;
					}
				}
			return false;
		}
		bool verifieC(vector<Facture> F1)
		{
			if(this->verifieF(F1))
				{
					cout<<"le client a pass� une facture de cette liste"<<endl;
					return true;
				}
			else{
					cout<<"le client n a pas pass� une facture de cette liste"<<endl;
					return false;
				}
		}
		void modifierEtat(vector<Facture> F1)
		{
			if(this->verifieF(F1))
				{
					cout<<"la Facture du client appartient a la liste "<<endl;
					
				}
				else
				{
					cout<<"la Facture du client n'appartient pas a la liste"<<endl;
				}
				cout<<"modifier la facture?"<<endl<<"1:oui"<<endl<<"0:non"<<endl;
				int V;
				cin>> V;
					do
					{
						cout<<"saisir le nouveau etat de la facture: 1:paye; 0:non paye"<<endl;
						cin>>*this->etat;
						cout<<endl<<"Valider la modification :" <<endl<<"taper 0 pour valider la modification sinon taper 1 pour quitter"<<endl;
						cin>> V;
					}while(V!=0);
			
		}
		void ajouterFF(vector<Facture> &F1)
		{
			if(!this->verifieF(F1))
				{
					cout<<"cette facture existe deja dans la liste"<<endl;
				}
			else{
					F1.push_back(*this);
				}
		}
		void modifierQtePF()
		{
			int V=0;
			if(*this->etat)
				{
					cout<<"[Erreur] : le client a deja paye"<<endl;
				}
			else{
				int ID;
				int j=-1;
				cout<<"qu elle produit a modifier?"<<endl;
				cin>>ID;
				for(int i=0;i<this->P.size();i++)
					{
						if(this->P.at(i).getID()==ID)
							{
								j=i;
							}
					}
				if(j==-1)
				{
					cout<<"ID du produit introuvable"<<endl;
				}
				else
				{
				do
				{
					cout<<"la modification du produit ID="<<ID<<" : "<<endl;
					this->P.at(j).modifier();
					cout<<"confirme la modification?"<<endl<<" oui:1"<<endl<<"non:0"<<endl;
					cin>> V;
				}while(V!=0);	
				}
				
			}
			
		}
		void supprimerPF()
			{
				int ID;
				cout<<"saisir l ID du produit a supprime"<<endl;
				cin>>ID;
				this->P=supprimer(this->P, ID);
			}

		bool aujourdhui() const {
					// temp actuelle
					std::time_t now = std::time(nullptr);
					std::tm* currentDate = std::localtime(&now);

					// comparaison de la date actuelle
					return (
						date->tm_mday == currentDate->tm_mday &&
						date->tm_mon == currentDate->tm_mon &&
						date->tm_year == currentDate->tm_year
					);
				}

	};
