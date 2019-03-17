#include <stdlib.h>

#include <stdio.h>
#include <string.h>
#include "dfa.h"
#include <unistd.h>


void IP(char* c, int* P ){
	char tmp[65];
	tmp[64]='\0';
	//strcpy(tmp,c);
	for(int i=0;i<64;i++){
		if(c[i]=='\0')printf("ip:%d\n",P[i]-1);
		tmp[i]=c[P[i]-1];
	}
	strncpy(c,tmp,64);
	
	//printf("ip : %s\n",c);
}


void P(char* c, int* P ){
	char tmp[33];
	tmp[32]='\0';
	//strcpy(tmp,c);
	for(int i=0;i<32;i++){
		if(c[i]=='\0')printf("p:%d\n",P[i]-1);
		tmp[i]=c[P[i]-1];
	}
	strncpy(c,tmp,33);
	
	//printf("ip : %s\n",c);
}


void Pc1(char* c, int* P,char* res ){
	//printf("key %s",c);
	char tmp[57];
	tmp[56]='\0';
	//strcpy(tmp,c);
	for(int i=0;i<56;i++){
		if(c[i]=='\0')printf("pc1:%d\n",P[i]-1);
		tmp[i]=c[P[i]-1];
	}
	strncpy(res,tmp,57);
	
	//printf("ip : %s\n",c);
}


void Pc2(char* c, int* P,char* res ){
	char tmp[49];
	tmp[48]='\0';
	//strcpy(tmp,c);
	for(int i=0;i<48;i++){
		if(c[i]=='\0')printf("pc2:%d\n",P[i]-1);
		tmp[i]=c[P[i]-1];
	}
	strncpy(res,tmp,49);
	
	//printf("ip : %s\n",c);
}

void PermInv(char* c, int* P ){
	char tmp[33];
	tmp[32]='\0';
	//strcpy(tmp,c);
	for(int i=0;i<32;i++){
		if(c[i]=='\0')printf("pinv:%d i %d\n",P[i]-1,i);
		tmp[P[i]-1]=c[i];
	}
	strncpy(c,tmp,32);
	
	//printf("ip : %s\n",c);
}

void Pc2inv(char* c, int* P ){
	char tmp[57]="xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\0";
	//strcpy(tmp,c);
	for(int i=0;i<48;i++){
		if(c[i]=='\0')printf("pc2inv:%d i %d\n",P[i]-1,i);
		tmp[P[i]-1]=c[i];
	}
	strncpy(c,tmp,57);
	
	//printf("ip : %s\n",c);
}


void Pc1inv(char* c, int* P ){
	char tmp[65]="pppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp\0";
	tmp[64]='\0';
	//strcpy(tmp,c);
	for(int i=0;i<56;i++){
		if(c[i]=='\0')printf("pc1inv:%d i %d\n",P[i]-1,i);
		tmp[P[i]-1]=c[i];
	}
	strncpy(c,tmp,65);
	
	//printf("ip : %s\n",c);
}


void Exp(char* c, int* P ){
	//printf("ipc : %s\n",c);
	char tmp[49];
	tmp[48]='\0';
	//strcpy(tmp,c);
	for(int i=0;i<48;i++){
		//if(c[i]=='\0')printf("p:%d\n",P[i]-1);
		tmp[i]=c[P[i]-1];
	}

	strncpy(c,tmp,49);

	
	//printf("ipt : %s\n",tmp);
}



void dectobin4(char* res,int e){
	if(e-8>=0){res[0]='1';e=e-8;}else res[0]='0';
	if(e-4>=0){res[1]='1';e=e-4;}else res[1]='0';
	if(e-2>=0){res[2]='1';e=e-2;}else res[2]='0';
	if(e-1>=0){res[3]='1';e=e-1;}else res[3]='0';
	res[4]='\0';
}



void Sboxes(int Sb[4][16], char* bin,char * res){
	int outer=0;
	if(bin[0]=='1')outer+=2;
	if(bin[5]=='1')outer+=1;
	int inner=0;
	if(bin[1]=='1')inner+=8;
	if(bin[2]=='1')inner+=4;
	if(bin[3]=='1')inner+=2;
	if(bin[4]=='1')inner+=1;

	dectobin4(res,Sb[outer][inner]);



}


