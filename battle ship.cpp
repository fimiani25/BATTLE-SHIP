//battle ship
//2 giocatori E COM
#include<iostream>
#include<string.h>
#include<ctime>		//rand
#include<cstdlib>
#include <process.h> //pulire schermo e pausa
#include<time.h>      //per passare il tempo a rand

using namespace std; //namespace

bool vinto=false;

char mat1[5][5]{{' ',' ',' ',' ',' '},{' ',' ',' ',' ',' '},{' ',' ',' ',' ',' '},{' ',' ',' ',' ',' '},{' ',' ',' ',' ',' '}};
char mat2[5][5]{{' ',' ',' ',' ',' '},{' ',' ',' ',' ',' '},{' ',' ',' ',' ',' '},{' ',' ',' ',' ',' '},{' ',' ',' ',' ',' '}};

char mat1vis[5][5]{{' ',' ',' ',' ',' '},{' ',' ',' ',' ',' '},{' ',' ',' ',' ',' '},{' ',' ',' ',' ',' '},{' ',' ',' ',' ',' '}};
char mat2vis[5][5]{{' ',' ',' ',' ',' '},{' ',' ',' ',' ',' '},{' ',' ',' ',' ',' '},{' ',' ',' ',' ',' '},{' ',' ',' ',' ',' '}};

char turno;
string nome1,nome2;
int punti1=0,punti2=0;
int nbom1=3,nbom2=3;
int ngiocatori=0;
int dif=0;

//variabili globali

//funzioni giocatori
void giocatore1();
void giocatore2();
void giocatoreCOM();

//stampa e vittoria
void stampa(){
	
	int i,j;
	system("cls");
	if(punti1==5){
		vinto=true;
		system("color ED");
		cout<<nome1<<" HAI VINTO"<<endl;
	}
	if(punti2==5){
		vinto=true;
		system("color ED");
		cout<<nome2<<" HAI VINTO"<<endl;
	}

	if(vinto==true){
		cout<<nome1<<" "<<punti1<<" - "<<nome2<<" "<<punti2<<endl<<endl;

	cout<<"mappa di "<<nome1<<endl<<endl;
	cout<<"[ ][A][B][C][D][E]"<<endl;
	for(i=0;i<5;i++){
		cout<<"["<<i+1<<"]";
		for(j=0;j<5;j++){
		cout<<"["<<mat1[i][j]<<"]";
	}
	cout<<endl;
	}

	cout<<endl<<"mappa di "<<nome2<<endl<<endl;
	cout<<"[ ][A][B][C][D][E]"<<endl;
	for(i=0;i<5;i++){
		cout<<"["<<i+1<<"]";
		for(j=0;j<5;j++){
		cout<<"["<<mat2[i][j]<<"]";
	}
	cout<<endl;
	}
	}

	if(vinto==true)
	system("pause");
	
	
	if(turno=='1' & vinto==false)
	 giocatore1();
	
	if(turno=='2' & vinto==false & ngiocatori==2)
	 giocatore2();
	 if(turno=='2' & vinto==false & ngiocatori==1)
	 giocatoreCOM();




}


