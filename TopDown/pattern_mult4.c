#include <stdio.h>
#include "genpat.h"

#define timestep 30000
#define delay 200000

char *inttostr(inteiro)
int inteiro;
{
	char *str;
	str = (char *) mbkalloc(32*sizeof(char));
	sprintf(str, "%d", inteiro);
	return(str);
}
int main()
{
	int i, j, k;
	int tempo = 0;
	int cout = 0;

	DEF_GENPAT("pat_multi");

	DECLAR("A", ":2", "X", IN, "3 downto 0", ""); // "a" é uma entrada de 4 bits, mostrada como hexadecimal
	DECLAR("B", ":2", "X", IN, "3 downto 0", ""); // "b" idem
	DECLAR("P", ":2", "X", OUT, "7 downto 0", ""); // "s" é uma saída
	//DECLAR("Err", ":2", "B", OUT, "", "");
	DECLAR("vdd", ":2", "B", IN, "", ""); // "Vdd" e "Vss" são 1 bit de entrada
	DECLAR("vss", ":2", "B", IN, "", ""); 

	LABEL("Prod"); // "labels" ajudam a visualizar etapas do processo
	AFFECT("0", "vdd", "0b1"); // no tempo 0, Vdd recebe "1"
	AFFECT("0", "vss", "0b0"); // e Vss recebe "0"

	for(i = 0; i<16; i++)
	{
		for(j = 0; j<16; j++)
		{
			k = i*j; // note que i = a, j = b, k = s
			//  Vamos mudar as variáveis de entrada
			AFFECT(inttostr(tempo), "a", inttostr(i));
			AFFECT(inttostr(tempo), "b", inttostr(j));
			// aumentar o tempo em um atraso
			tempo += delay;	
			// mudar a variável de saída
			AFFECT(inttostr(tempo), "P", inttostr(k));
			// continua incrementando o tempo
			tempo += timestep;
		} // final do laço de j
	} // final do laço de i
	SAV_GENPAT();
	return 0;
}