int addonebin(char * e, int length){
	int r=1;
	int i=length-1;
	//printf("av %s\n",e );
	while(r==1 && i>=0){
		if(e[i]=='0'){
			//printf("ucu\n");
			e[i]='1';
			r--;
		}
		else{
			e[i]='0';

		}
	i--;
		
	}
	//printf("ap %s\n",e );
	if(r==1)return 1;
	return 0;
}










void GetFaute(char** fautes){

	FILE* f =fopen("msg", "r");
	if (f==NULL){printf("pb fichier");exit(0);}
	for(int i=0;i<32;i++){
		fgets(fautes[i],20,f);
		fautes[i][16]='\0';
	}

	fclose(f);

}


void hextobin(char* hex,char bin[65] ){ //taille 16,64
	//bin="heye";
	 //printf("%s\n",hex);
	 for(int i=0; i<16; i++){
	 	//printf("coucou");
        switch(hex[i])	{
            case '0':
                strcat(bin, "0000");
                break;
            case '1':
                strcat(bin, "0001");
                break;
            case '2':
            	strcat(bin, "0010");
				break;
            case '3':
                strcat(bin, "0011");
                break;
            case '4':
                strcat(bin, "0100");
                break;
            case '5':
          	      strcat(bin, "0101");
                break;
            case '6':
                strcat(bin, "0110");
                break;
            case '7':
                strcat(bin, "0111");
                break;
            case '8':
                strcat(bin, "1000");
                break;
            case '9':
                strcat(bin, "1001");
                break;
            case 'a':
            case 'A':
                strcat(bin, "1010");
                break;
            case 'b':
            case 'B':
                strcat(bin, "1011");
                break;
            case 'c':
            case 'C':
                strcat(bin, "1100");
                break;
            case 'd':
            case 'D':
                strcat(bin, "1101");
                break;
            case 'e':
            case 'E':
                strcat(bin, "1110");
                break;
            case 'f':
            case 'F':
                strcat(bin, "1111");
                break;
             case '\0':
             	 printf("null char\n");
             	break;
            default:
                printf("Invalid hexadecimal input.%d\n",hex[i]);
        }

    }
       bin[64]='\0';
       //printf(" ...  bhex :%s\n",bin);
}

char XOR(char a,char b){
	//printf("oui ...");
	char tmp;
	switch (a){
		case '0':
			//if(b!='0' && b!='1') printf("erreur XOR: %c",b);exit(0); 
			tmp=b;
			break;
		case '1':
			if (b=='1')tmp='0';
			else if (b=='0')tmp='1';
			else{

			 printf("erreur XOR b: %c",b);
			 exit(0);
			 } 
			break;
		case '\0':
			printf("anti 0");exit(0);
			break;

		default:
			printf("erreur XOR a: %c",a);
			exit(0);
	}
	return tmp;
}



void discardSkeys(subkeys* Skeys,subkeys *Skeys2){
	char * Pkeys=malloc(sizeof(char)*7*20);
	//for(int i=0;i<20;i++)Pkeys[i]=malloc(sizeof(char)*20);
	int nkey=0;
	for(int i = 0; i < Skeys->nbkey; ++i){
		int j=0;
		int test=1;
		while (j < Skeys2->nbkey && test){
			if(strcmp(Skeys->tab[i],Skeys2->tab[j])==0){
				strcat(Pkeys,Skeys->tab[i]);
				test=0;
				nkey++;
			}
			j++;	
		}
	}
	//printf("Pkeys %s\n",Pkeys);
	for(int i=0;i<nkey;i++){
		strncpy(Skeys->tab[i],Pkeys+i*6,6);
		Skeys->tab[i][7]='\0';

	}
	Skeys->nbkey=nkey;
	free(Pkeys);



}



