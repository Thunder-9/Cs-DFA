#ifndef DFA_H
#define DFA_H 

struct Subkeys{
	char** tab;
	int nbkey;

}typedef subkeys;

void IP(char* c, int* P );
void PermInv(char* c, int* P );
void Exp(char* c, int* P );
void dectobin4(char* res,int e);
void Sboxes(int Sb[4][16], char* bin,char * res);
int addonebin(char * e,int length);
void GetFaute(char** fautes);
void hextobin(char* hex,char bin[65]);
char XOR(char a,char b);
void find_subskeys(int ifaute,char R16E[32][49],char R16[49],char L16F[32][33], int Sbox[4][16],subkeys *Skeys,int nsb);
subkeys* init_subkeys();
char *findKey(int nSbox,int Sbox[4][16], char L16F[32][33],char R16E[32][49],char R16[49]);
void Pc1inv(char* c, int* P );
void Pc2inv(char* c, int* P );
void addukbits(char * k, char* ukbits,char* ktmp);
void addparity(char * k);
void F(char * Ri,int E[48],int PS[32],
		int S1[4][16],int S2[4][16],int S3[4][16],int S4[4][16],int S5[4][16],int S6[4][16],int S7[4][16],int S8[4][16],char k[48]);
void lshift(char* c,char* d);
void keyschedule(char ki[16][49],char* k,int PC1[56],int PC2[48]);
void DES( char * clair,char * k, char * res,int E[48],int PS[32],int P[64], int Pinv[64],int PC1[56],int PC2[48],
		int S1[4][16],int S2[4][16],int S3[4][16],int S4[4][16],int S5[4][16],int S6[4][16],int S7[4][16],int S8[4][16]);
#endif