//turni giocatori
void giocatore1(){
	system("color C0");
	char chi,chj;
	int i,j;					//locali a giocatore1
	
	//MAPPA
		cout<<"mappa di "<<nome2<<endl<<endl;
		cout<<"[ ][A][B][C][D][E]"<<endl;
	for(i=0;i<5;i++){
		cout<<"["<<i+1<<"]";
		for(j=0;j<5;j++){
		cout<<"["<<mat2vis[i][j]<<"]";
	}
	cout<<endl;
	}
cout<<"navi mancanti:"<<5-punti1<<endl;
cout<<"bombe mancanti:"<<nbom1<<endl<<endl;
cout<<nome1<<" scegli dove colpire (1-5)(A-E)(righe)(colonne) "<<endl;
cin>>chi>>chj;

		i=int(chi);
		i=i-49;

		j=int(chj);
		j=j-65;
		
		//ERRORI
		if(i>4 || j>4 || i<0 || j<0){
		system("cls");
 		cout<<"ERRORE "<<endl<<endl;
		giocatore1();}

		if(mat2vis[i][j]=='X' || mat2vis[i][j]=='M' || mat2vis[i][j]=='B'){
		system("cls");
        cout<<"ERRORE "<<endl<<endl;
			giocatore1();}

//NAVE MANCATA
if(mat2[i][j]==' '){
 mat2[i][j]='M';
 mat2vis[i][j]='M';
 turno='2';
 system("cls");
 cout<<"mappa di "<<nome2<<endl<<endl;
 cout<<"[ ][A][B][C][D][E]"<<endl;
	for(i=0;i<5;i++){
		cout<<"["<<i+1<<"]";
		for(j=0;j<5;j++){
		cout<<"["<<mat2vis[i][j]<<"]";
	}
	cout<<endl;
	}
	cout<<"navi mancanti:"<<5-punti1<<endl;
	cout<<"bombe mancanti:"<<nbom1<<endl<<endl;
	cout<<nome1<<" nave mancata"<<endl<<endl;
	system("pause");
 stampa();
 }
 //NAVE COLPITA
else if(mat2[i][j]=='N'){
 mat2[i][j]='X';
 mat2vis[i][j]='X';
 turno='2';
 punti1++;
 system("cls");
 cout<<"mappa di "<<nome2<<endl<<endl;
 cout<<"[ ][A][B][C][D][E]"<<endl;
	for(i=0;i<5;i++){
		cout<<"["<<i+1<<"]";
		for(j=0;j<5;j++){
		cout<<"["<<mat2vis[i][j]<<"]";
	}
	cout<<endl;
	}
	cout<<"navi mancanti:"<<5-punti1<<endl;
	cout<<"bombe mancanti:"<<nbom1<<endl<<endl;
 cout<<nome1<<" nave colpita "<<endl<<endl;
 system("pause");
 stampa();
}
//BOMBA COLPITA
else if(mat2[i][j]=='B'){
	nbom1--;
	mat2vis[i][j]='B';
	turno='2';
if(mat1[i][j]==' '){
	mat1[i][j]='M';
	mat1vis[i][j]='M';}
	else if(mat1[i][j]=='B'){
	mat1[i][j]='B';
	mat1vis[i][j]='B';}
	else if(mat1[i][j]=='N'){
	mat1[i][j]='X';
	mat1vis[i][j]='X';
	punti2++;}
	system("cls");
	cout<<"mappa di "<<nome2<<endl<<endl;
 cout<<"[ ][A][B][C][D][E]"<<endl;
	for(i=0;i<5;i++){
		cout<<"["<<i+1<<"]";
		for(j=0;j<5;j++){
		cout<<"["<<mat2vis[i][j]<<"]";
	}
	cout<<endl;
	}
	cout<<"navi mancanti:"<<5-punti1<<endl;
	cout<<"bombe mancanti:"<<nbom1<<endl<<endl;
	cout<<nome1<<" bomba colpita "<<endl<<endl;
 system("pause");
 stampa();}	
 //ERRORI
else{
system("cls");
 cout<<"ERRORE "<<endl<<endl;
 giocatore1();
}
}