void find_subskeys(int ifaute,char R16E[32][49],char R16[49],char L16F[32][33], int Sbox[4][16],subkeys *Skeys,int nsb){


		int t=0;
		char skey[7]="000000\0";
		while(t==0){
			//printf("%d\n",i);		
			//faute
			char sub[7];
			char res[5];
			strncpy(sub,R16E[ifaute]+6*nsb,6); // changer en fonction de la sbox 
			//xor ki

			//printf("xor 1\n");
			//printf("r %s\n",skey);
			//printf("r2 %s\n",sub);
			//printf("r16 %s\n",R16E[i]);
			for(int k=0;k<6;k++)sub[k]=XOR(skey[k],sub[k]);
			Sboxes(Sbox,sub,res);

			//pas faute
			char sub2[7];
			char res2[5];
			strncpy(sub2,R16+6*nsb,6);
			//printf("xor 2\n");
			for(int k=0;k<6;k++)sub2[k]=XOR(skey[k],sub2[k]);
			Sboxes(Sbox,sub2,res2);		
			


			for(int k=0;k<4;k++)res[k]=XOR(res[k],res2[k]);
			strncpy(res2,L16F[ifaute]+4*nsb,4);
			 //printf("xor 3\n");
			res[4]='\0';
			res2[4]='\0';
			//printf("r %s\n",res);
			//printf("r2 %s\n",res2);
			if(strcmp(res,res2)==0){
				printf(" potential skey %s\n",skey);
				//printf(" Skey nb  %d\n",Skeys->nbkey);
				strncpy(Skeys->tab[Skeys->nbkey],skey,7);
				Skeys->nbkey++;
			}
			//printf("%d potential skey %s\n",i,skey);
			t=addonebin(skey,6);
			//test d'equal res res2;
		}
}

subkeys* init_subkeys(){
	subkeys* Skeys=malloc(sizeof(subkeys));
	Skeys->tab=malloc(sizeof(char)*7*50);
	for (int j=0;j<50;j++)Skeys->tab[j]=malloc(sizeof(char)*7);
	Skeys->nbkey=0;
	return Skeys;

	//Skeys=malloc(sizeof(subkeys));
	//Skeys->tab=malloc(sizeof(char)*7*20);
	
	//Skeys->nbkey=0;

}

char* findKey(int nSbox,int Sbox[4][16], char L16F[32][33],char R16E[32][49],char R16[49]){
		//à adapter pour chaque Sbox
		printf("nsb  %d\n",nSbox); 
	subkeys* Skeys=init_subkeys();
	subkeys* Skeys2=init_subkeys();
	printf("%c  %d\n",L16F[1][4],nSbox);
	int test=0;
	for(int i=0;i<32;i++){
				printf("i  %d",i);
		if(L16F[i][0+(4*nSbox)]=='1' || L16F[i][1+(nSbox*4)]=='1' || L16F[i][2+(nSbox*4)]=='1' || L16F[i][3+(nSbox*4)]=='1'){ //0,1,2,3 + (#sbox-1)*4 
			switch(test){
				case 0:
					find_subskeys(i,R16E,R16,L16F,Sbox,Skeys,nSbox); // faire passer la sbox en arg 
					test++;
					break;
				case 1:
					find_subskeys(i,R16E,R16,L16F,Sbox,Skeys2,nSbox);
					discardSkeys(Skeys,Skeys2);
					//for (int k=0;k<Skeys->nbkey;k++)printf("Skeys p %s\n",Skeys->tab[k]);
						Skeys2->nbkey=0;
					break;
				default:
					printf("unknown test case");
					exit(0);

			}
		}
		if(Skeys->nbkey==1){
			printf("subkey S%d : %s\n",nSbox+1,Skeys->tab[0]);
			return Skeys->tab[0];  //return Skeys->tab[0] 
		}
	}
}


void addukbits(char * k, char* ukbits,char * ktmp){
	
	strncpy(ktmp,k,65);
	int i=0;
	int j=0;
	while(i<64 && j<8){
		if(ktmp[i]=='x'){
			ktmp[i]=ukbits[j];
			j++;
		}
		i++;
	}

}

void addparity(char * k){
	char tmp[7];
	for(int i=0;i<8;i++){
		int par=0;
		strncpy(tmp,k+i*8,7);
		for( int j=0;j<8;j++){
			if(tmp[j]=='1')par++;
		}
		k[7+8*i]=(par%2==0)?'1':'0';

	}

}

