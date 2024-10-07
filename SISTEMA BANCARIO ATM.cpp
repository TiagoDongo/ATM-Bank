//SISTEMA ATM(CAIXA ELETRONICA)

#include <stdio.h>
#include <locale.h>
#include <windows.h>
//-------------------------------------------------------------------------------------------------------------------------
struct DADOS_CLIENTE{
int senha;
int n_conta;
int saldo_bancario;
};
typedef DADOS_CLIENTE user_info;
//PS:Talvez nao fosse necessario criar uma estruta," O que esta feito,feito esta. :) "-Liedson Delgado 01:43
//(!!!)Pretendo dps implementar um prototipo de lista duplamente ligada,para retroceder a qualquer operacao ou cancelar uma operacao
//-------------------------------------------------------------------------------------------------------------------------
void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
//-------------------------------------------------------------------------------------------------------------------------
int ATM_SERVICES(user_info c_user){//Funcao que coleta os dados do cliente(ex.:senha,numero de conta,saldo bancario)

int montante_lev=0;//Montante levantado durante as opercoes
int esc_oprc;//Escolha de Operacoes a realizar;
char esc_oprc2;//Escolha de Operacoes de Operacoes de levantamento a realizar
//---------------------------
//Alteravel apenas para teste
int cdg=1234;//Supondo que esse seja a senha de um utilizador ja atribuido ao cliente previamente!!
int acc_num=246810;//Supondo que esse seja o numero de conta de um utilizador ja atribuido ao cliente previamente!!
c_user.saldo_bancario=10000;

//---------------------------
printf("\n------------------------------\nWelcome to BCV Bank Services\n------------------------------\nNÚMERO DE CONTA: ");
     scanf("%d",&c_user.n_conta);
printf("SENHA: ");
     scanf("%d",&c_user.senha);
//VERIFICAR SE A SENHA <ou> NUMERO DE CONTA ESTAO CORRETOS
if((c_user.senha==cdg) && (c_user.n_conta==acc_num)){
     printf("OK!\n");
printf("------------------------------\n<MENU>\n");        
printf("1.Consultar Saldo Disponivel \n2.Levantamento\n");
printf("\n>Escolha a opçãoo de levantamento: ");
      scanf("%d",&esc_oprc);
switch(esc_oprc){
case 1:
	//...(CONSULTAR SALDO DISPONIVEL)
	printf("O tem um montante de %d CVE na sua conta\n",c_user.saldo_bancario);
	     break;
case 2:
	//...(FAZER LEVANTAMENTO+switch com opcoes de levantamente[ex.:1000$,2000$,3000$,etc])
	printf("\n a.1000$\n b.2000$\n c.3000$\n d.5000$\n e.Outro\n");
	printf("Escolha o montante que deseja levantar: ");
	     scanf("%c",&esc_oprc2);
switch(esc_oprc2){
     case 'a':
     	printf("CVD");
	 montante_lev=1000;
			break;
     case 'b':
	 montante_lev=2000;
			break;
     case 'c':
	 montante_lev=3000;
			break;
     case 'd':
	 montante_lev=5000;
			break;
	 case 'e':
	 printf("Digite o montante que deseja levantar");
	    scanf("%d",&montante_lev);
		    break;
}
break;
default:
	 printf("OPÇÃO INVÁLIDA,TENTE NOVAMENTE!!!\n");

if (montante_lev<=c_user.saldo_bancario){
	 printf("Levantamento de %d realizado com sucesso",montante_lev);
	 c_user.saldo_bancario-=montante_lev;
	}
	else{
		printf("Saldo Bancário Indisponivel");
	}
 }
  }
else{
	 printf("O número da conta OU a senha está incorrento!!!\n");
}
return 0;
}


int main(){
	setColor(2);
setlocale(LC_ALL,"PORTUGUESE");//Caracteres do Portugues(ex.:acentos,etc)
	int cont_oprc;//Continuar Operacoes (1=SIM && 0=NAO)
	user_info c_user;
do{
ATM_SERVICES(c_user);
getchar();
printf("------------------------------\nVc deseja continuar com mais alguma operacao?\n");
     printf("(1.SIM) (2.NÃO): ");
         scanf("%d",&cont_oprc);
}
while(cont_oprc==1);
printf("\bPOR FAVOR ESPERE PELO SEU RECIBO");
return 0;
}