void giocatore2(){
	system("color 90");
	char chi,chj;
	int i,j;        //locali a giocatore2
	//MAPPA
	cout<<"mappa di "<<nome1<<endl<<endl;
	cout<<"[ ][A][B][C][D][E]"<<endl;
	for(i=0;i<5;i++){
		cout<<"["<<i+1<<"]";
		for(j=0;j<5;j++){
		cout<<"["<<mat1vis[i][j]<<"]";
	}
	cout<<endl;
	}
cout<<"navi mancanti:"<<5-punti2<<endl;
cout<<"bombe mancanti:"<<nbom2<<endl<<endl;
cout<<nome2<<" scegli dove colpire (1-5)(A-E)(righe)(colonne) "<<endl;
cin>>chi>>chj;

		i=int(chi);
		i=i-49;

		j=int(chj);
		j=j-65;
		
//ERRORI
		if(i>4 || j>4 || i<0 || j<0){
		system("cls");
 		cout<<"ERRORE "<<endl<<endl;
		giocatore2();}
		if(mat1vis[i][j]=='X' || mat1vis[i][j]=='M' || mat1vis[i][j]=='B'){
		system("cls");
 		cout<<"ERRORE "<<endl<<endl;
		giocatore2();}

//NAVE MANCATA
if(mat1[i][j]==' '){
 mat1[i][j]='M';
 mat1vis[i][j]='M';
 turno='1';
 system("cls");
 cout<<"mappa di "<<nome2<<endl<<endl;
 cout<<"[ ][A][B][C][D][E]"<<endl;
	for(i=0;i<5;i++){
		cout<<"["<<i+1<<"]";
		for(j=0;j<5;j++){
		cout<<"["<<mat1vis[i][j]<<"]";
	}
	cout<<endl;
	}
	cout<<"navi mancanti:"<<5-punti2<<endl;
	cout<<"bombe mancanti:"<<nbom2<<endl<<endl;
	cout<<nome2<<" nave mancata"<<endl<<endl;
	system("pause");
 stampa();
 }
//NAVE COLPITA
else if(mat1[i][j]=='N'){
 mat1[i][j]='X';
 mat1vis[i][j]='X';
 turno='1';
 punti2++;
 system("cls");
 cout<<"mappa di "<<nome1<<endl<<endl;
 cout<<"[ ][A][B][C][D][E]"<<endl;
	for(i=0;i<5;i++){
		cout<<"["<<i+1<<"]";
		for(j=0;j<5;j++){
		cout<<"["<<mat1vis[i][j]<<"]";
	}
	cout<<endl;
	}
	
	cout<<"navi mancanti:"<<5-punti2<<endl;
	cout<<"bombe mancanti:"<<nbom2<<endl<<endl;
 cout<<nome2<<" nave colpita "<<endl<<endl;
 system("pause");
 stampa();
}
//BOMBA COLPITA
else if(mat1[i][j]=='B'){
	nbom2--;
	mat1vis[i][j]='B';
	turno='1';
if(mat2[i][j]==' '){
	mat2[i][j]='M';
	mat2vis[i][j]='M';}
	else if(mat2[i][j]=='B'){
	mat2[i][j]='B';
	mat2vis[i][j]='B';}
	else if(mat2[i][j]=='N'){
	mat2[i][j]='X';
	mat2vis[i][j]='X';
	punti1++;}
	 system("cls");
 cout<<"mappa di "<<nome1<<endl<<endl;
 cout<<"[ ][A][B][C][D][E]"<<endl;
	for(i=0;i<5;i++){
		cout<<"["<<i+1<<"]";
		for(j=0;j<5;j++){
		cout<<"["<<mat1vis[i][j]<<"]";
	}
	cout<<endl;
	}
		cout<<"navi mancanti:"<<5-punti2<<endl;
	cout<<"bombe mancanti:"<<nbom2<<endl<<endl;
	cout<<nome2<<" bomba colpita "<<endl<<endl;
 system("pause");
 stampa();}
 //ERRORI
else{
system("cls");
 cout<<"ERRORE "<<endl;
 giocatore2();
}
}