void F(char * Ri,int E[48],int PS[32],
		int S1[4][16],int S2[4][16],int S3[4][16],int S4[4][16],int S5[4][16],int S6[4][16],int S7[4][16],int S8[4][16],char k[48]){
	
	char R[49];

	strncpy(R,Ri,32);
	R[48]='\0';
	Exp(R,E);
	for(int i=0;i<48;i++){
		R[i]=XOR(R[i],k[i]);
	}
	char tmp[33]="\0";
	tmp[32]='\0';
	char res[5];
	char tmp2[7];
	tmp2[6]='\0';
	
	strncpy(tmp2,R,6);
	Sboxes(S1,tmp2,res);
	strcat(tmp,res);
	tmp[4]='\0';

	strncpy(tmp2,R+6,6);
	Sboxes(S2,tmp2,res);
	strcat(tmp,res);
	tmp[8]='\0';

	strncpy(tmp2,R+12,6);
	Sboxes(S3,tmp2,res);
	strcat(tmp,res);
	tmp[12]='\0';

	strncpy(tmp2,R+18,6);
	Sboxes(S4,tmp2,res);
	strcat(tmp,res);
	tmp[16]='\0';

	strncpy(tmp2,R+24,6);
	Sboxes(S5,tmp2,res);
	strcat(tmp,res);
	tmp[20]='\0';

	strncpy(tmp2,R+30,6);
	Sboxes(S6,tmp2,res);
	strcat(tmp,res);
	tmp[24]='\0';

	strncpy(tmp2,R+36,6);
	Sboxes(S7,tmp2,res);
	strcat(tmp,res);
	tmp[28]='\0';

	strncpy(tmp2,R+42,6);
	Sboxes(S8,tmp2,res);
	strcat(tmp,res);
	tmp[32]='\0';

	strncpy(Ri,tmp,33);

	//appliquer PS
	P(Ri,PS);


}

void lshift(char* c,char* d){
	char tmp[29];
	char tmp2[29];
	tmp[28]='\0';
	tmp2[28]='\0';
	for(int i=0;i<28;i++){
		tmp[i]=c[(i+1)%28];
		tmp2[i]=d[(i+1)%28];
	}
	strncpy(c,tmp,29);
	strncpy(d,tmp2,29);
}

void keyschedule(char ki[16][49],char* k,int PC1[56],int PC2[48]){
		
		char tmp[57];
		Pc1(k,PC1,tmp);
		char C[29];
		char D[29];
		strncpy(C,tmp,28);
		strncpy(D,tmp+28,28);
		C[28]='\0';
		D[28]='\0';
	for(int i=0;i<16;i++){
		
		if(i==0 ||i==1 ||i==8 ||i==15)lshift(C,D);
		else{lshift(C,D);lshift(C,D);}
		strncpy(tmp,C,28);
		tmp[28]='\0';
		strcat(tmp,D);
		Pc2(tmp,PC2,ki[i]);


	}


}

void DES( char * clair,char * k, char * res,int E[48],int PS[32],int P[64], int Pinv[64],int PC1[56],int PC2[48],
		int S1[4][16],int S2[4][16],int S3[4][16],int S4[4][16],int S5[4][16],int S6[4][16],int S7[4][16],int S8[4][16]){
	





	char ki[16][49];
	keyschedule(ki,k,PC1,PC2);
	printf("key scheduled : k16 %s\n", ki[15]);
	char bclair[65]="";
	hextobin(clair,bclair);
	IP(bclair,P);
	char Li[65];
	strncpy(Li,bclair,32);
	Li[32]='\0';
	char Ri[65];
	strncpy(Ri,bclair+32,32);
	Ri[32]='\0';
	
	printf("bclair %s\n",bclair );	
	printf("init  %s  %s\n",Li,Ri);
	for(int i=0;i<15;i++){

		char tmp[49];
		strncpy(tmp,Ri,33);
		F(Ri,E,PS,S1,S2,S3,S4,S5,S6,S7,S8,ki[i]);
	//	printf("get f  %s  %s\n",Ri,Li);
		for(int j=0;j<32;j++){Ri[j]=XOR(Ri[j],Li[j]);}
		
		strncpy(Li,tmp,33);
	}
	char tmp[49];
		strncpy(tmp,Ri,33);	
		F(Ri,E,PS,S1,S2,S3,S4,S5,S6,S7,S8,ki[15]);
		for(int j=0;j<32;j++){Li[j]=XOR(Ri[j],Li[j]);}
		strncpy(Ri,tmp,33);
		Li[32]='\0';
		Ri[32]='\0';

	strcat(Li,Ri);
	Li[64]='\0';
	IP(Li,Pinv);
	strncpy(res,Li,65);



}





