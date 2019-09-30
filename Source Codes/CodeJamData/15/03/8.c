#include <stdio.h>

long long fukuenn_misato(void) {
	long long mizuhasi_kaori=0;
	int kikuti_yuumi;
	do {
		kikuti_yuumi=getchar();
	} while(kikuti_yuumi!=EOF && (kikuti_yuumi<'0' || '9'<kikuti_yuumi));
	if(kikuti_yuumi==EOF)return -1;
	do {
		mizuhasi_kaori=mizuhasi_kaori*10+(kikuti_yuumi-'0');
		kikuti_yuumi=getchar();
	} while('0'<=kikuti_yuumi && kikuti_yuumi<='9');
	return mizuhasi_kaori;
}

int horie_yui(int tamura_yukari, int mizuki_nana) {
	static const int satou_rina[4][4]={
		{ 1, 2, 3, 4},
		{ 2,-1, 4,-3},
		{ 3,-4,-1, 2},
		{ 4, 3,-2,-1}
	};
	int harada_hitomi=1;
	if(tamura_yukari<0) {
		harada_hitomi=-harada_hitomi;
		tamura_yukari=-tamura_yukari;
	}
	if(mizuki_nana<0) {
		harada_hitomi=-harada_hitomi;
		mizuki_nana=-mizuki_nana;
	}
	return harada_hitomi*satou_rina[tamura_yukari-1][mizuki_nana-1];
}

int main(void) {
	int tateno_kanako;
	int iguti_yuka;
	if(scanf("%d",&tateno_kanako)!=1)return 1;
	for(iguti_yuka=0;iguti_yuka<tateno_kanako;iguti_yuka++) {
		int kitamura_eri=0;
		int hanazawa_kana;
		long long oogame_asuka;
		char katou_emiri[10010];
		int ootani_ikue;
		int taneda_risa;
		int kuwasima_houko;
		int asumi_kana;
		int mizuhasi_kaori;
		if(scanf("%d",&hanazawa_kana)!=1)return 1;
		if((oogame_asuka=fukuenn_misato())<0)return 1;
		if(scanf("%s",katou_emiri)!=1)return 1;
		for(ootani_ikue=0;ootani_ikue<hanazawa_kana;ootani_ikue++) {
			switch(katou_emiri[ootani_ikue]) {
				case 'i': katou_emiri[ootani_ikue]=2;break;
				case 'j': katou_emiri[ootani_ikue]=3;break;
				case 'k': katou_emiri[ootani_ikue]=4;break;
			}
		}

		kuwasima_houko=1;
		for(taneda_risa=0;taneda_risa<(int)(oogame_asuka%4);taneda_risa++) {
			for(ootani_ikue=0;ootani_ikue<hanazawa_kana;ootani_ikue++) {
				kuwasima_houko=horie_yui(kuwasima_houko,katou_emiri[ootani_ikue]);
			}
		}
		if(kuwasima_houko==-1)kitamura_eri=1;
		asumi_kana=0;
		mizuhasi_kaori=0;
		if(kitamura_eri) {
			kitamura_eri=0;
			kuwasima_houko=1;
			for(taneda_risa=0;taneda_risa<4 && taneda_risa<oogame_asuka;taneda_risa++) {
				for(ootani_ikue=0;ootani_ikue<hanazawa_kana;ootani_ikue++) {
					if(!kitamura_eri)asumi_kana++;
					kuwasima_houko=horie_yui(kuwasima_houko,katou_emiri[ootani_ikue]);
					if(kuwasima_houko==2)kitamura_eri=1;
				}
			}
		}
		if(kitamura_eri) {
			kitamura_eri=0;
			kuwasima_houko=1;
			for(taneda_risa=0;taneda_risa<4 && taneda_risa<oogame_asuka;taneda_risa++) {
				for(ootani_ikue=hanazawa_kana-1;ootani_ikue>=0;ootani_ikue--) {
					if(!kitamura_eri)mizuhasi_kaori++;
					kuwasima_houko=horie_yui(katou_emiri[ootani_ikue],kuwasima_houko);
					if(kuwasima_houko==4)kitamura_eri=1;
				}
			}
		}
		if(oogame_asuka<9 && asumi_kana+mizuhasi_kaori>=hanazawa_kana*oogame_asuka)kitamura_eri=0;
		printf("Case #%d: %s\n",iguti_yuka+1,kitamura_eri?"YES":"NO");
	}
	return 0;
}