void giocatoreCOM(){
	system("color 20");
	char chi,chj;
	int i,j;        //locali a giocatore2
	//MAPPA
	cout<<"mappa di "<<nome1<<endl<<endl;
	cout<<"[ ][A][B][C][D][E]"<<endl;
	for(i=0;i<5;i++){
		cout<<"["<<i+1<<"]";
		for(j=0;j<5;j++){
		cout<<"["<<mat1vis[i][j]<<"]";
	}
	cout<<endl;
	}
cout<<"navi mancanti:"<<5-punti2<<endl;
cout<<"bombe mancanti:"<<nbom2<<endl<<endl;
cout<<nome2<<" scegli dove colpire (1-5)(A-E)(righe)(colonne) "<<endl;

i=rand()%5;
j=rand()%5;

if(rand()%10<dif-1){
while(mat1[i][j]!='N'){
i=rand()%5;
j=rand()%5;
}
}


//ERRORI
		if(i>4 || j>4 || i<0 || j<0){
		system("cls");
		giocatoreCOM();}
		if(mat1vis[i][j]=='X' || mat1vis[i][j]=='M' || mat1vis[i][j]=='B'){
		system("cls");
		giocatoreCOM();}

//NAVE MANCATA
if(mat1[i][j]==' '){
 mat1[i][j]='M';
 mat1vis[i][j]='M';
 turno='1';
 system("cls");
 cout<<"mappa di "<<nome1<<endl<<endl;
 cout<<"[ ][A][B][C][D][E]"<<endl;
	for(i=0;i<5;i++){
		cout<<"["<<i+1<<"]";
		for(j=0;j<5;j++){
		cout<<"["<<mat1vis[i][j]<<"]";
	}
	cout<<endl;
	}
	cout<<"navi mancanti:"<<5-punti2<<endl;
	cout<<"bombe mancanti:"<<nbom2<<endl<<endl;
	cout<<nome2<<" nave mancata"<<endl<<endl;
	system("pause");
 stampa();
 }
//NAVE COLPITA
else if(mat1[i][j]=='N'){
 mat1[i][j]='X';
 mat1vis[i][j]='X';
 turno='1';
 punti2++;
 system("cls");
 cout<<"mappa di "<<nome1<<endl<<endl;
 cout<<"[ ][A][B][C][D][E]"<<endl;
	for(i=0;i<5;i++){
		cout<<"["<<i+1<<"]";
		for(j=0;j<5;j++){
		cout<<"["<<mat1vis[i][j]<<"]";
	}
	cout<<endl;
	}
	
	cout<<"navi mancanti:"<<5-punti2<<endl;
	cout<<"bombe mancanti:"<<nbom2<<endl<<endl;
 cout<<nome2<<" nave colpita "<<endl<<endl;
 system("pause");
 stampa();
}
//BOMBA COLPITA
else if(mat1[i][j]=='B'){
	nbom2--;
	mat1vis[i][j]='B';
	turno='1';
if(mat1[i][j]==' '){
	mat1[i][j]='M';
	mat1vis[i][j]='M';}
	else if(mat1[i][j]=='B'){
	mat1[i][j]='B';
	mat1vis[i][j]='B';}
	else if(mat2[i][j]=='N'){
	mat1[i][j]='X';
	mat1vis[i][j]='X';
	punti1++;}
	 system("cls");
 cout<<"mappa di "<<nome1<<endl<<endl;
 cout<<"[ ][A][B][C][D][E]"<<endl;
	for(i=0;i<5;i++){
		cout<<"["<<i+1<<"]";
		for(j=0;j<5;j++){
		cout<<"["<<mat1vis[i][j]<<"]";
	}
	cout<<endl;
	}
		cout<<"navi mancanti:"<<5-punti2<<endl;
	cout<<"bombe mancanti:"<<nbom2<<endl<<endl;
	cout<<nome2<<" bomba colpita "<<endl<<endl;
 system("pause");
 stampa();}
 //ERRORI
else{
system("cls");
 giocatoreCOM();
}
}



//riempimento
void riempimento1(){
	system("color C0");
	char chi,chj;
	int i,j,k;      //locali a riempimento1
	for(k=0;k<5;k++){	
		system("cls");
		cout<<"[ ][A][B][C][D][E]"<<endl;
		for(i=0;i<5;i++){
			cout<<"["<<i+1<<"]";
		for(j=0;j<5;j++){
		cout<<"["<<mat1[i][j]<<"]";
	}
	cout<<endl;
	}

		cout<<nome1<<" dove vuoi inserire la nave n "<<k+1<<" (1-5)(A-E)(righe)(colonne)"<<endl;		//navi
		cin>>chi>>chj;

		i=int(chi);
		i=i-49;

		j=int(chj);
		j=j-65;

		if(i>4 || j>4 || i<0 || j<0)
		{
		k--;
		continue;
		}
		
		if(mat1[i][j]=='N')
		{
			k--;
			continue;
			}
        else if(mat1[i][j]=='B')
		{
			k--;
		continue;
		}

		mat1[i][j]='N';
	}
	for(k=0;k<3;k++){                                                           
		system("cls");
		cout<<"[ ][A][B][C][D][E]"<<endl;
		for(i=0;i<5;i++){
			cout<<"["<<i+1<<"]";
		for(j=0;j<5;j++){
		cout<<"["<<mat1[i][j]<<"]";
	}
	cout<<endl;
	}

		cout<<nome1<<" dove vuoi inserire la bomba n "<<k+1<<" (1-5)(A-E)(righe)(colonne)"<<endl;		//bombe
		cin>>chi>>chj;

		i=int(chi);
		i=i-49;

		j=int(chj);
		j=j-65;

		if(i>4 || j>4 || i<0 || j<0){
		k--;
		continue;}
		if(mat1[i][j]==' ')
		mat1[i][j]='B';
		else
		{
		k--;
		continue;}
	}	system("cls");
		cout<<"[ ][A][B][C][D][E]"<<endl;
		for(i=0;i<5;i++){
			cout<<"["<<i+1<<"]";
		for(j=0;j<5;j++){
		cout<<"["<<mat1[i][j]<<"]";
	}
	cout<<endl;
	}
	system("pause");
	}



