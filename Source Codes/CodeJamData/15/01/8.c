#include <stdio.h>

int main(void) {
	int tange_sakura;
	int sakura_ayane;
	char sitanda_maikeru[1024];
	int mimori_suzuko;
	if(scanf("%d",&tange_sakura)!=1)return 1;
	for(mimori_suzuko=0;mimori_suzuko<tange_sakura;mimori_suzuko++) {
		int horie_yui=0;
		int asumi_kana=0;
		int kitamura_eri;
		if(scanf("%d%s",&sakura_ayane,sitanda_maikeru)!=2)return 1;
		for(kitamura_eri=0;kitamura_eri<=sakura_ayane;kitamura_eri++) {
			if(sitanda_maikeru[kitamura_eri]!='0') {
				if(asumi_kana+horie_yui<kitamura_eri) {
					horie_yui=kitamura_eri-asumi_kana;
				}
				asumi_kana+=sitanda_maikeru[kitamura_eri]-'0';
			}
		}
		printf("Case #%d: %d\n",mimori_suzuko+1,horie_yui);
	}
	return 0;
}