int main(int argc, char const *argv[])
{
	
	int P[64] = {
		58,50,42,34,26,18,10,2,
 		60,52,44,36,28,20,12,4,
		62,54,46,38,30,22,14,6,
		64,56,48,40,32,24,16,8,
		57,49,41,33,25,17,9,1,
		59,51,43,35,27,19,11,3,
		61,53,45,37,29,21,13,5,
		63,55,47,39,31,23,15,7}; 

	int PInv[64] ={
		40,8,48,16,56,24,64,32,
		39,7,47,15,55,23,63,31,
		38,6,46,14,54,22,62,30,
		37,5,45,13,53,21,61,29,
		36,4,44,12,52,20,60,28,
		35,3,43,11,51,19,59,27,
		34,2,42,10,50,18,58,26,
		33,1,41,9,49,17,57,25,
	};


	int PS[32] ={
		16,7,20,21,
		29,12,28,17,
		1,15,23,26,
		5,18,31,10,
		2,8,24,14,
		32,27,3,9,
		19,13,30,6,
		22,11,4,25, 
	};

	int E[48]= {
		32,1,2,3,4,5,
		4,5,6,7,8,9,
		8,9,10,11,12,13,
		12,13,14,15,16,17,
		16,17,18,19,20,21,
		20,21,22,23,24,25,
		24,25,26,27,28,29,
		28,29,30,31,32,1,
	};


	int S1[4][16]= {
		{14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},
		{0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
		{4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},
		{15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13},

	};
	
	int S2[4][16]={
		{15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10},
		{3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5},
		{0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15},
		{13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9},
	};

	int S3[4][16]={
		{10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8},
		{13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1},
		{13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7},
		{1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12},
	};
	int S4[4][16]={
		{7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15},
		{13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9},
		{10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4},
		{3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14},
		
	};
	int S5[4][16]={
		{2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9},
		{14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6},
		{4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14},
		{11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3},
	};
	int S6[4][16]={
		{12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11},
		{10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8},
		{9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6},
		{4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13},
	};
	int S7[4][16]={
		{4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1},
		{13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6},
		{1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2},
		{6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12},
	};
	int S8[4][16]={
		{13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7},
		{1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2},
		{7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8},
		{2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11},
	};	

	int PC1[56]={
		57,49,41,33,25,17,9,
		1,58,50,42,34,26,18,
		10,2,59,51,43,35,27,
		19,11,3,60,52,44,36,
		63,55,47,39,31,23,15,
		7,62,54,46,38,30,22,
		14,6,61,53,45,37,29,
		21,13,5,28,20,12,4
	};

	int PC1c[28] ={
		57,49,41,33,25,17,9,
		1,58,50,42,34,26,18,
		10,2,59,51,43,35,27,
		19,11,3,60,52,44,36
	};

	int PC1d[28]={
		63,55,47,39,31,23,15,
		7,62,54,46,38,30,22,
		14,6,61,53,45,37,29,
		21,13,5,28,20,12,4
	};

	int PC2[48]={
		14,17,11,24,1,5,
		3,28,15,6,21,10,
		23,19,12,4,26,8,
		16,7,27,20,13,2,
		41,52,31,37,47,55,
		30,40,51,45,33,48,
		44,49,39,56,34,53,
		46,42,50,36,29,32,
	};



	// int *** S=malloc(sizeof(int**)*8);
	//int S[8][4][16]={S1,S2,S3,S4,S5,S6,S7,S8};
	 //printf("%d",S[0][1][0]);
	// S[0]=S1;
	// S[1]=S2;
	// S[2]=S3;	
	// S[3]=S4;
	// S[4]=S5;
	// S[5]=S6;
	// S[6]=S7;
	// S[7]=S8;


	char clair[17] = "8C8F2C52C85702EC\0";
	char juste[17] = "2C11704D50320988\0";

	char** fautes=malloc(sizeof(char*)*32);
	for(int i=0;i<32;i++){fautes[i]=malloc(sizeof(char)*17);}
	
	GetFaute(fautes);

	char** Bfautes=malloc(sizeof(char*)*32);
	for(int i=0;i<32;i++){Bfautes[i]=malloc(sizeof(char)*65);}
	//char Bfautes[32][65];

	for(int i=0;i<32;i++){
		strcpy(Bfautes[i],"");
		printf("fautes: %s\n",fautes[i]);
		hextobin(fautes[i],Bfautes[i]);
		//printf("%d bfautes %s\n",i,Bfautes[i]);
		IP(Bfautes[i],P);
		printf("%d bfautes %s\n",i,Bfautes[i]);
		//free(Bfautes[i]);
	}

	char Bjuste[65];
	strcpy(Bjuste,"\0");
	hextobin(juste,Bjuste);

	
	IP(Bjuste,P);
	printf("juste %s\n",Bjuste);
	char L16[33];
	for(int i=0;i<32;i++){L16[i]=Bjuste[i];}
	L16[32]='\0';				//i-32
	
	printf("L16 : %s\n",L16);	
	char L16F[32][33];
	for(int i=0;i<32;i++){
		for(int j=0;j<32;j++){
			L16F[i][j]=XOR(L16[j],Bfautes[i][j]);
		}								  //32+j
		L16F[i][32]='\0';
	}

	for(int i=0;i<32;i++){
		printf("L %d %s\n",i,L16F[i]);
	}


	char R16[49];
	L16[32]='\0';
	for(int i=0;i<32;i++){R16[i]=Bjuste[i+32];}
	
	char R16F[32][33];
	for(int i=0;i<32;i++){
		for(int j=0;j<32;j++){
			R16F[i][j]=XOR(R16[j],Bfautes[i][32+j]);
		}								  //32+j
		R16F[i][32]='\0';
	}

	char R16E[32][49];
	for(int i=0;i<32;i++){
		for(int j=0;j<32;j++){
			R16E[i][j]=Bfautes[i][32+j];
		}								  //32+j
		R16E[i][32]='\0';
		printf("%d R16E %s\n",i,R16E[i]);
	}


	for(int i=0;i<32;i++){
		printf("R %d %s\n",i,R16F[i]);
	}
//analyser autre partie pour voir où sont les fautes !!!



	//test f function

	char a[65];
	char b[65];
	strncpy(a,Bfautes[0],32);
	strncpy(b,Bfautes[0]+32,32);
	F(b,E,PS,S1,S2,S3,S4,S5,S6,S7,S8,"100101000101111011110011001101010010010111001101");
	a[32]='\0';
	PermInv(a,PS);
	b[32]='\0';
	printf("a\n%s\n%s\n",a,b);
	

	printf("XOR 0 0   %c\n",XOR('0','0'));
	printf("XOR 0 1   %c\n",XOR('0','1'));
	printf("XOR 1 0   %c\n",XOR('1','0'));
	printf("XOR 1 1   %c\n",XOR('1','1'));
	for(int i=0;i<32;i++){
		PermInv(L16F[i],PS);
		printf("Ps L16f %d : %s\n",i,L16F[i]);
	}


	Exp(R16,E);
	for(int i=0;i<32;i++){
		//printf("%d bfautes %s\n",i,Bfautes[i]);
		Exp(R16E[i],E);
		//printf("%d R16E %s\n",i,R16E[i]);
	}

	char k16[65]="\0";
	strcat(k16,findKey(0,S1, L16F,R16E,R16));
	strcat(k16,findKey(1,S2, L16F,R16E,R16));
	strcat(k16,findKey(2,S3, L16F,R16E,R16));
	strcat(k16,findKey(3,S4, L16F,R16E,R16));
	strcat(k16,findKey(4,S5, L16F,R16E,R16));
	strcat(k16,findKey(5,S6, L16F,R16E,R16));
	strcat(k16,findKey(6,S7, L16F,R16E,R16));
	strcat(k16,findKey(7,S8, L16F,R16E,R16));
	k16[48]='\0';
	printf("k16: %s\n",k16);
	Pc2inv(k16,PC2);
	printf("ktmp pc2: %s\n",k16);
	Pc1inv(k16,PC1);


	char ukbits[9]="00000000\0";
	//addonebin(ukbits,8);

	//addukbits(k16,ukbits);
	//addparity(k16);
	int cpt=1;
	printf("ktmp: %s\n",k16);
	char res[65];
	int test=1;
	char ktmp[65];


	char toto[28]="0101010101010101010101010101";
	char tata[28]="1000000000000000000000000000";
	lshift(toto,tata);
	printf("toto %s tata %s\n",toto,tata);

	strcpy(Bjuste,"\0");
	hextobin(juste,Bjuste);
	Bjuste[64]='\0';
	



	while(test){
		addukbits(k16,ukbits,ktmp);
		addparity(ktmp);
		printf("cpt:%d ktmp exauh: %s\n",cpt,ktmp);
		DES(clair,ktmp,res,E,PS,P,PInv,PC1,PC2,S1,S2,S3,S4,S5,S6,S7,S8);
		res[65]='\0';
		printf("%s\n%s\n",Bjuste,res);
		if (strcmp(Bjuste,res)==0){printf("K %s\n",ktmp);test=0;}
		addonebin(ukbits,8);
		printf("ukbits %s\n",ukbits);
		//addukbits(k16,ukbits);
		//addparity(k16);
		cpt++;
		if(cpt>256	){exit(0);}


	}










	//à adapter pour chaque Sbox 
	// subkeys* Skeys=init_subkeys();
	// subkeys* Skeys2=init_subkeys();
	// int test=0;
	// for(int i=0;i<32;i++){
	// 	if(L16F[i][0]=='1' || L16F[i][1]=='1' || L16F[i][2]=='1' || L16F[i][3]=='1'){ //0,1,2,3 + (#sbox-1)*4 
	// 			printf("i  %d",i);
	// 		switch(test){
	// 			case 0:
	// 				find_subskeys(i,R16E,R16,L16F,S1,Skeys); // faire passer la sbox en arg 
	// 				test++;
	// 				break;
	// 			case 1:
	// 				find_subskeys(i,R16E,R16,L16F,S1,Skeys2);
	// 				discardSkeys(Skeys,Skeys2);
	// 				for (int k=0;k<Skeys->nbkey;k++)printf("Skeys p %s\n",Skeys->tab[k]);
	// 					Skeys2->nbkey=0;
	// 				break;
	// 			default:
	// 				printf("unknown test case");
	// 				exit(0);

	// 		}
	// 	}
	// 	if(Skeys->nbkey==1)break;  //return Skeys->tab[0] 

	// }
	// printf("subkey S1 : %s\n",Skeys->tab[0]); 





//EXPension à coriiger taille pas bien 
	// func testkeys() à faire 
	//test 1 Sbox
	//for(int i=0;i<1;i++){
		// int i = 4;
		// int t=0;
		// char skey[7]="000000\0";
		// while(t==0){
		// 	//printf("%d\n",i);		
		// 	//faute
		// 	char sub[7];
		// 	char res[5];
		// 	strncpy(sub,R16E[i],6);
		// 	//xor ki

		// 	//printf("xor 1\n");
		// 	//printf("r %s\n",skey);
		// 	//printf("r2 %s\n",sub);
		// 	//printf("r16 %s\n",R16E[i]);
		// 	for(int k=0;k<6;k++)sub[k]=XOR(skey[k],sub[k]);
		// 	Sboxes(S1,sub,res);

		// 	//pas faute
		// 	char sub2[7];
		// 	char res2[5];
		// 	strncpy(sub2,R16,6);
		// 	//printf("xor 2\n");
		// 	for(int k=0;k<6;k++)sub2[k]=XOR(skey[k],sub2[k]);
		// 	Sboxes(S1,sub2,res2);		
			


		// 	for(int k=0;k<4;k++)res[k]=XOR(res[k],res2[k]);
		// 	strncpy(res2,L16F[i],4);
		// 	 //printf("xor 3\n");
		// 	res[4]='\0';
		// 	res2[4]='\0';
		// 	//printf("r %s\n",res);
		// 	//printf("r2 %s\n",res2);
		// 	if(strcmp(res,res2)==0)printf(" potential skey %s\n",skey);
		// 	//printf("%d potential skey %s\n",i,skey);
		// 	t=addonebin(skey);
		// 	//test d'equal res res2;
		//}
	//}
	






}