void riempimento2(){
	char chi,chj;
	int i,j,k;
system("color 90");
			//locali a riempimento2
	for(k=0;k<5;k++){						
		system("cls");
		cout<<"[ ][A][B][C][D][E]"<<endl;
		for(i=0;i<5;i++){
			cout<<"["<<i+1<<"]";
		for(j=0;j<5;j++){
		cout<<"["<<mat2[i][j]<<"]";
	}
	cout<<endl;
	}

		cout<<nome2<<" dove vuoi inserire la nave n "<<k+1<<" (1-5)(A-E)(righe)(colonne)"<<endl;  //navi
			cin>>chi>>chj;

		i=int(chi);
		i=i-49;

		j=int(chj);
		j=j-65;

		if(i>4 || j>4 || i<0 || j<0){
		k--;
		continue;}
		if(mat2[i][j]=='N'){
			k--;
		continue;}
		mat2[i][j]='N';
	}
	
		for(k=0;k<3;k++){                                                           
		system("cls");
		cout<<"[ ][A][B][C][D][E]"<<endl;
		for(i=0;i<5;i++){
			cout<<"["<<i+1<<"]";
		for(j=0;j<5;j++){
		cout<<"["<<mat2[i][j]<<"]";
	}
	cout<<endl;
	}

		cout<<nome1<<" dove vuoi inserire la bomba n "<<k+1<<" (1-5)(A-E)(righe)(colonne)"<<endl;  //bombe
		cin>>chi>>chj;

		i=int(chi);
		i=i-49;

		j=int(chj);
		j=j-65;

		if(i>4 || j>4 || i<0 || j<0){
		k--;
		continue;}
		if(mat2[i][j]==' ')
		mat2[i][j]='B';
		else
		{
			k--;
		continue;}
	}system("cls");
		cout<<"[ ][A][B][C][D][E]"<<endl;
		for(i=0;i<5;i++){
			cout<<"["<<i+1<<"]";
		for(j=0;j<5;j++){
		cout<<"["<<mat2[i][j]<<"]";
	}
	cout<<endl;
	}
	system("pause");
	}
	

void riempimentoCOM(){
	char chi,chj;
	int i,j,k;
	//system("color 20");

			//locali a riempimentoCOM
			
	system("cls");	
	for(k=0;k<5;k++){						//navi
	
	   i=rand()%5;
		j=rand()%5;

		if(i>4 || j>4 || i<0 || j<0){
		k--;
		continue;}
		if(mat2[i][j]=='N'){
			k--;
		continue;}
		mat2[i][j]='N';
	}
	
		for(k=0;k<3;k++){                                                       //bombe
		
		i=rand()%5;
		j=rand()%5;

		if(i>4 || j>4 || i<0 || j<0){
		k--;
		continue;}
		if(mat2[i][j]==' ')
		mat2[i][j]='B';
		else
		{
			k--;
		continue;}
	}
	system("cls");
	
	}
	


//nomi e decidi chi inizia
int main(){
	
system("MODE con COLS=80 LINES=20");
system("TITLE   BATTLE SHIP");

	system("color F0");
	int numero;
	srand(time(NULL));
	while(ngiocatori!=1 & ngiocatori!=2){
	system("cls");                		//locale al main
	cout<<"1 o 2 giocatori"<<endl;
	cin>>ngiocatori;}
	
	if(ngiocatori==1){
	while(dif<1 || dif>10){
	system("cls");
	cout<<"scegli difficolta' 1-10"<<endl;           //difficoltà
	cin>>dif;}
	}	
		system("cls");
	//giocatore 1 nome

	cout<<"inserisci nome giocatore 1 "<<endl;
	cin>>nome1;
	riempimento1();


system("color F0");
	//giocatore 2 nome
	system("cls");
	if(ngiocatori==1){
		nome2="COM";
		riempimentoCOM();}
	else{
    cout<<"inserisci nome giocatore 2 "<<endl;
	cin>>nome2;
	riempimento2();	}

	
	 numero=rand()%2+1;            //rand genera sempre lo stesso nummero 41 resto 1+1
									//problema quasi risolto passando il tempo alla riga 105
									
	if(numero==1)
	 	turno='1';
	if(numero==2)
	 	turno='2';

	stampa();
return 0;

}


