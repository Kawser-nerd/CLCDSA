#include <stdio.h>

int main(void) {
	int tamura_yukari;
	int satou_satomi;
	if(scanf("%d",&tamura_yukari)!=1)return 1;
	for(satou_satomi=0;satou_satomi<tamura_yukari;satou_satomi++) {
		int naduka_kaori;
		int murakawa_rie[1000];
		int asumi_kana;
		int tokui_sora=0;
		int kugimiya_rie;
		if(scanf("%d",&naduka_kaori)!=1)return 1;
		for(asumi_kana=0;asumi_kana<naduka_kaori;asumi_kana++) {
			if(scanf("%d",&murakawa_rie[asumi_kana])!=1)return 1;
		}
		for(asumi_kana=0;asumi_kana<naduka_kaori;asumi_kana++) {
			if(murakawa_rie[asumi_kana]>tokui_sora)tokui_sora=murakawa_rie[asumi_kana];
		}
		kugimiya_rie=tokui_sora;
		for(asumi_kana=1;asumi_kana<tokui_sora;asumi_kana++) {
			int mizuhasi_kaori=asumi_kana;
			int harada_hitomi;
			for(harada_hitomi=0;harada_hitomi<naduka_kaori;harada_hitomi++) {
				if(murakawa_rie[harada_hitomi]>asumi_kana) {
					mizuhasi_kaori+=(murakawa_rie[harada_hitomi]-1)/asumi_kana;
				}
			}
			if(mizuhasi_kaori<kugimiya_rie)kugimiya_rie=mizuhasi_kaori;
		}
		printf("Case #%d: %d\n",satou_satomi+1,kugimiya_rie);
	}
	return 0;
}
