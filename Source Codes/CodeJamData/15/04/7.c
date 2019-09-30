#include <stdio.h>

/*

6-ominoes

##
 ##
##

 #
###
 ##

#
###
 ##

 #
####
 #

 #
####
#

  #
####
#

####
 #
 #

   #
####
#

*/

int main(void) {
	int tihara_minori;
	int utida_maaya;
	if(scanf("%d",&tihara_minori)!=1)return 1;
	for(utida_maaya=0;utida_maaya<tihara_minori;utida_maaya++) {
		int noto_mamiko;
		int kitamura_eri;
		int asumi_kana;
		int kugimiya_rie;
		int mimori_suzuko=0;
		if(scanf("%d%d%d",&noto_mamiko,&kitamura_eri,&asumi_kana)!=3)return 1;
		if((kitamura_eri*asumi_kana)%noto_mamiko!=0) {
			mimori_suzuko=1;
		} else {
			if(kitamura_eri<asumi_kana) {
				kugimiya_rie=kitamura_eri;
				kitamura_eri=asumi_kana;
				asumi_kana=kugimiya_rie;
			}
			switch(noto_mamiko) {
				case 1:
					mimori_suzuko=0;
					break;
				case 2:
					mimori_suzuko=0;
					break;
				case 3:
					if(asumi_kana<2 || kitamura_eri<3)mimori_suzuko=1;
					break;
				case 4:
					/* #### */
					if(kitamura_eri<4)mimori_suzuko=1;
					/*
					 #
					###
					*/
					if(asumi_kana<=2)mimori_suzuko=1;
					break;
				case 5:
					/* ##### */
					if(kitamura_eri<5)mimori_suzuko=1;
					/*
					 #
					###
					 #
					*/
					if(asumi_kana<=2)mimori_suzuko=1;
					if(asumi_kana==3 && kitamura_eri<5)mimori_suzuko=1;
					break;
				case 6:
					/* ###### */
					if(kitamura_eri<6)mimori_suzuko=1;
					/*
					##
					 ##
					##
					*/
					if(asumi_kana<=2)mimori_suzuko=1;
					if(asumi_kana==3)mimori_suzuko=1;
					break;
				default:
					/*
					###
					# #...
					##
					*/
					mimori_suzuko=1;
					break;
			}
		}
		printf("Case #%d: %s\n",utida_maaya+1,mimori_suzuko?"RICHARD":"GABRIEL");
	}
	return 0;
}
