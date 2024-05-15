#include <genlib.h>

int main(void){


	GENLIB_DEF_LOFIG("mult4_genlib");
//_________________________Pinos externos _________________________________________________________________
    
    GENLIB_LOCON("b0", IN, "b0"); //Entradas b  (4 bits)
	GENLIB_LOCON("b1", IN, "b1");
    GENLIB_LOCON("b2", IN, "b2");
    GENLIB_LOCON("b3", IN, "b3");

    GENLIB_LOCON("a0", IN, "a0"); //Entradas a (4 bits)
	GENLIB_LOCON("a1", IN, "a1");
    GENLIB_LOCON("a2", IN, "a2");
    GENLIB_LOCON("a3", IN, "a3");

    GENLIB_LOCON("p0", OUT, "p0"); //Saida 8 bits
    GENLIB_LOCON("p1", OUT, "p1");
    GENLIB_LOCON("p2", OUT, "p2");
    GENLIB_LOCON("p3", OUT, "p3");
    GENLIB_LOCON("p4", OUT, "p4");
    GENLIB_LOCON("p5", OUT, "p5");
    GENLIB_LOCON("p6", OUT, "p6");
    GENLIB_LOCON("p7", OUT, "p7");

    GENLIB_LOCON("vdd", IN, "vdd");
    GENLIB_LOCON("vss", IN, "vss");
/*
    // Saida dos inversores
    int i; //i4 é p0
    for (i = 1; i <= 3; i++) {
        GENLIB_LOCON(GENLIB_NAME("i%d",i), OUT, GENLIB_NAME("i%d",i));
    }
    
    for (i = 5; i <= 16; i++) {
        GENLIB_LOCON(GENLIB_NAME("i%d",i), OUT, GENLIB_NAME("i%d",i));
    }
    
    // Todas saidas nand2
    for (i = 1; i <= 52; i++) {
        GENLIB_LOCON(GENLIB_NAME("n%d",i), OUT, GENLIB_NAME("n%d",i));
    }

    // Saidas dos XOR2 (x6 é p1)
    for (i = 1; i <= 5; i++) {
        GENLIB_LOCON(GENLIB_NAME("x%d",i), OUT, GENLIB_NAME("x%d",i));
    }
    // x12 é p2
    for (i = 7; i <= 11; i++) {
        GENLIB_LOCON(GENLIB_NAME("x%d",i), OUT, GENLIB_NAME("x%d",i));
    }

    //x18 é p3
    for (i = 13; i <= 17; i++) {
        GENLIB_LOCON(GENLIB_NAME("x%d",i), OUT, GENLIB_NAME("x%d",i));
    }

    //x24 é p4
    for (i = 19; i <= 23; i++) {
        GENLIB_LOCON(GENLIB_NAME("x%d",i), OUT, GENLIB_NAME("x%d",i));
    }

    // Todas as saidas do NAND3
    for (i = 1; i <= 9; i++) {
        GENLIB_LOCON(GENLIB_NAME("n3_%d",i), OUT, GENLIB_NAME("n3_%d",i));
    }
    //n3_10 é p7
    for (i = 11; i <= 12; i++) {
        GENLIB_LOCON(GENLIB_NAME("n3_%d",i), OUT, GENLIB_NAME("n3_%d",i));
    }
*/



    //_________________________Instancias internas___________________________________

        //TODAS AS PORTAS NAND + INVERSOR
    GENLIB_LOINS("na2_x1", "nan1", "b3", "a0", "n1", "vdd", "vss", NULL);
    GENLIB_LOINS("inv_x1", "inv1", "n1", "i1", "vdd", "vss", NULL);

    GENLIB_LOINS("na2_x1", "nan2", "b2", "a0", "n2", "vdd", "vss", NULL);
    GENLIB_LOINS("inv_x1", "inv2", "n2", "i2", "vdd", "vss", NULL);

    GENLIB_LOINS("na2_x1", "nan3", "b1", "a0", "n3", "vdd", "vss", NULL);
    GENLIB_LOINS("inv_x1", "inv3", "n3", "i3", "vdd", "vss", NULL);

    GENLIB_LOINS("na2_x1", "nan4", "b0", "a0", "n4", "vdd", "vss", NULL);
    GENLIB_LOINS("inv_x1", "inv4", "n4", "p0", "vdd", "vss", NULL);

    GENLIB_LOINS("na2_x1", "nan5", "b2", "a1", "n5", "vdd", "vss", NULL);
    GENLIB_LOINS("inv_x1", "inv5", "n5", "i5", "vdd", "vss", NULL);
	
	 //BLOCO 1
    GENLIB_LOINS("xr2_x1", "xor1", "i5", "i1", "x2", "vdd", "vss", NULL);
    //GENLIB_LOINS("xr2_x1", "xor2", "x1", "vss", "x2", "vdd", "vss", NULL);

    //GENLIB_LOINS("na2_x1", "nan8", "i5", "vss", "n8", "vdd", "vss", NULL);
    //GENLIB_LOINS("na2_x1", "nan9", "i1", "vss", "n9", "vdd", "vss", NULL);
    GENLIB_LOINS("na2_x1", "nan10", "i5", "i1", "n10", "vdd", "vss", NULL);
	GENLIB_LOINS("inv_x1", "inv_n3_1", "n10", "n3_1", "vdd", "vss", NULL); 

    //GENLIB_LOINS("na3_x1", "nan3_1", "n8", "n9", "n10", "n3_1", "vdd", "vss", NULL);


    GENLIB_LOINS("na2_x1", "nan6", "b1", "a1", "n6", "vdd", "vss", NULL);
    GENLIB_LOINS("inv_x1", "inv6", "n6", "i6", "vdd", "vss", NULL);

	//BLOCO 2
    GENLIB_LOINS("xr2_x1", "xor3", "i6", "i2", "x4", "vdd", "vss", NULL);
    //GENLIB_LOINS("xr2_x1", "xor4", "x3", "vss", "x4", "vdd", "vss", NULL);

    //GENLIB_LOINS("na2_x1", "nan11", "i6", "vss", "n11", "vdd", "vss", NULL);
    //GENLIB_LOINS("na2_x1", "nan12", "i2", "vss", "n12", "vdd", "vss", NULL);
    GENLIB_LOINS("na2_x1", "nan13", "i6", "i2", "n13", "vdd", "vss", NULL);
	GENLIB_LOINS("inv_x1", "inv_n3_2", "n13", "n3_2", "vdd", "vss", NULL);

    //GENLIB_LOINS("na3_x1", "nan3_2", "n11", "n12", "n13", "n3_2", "vdd", "vss", NULL);


    GENLIB_LOINS("na2_x1", "nan7", "b0", "a1", "n7", "vdd", "vss", NULL);
    GENLIB_LOINS("inv_x1", "inv7", "n7", "i7", "vdd", "vss", NULL);

	 //BLOCO 3
    GENLIB_LOINS("xr2_x1", "xor5", "i7", "i3", "p1", "vdd", "vss", NULL);
    //GENLIB_LOINS("xr2_x1", "xor6", "x5", "vss", "p1", "vdd", "vss", NULL);

    //GENLIB_LOINS("na2_x1", "nan14", "i7", "vss", "n14", "vdd", "vss", NULL);
    //GENLIB_LOINS("na2_x1", "nan15", "i3", "vss", "n15", "vdd", "vss", NULL);
    GENLIB_LOINS("na2_x1", "nan16", "i7", "i3", "n16", "vdd", "vss", NULL);
	
	GENLIB_LOINS("inv_x1", "inv_n3_3", "n16", "n3_3", "vdd", "vss", NULL);

    //GENLIB_LOINS("na3_x1", "nan3_3", "n14", "n15", "n16", "n3_3", "vdd", "vss", NULL);


    GENLIB_LOINS("na2_x1", "nan17", "b3", "a1", "n17", "vdd", "vss", NULL);
    GENLIB_LOINS("inv_x1", "inv8", "n17", "i8", "vdd", "vss", NULL);

    GENLIB_LOINS("na2_x1", "nan18", "b2", "a2", "n18", "vdd", "vss", NULL);
    GENLIB_LOINS("inv_x1", "inv9", "n18", "i9", "vdd", "vss", NULL);

	// BLOCO 4
    GENLIB_LOINS("xr2_x1", "xor7", "i9", "i8", "x7", "vdd", "vss", NULL);
    GENLIB_LOINS("xr2_x1", "xor8", "x7", "n3_1", "x8", "vdd", "vss", NULL);

    GENLIB_LOINS("na2_x1", "nan21", "i9", "n3_1", "n21", "vdd", "vss", NULL);
    GENLIB_LOINS("na2_x1", "nan22", "i8", "n3_1", "n22", "vdd", "vss", NULL);
    GENLIB_LOINS("na2_x1", "nan23", "i9", "i8", "n23", "vdd", "vss", NULL);

    GENLIB_LOINS("na3_x1", "nan3_4", "n21", "n22", "n23", "n3_4", "vdd", "vss", NULL);


    GENLIB_LOINS("na2_x1", "nan19", "b1", "a2", "n19", "vdd", "vss", NULL);
    GENLIB_LOINS("inv_x1", "inv10", "n19", "i10", "vdd", "vss", NULL);

	// BLOCO 5
    GENLIB_LOINS("xr2_x1", "xor9", "i10", "x2", "x9", "vdd", "vss", NULL);
    GENLIB_LOINS("xr2_x1", "xor10", "x9", "n3_2", "x10", "vdd", "vss", NULL);

    GENLIB_LOINS("na2_x1", "nan24", "i10", "n3_2", "n24", "vdd", "vss", NULL);
    GENLIB_LOINS("na2_x1", "nan25", "x2", "n3_2", "n25", "vdd", "vss", NULL);
    GENLIB_LOINS("na2_x1", "nan26", "i10", "x2", "n26", "vdd", "vss", NULL);

    GENLIB_LOINS("na3_x1", "nan3_5", "n24", "n25", "n26", "n3_5", "vdd", "vss", NULL);

	

    GENLIB_LOINS("na2_x1", "nan20", "b0", "a2", "n20", "vdd", "vss", NULL);
    GENLIB_LOINS("inv_x1", "inv11", "n20", "i11", "vdd", "vss", NULL);

	// BLOCO 6
    GENLIB_LOINS("xr2_x1", "xor11", "i11", "x4", "x11", "vdd", "vss", NULL);
    GENLIB_LOINS("xr2_x1", "xor12", "x11", "n3_3", "p2", "vdd", "vss", NULL);

    GENLIB_LOINS("na2_x1", "nan27", "i11", "n3_3", "n27", "vdd", "vss", NULL);
    GENLIB_LOINS("na2_x1", "nan28", "x4", "n3_3", "n28", "vdd", "vss", NULL);
    GENLIB_LOINS("na2_x1", "nan29", "i11", "x4", "n29", "vdd", "vss", NULL);

    GENLIB_LOINS("na3_x1", "nan3_6", "n27", "n28", "n29", "n3_6", "vdd", "vss", NULL);


    GENLIB_LOINS("na2_x1", "nan30", "b3", "a2", "n30", "vdd", "vss", NULL);
    GENLIB_LOINS("inv_x1", "inv12", "n30", "i12", "vdd", "vss", NULL);

    GENLIB_LOINS("na2_x1", "nan31", "b2", "a3", "n31", "vdd", "vss", NULL);
    GENLIB_LOINS("inv_x1", "inv13", "n31", "i13", "vdd", "vss", NULL);

	
    //BLOCO 7
    GENLIB_LOINS("xr2_x1", "xor13", "i13", "i12", "x13", "vdd", "vss", NULL);
    GENLIB_LOINS("xr2_x1", "xor14", "x13", "n3_4", "x14", "vdd", "vss", NULL);

    GENLIB_LOINS("na2_x1", "nan32", "i13", "n3_4", "n32", "vdd", "vss", NULL);
    GENLIB_LOINS("na2_x1", "nan33", "i12", "n3_4", "n33", "vdd", "vss", NULL);
    GENLIB_LOINS("na2_x1", "nan34", "i13", "i12", "n34", "vdd", "vss", NULL);

    GENLIB_LOINS("na3_x1", "nan3_7", "n32", "n33", "n34", "n3_7", "vdd", "vss", NULL);


    GENLIB_LOINS("na2_x1", "nan35", "b1", "a3", "n35", "vdd", "vss", NULL);
    GENLIB_LOINS("inv_x1", "inv14", "n35", "i14", "vdd", "vss", NULL);
	
	//BLOCO 8
    GENLIB_LOINS("xr2_x1", "xor15", "i14", "x8", "x15", "vdd", "vss", NULL);
    GENLIB_LOINS("xr2_x1", "xor16", "x15", "n3_5", "x16", "vdd", "vss", NULL);

    GENLIB_LOINS("na2_x1", "nan36", "i14", "n3_5", "n36", "vdd", "vss", NULL);
    GENLIB_LOINS("na2_x1", "nan37", "x8", "n3_5", "n37", "vdd", "vss", NULL);
    GENLIB_LOINS("na2_x1", "nan38", "i14", "x8", "n38", "vdd", "vss", NULL);

    GENLIB_LOINS("na3_x1", "nan3_8", "n36", "n37", "n38", "n3_8", "vdd", "vss", NULL);


    GENLIB_LOINS("na2_x1", "nan39", "b0", "a3", "n39", "vdd", "vss", NULL);
    GENLIB_LOINS("inv_x1", "inv15", "n39", "i15", "vdd", "vss", NULL);
	
	//BLOCO 9
    GENLIB_LOINS("xr2_x1", "xor17", "i15", "x10", "x17", "vdd", "vss", NULL);
    GENLIB_LOINS("xr2_x1", "xor18", "x17", "n3_6", "p3", "vdd", "vss", NULL);

    GENLIB_LOINS("na2_x1", "nan40", "i15", "n3_6", "n40", "vdd", "vss", NULL);
    GENLIB_LOINS("na2_x1", "nan41", "x10", "n3_6", "n41", "vdd", "vss", NULL);
    GENLIB_LOINS("na2_x1", "nan42", "i15", "x10", "n42", "vdd", "vss", NULL);

    GENLIB_LOINS("na3_x1", "nan3_9", "n40", "n41", "n42", "n3_9", "vdd", "vss", NULL);


    GENLIB_LOINS("na2_x1", "nan43", "b3", "a3", "n43", "vdd", "vss", NULL);
    GENLIB_LOINS("inv_x1", "inv16", "n43", "i16", "vdd", "vss", NULL);

    
    //Bloco 10
    GENLIB_LOINS("xr2_x1", "xor19", "i16", "n3_11", "x19", "vdd", "vss", NULL);
    GENLIB_LOINS("xr2_x1", "xor20", "x19", "n3_7", "p6", "vdd", "vss", NULL);

    GENLIB_LOINS("na2_x1", "nan44", "i16", "n3_7", "n44", "vdd", "vss", NULL);
    GENLIB_LOINS("na2_x1", "nan45", "n3_11", "n3_7", "n45", "vdd", "vss", NULL);
    GENLIB_LOINS("na2_x1", "nan46", "i16", "n3_11", "n46", "vdd", "vss", NULL);

    GENLIB_LOINS("na3_x1", "nan3_10", "n44", "n45", "n46", "p7", "vdd", "vss", NULL);

	
	 //Bloco 12
    //GENLIB_LOINS("xr2_x1", "xor23", "x16", "vss", "x23", "vdd", "vss", NULL);
    GENLIB_LOINS("xr2_x1", "xor24", "x16", "n3_9", "p4", "vdd", "vss", NULL);

    GENLIB_LOINS("na2_x1", "nan50", "x16", "n3_9", "n50", "vdd", "vss", NULL);
    //GENLIB_LOINS("na2_x1", "nan51", "vss", "n3_9", "n51", "vdd", "vss", NULL);
    //GENLIB_LOINS("na2_x1", "nan52", "x16", "vss", "n52", "vdd", "vss", NULL);
	GENLIB_LOINS("inv_x1", "inv_n3_12", "n50", "n3_12", "vdd", "vss", NULL);

    //GENLIB_LOINS("na2_x1", "nan3_12", "n50", "n51", "n52", "n3_12", "vdd", "vss", NULL);

    //Bloco 11
    GENLIB_LOINS("xr2_x1", "xor21", "x14", "n3_12", "x21", "vdd", "vss", NULL);
    GENLIB_LOINS("xr2_x1", "xor22", "x21", "n3_8", "p5", "vdd", "vss", NULL);

    GENLIB_LOINS("na2_x1", "nan47", "x14", "n3_8", "n47", "vdd", "vss", NULL);
    GENLIB_LOINS("na2_x1", "nan48", "n3_12", "n3_8", "n48", "vdd", "vss", NULL);
    GENLIB_LOINS("na2_x1", "nan49", "x14", "n3_12", "n49", "vdd", "vss", NULL);

    GENLIB_LOINS("na3_x1", "nan3_11", "n47", "n48", "n49", "n3_11", "vdd", "vss", NULL);


   


	

    GENLIB_SAVE_LOFIG();

   return 0;

}
