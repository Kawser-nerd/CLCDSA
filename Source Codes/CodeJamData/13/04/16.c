/* common *********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#define ASC 0
#define DESC 1
#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<math.h>

void calc(FILE* fp_i, FILE* fp_o);
void GenerateFilename(char* out, char* in, char* add);

void GenerateFilename(char* out, char* in, char* add){
	char* p;
	sprintf(out, "%s", in);
	for(p=out+strlen(out)-1; p>=out; p--){
		if(*p=='/' )break;
		if(*p=='\\')break;
		if(*p=='.' ){*p='\0'; break;}
	}
	sprintf(out+strlen(out), "%s", add);
}

void main(int argc, char* argv[]){
	FILE* fp_i;
	FILE* fp_o;
	char fname_o[_MAX_PATH];
	GenerateFilename(fname_o, argv[1], "_out.txt");
	fp_i = fopen(argv[1], "r");
	fp_o = fopen(fname_o, "w");
	calc(fp_i, fp_o);
	fclose(fp_i);
	fclose(fp_o);
}

/******************************************************************************/

typedef struct Key Key;
typedef struct Chest Chest;
typedef struct KeyArray KeyArray;
typedef struct ChestArray ChestArray;
typedef struct ChestArrayList ChestArrayList;

struct Key{
	int rest;
	int used;
	int total;
	int numChest;
	Chest** chests;
};

struct Chest{
	Key* keyType;
	int numKey;
	Key** keys;

	int checked;
};

struct KeyArray{
	int num;
	Key data[400];
};

struct ChestArray{
	int num;
	Chest data[200];
};

struct ChestArrayList{
	int num;
	Chest* data[200];
};

void check(ChestArray* chest, KeyArray* keyType, ChestArrayList* history){
	Chest* chest_p;
	Chest** chest_pp;
	Key* key_p;
	int jj;

	printf("\n");
	printf("Chests\n");

	for(chest_p=chest->data; chest_p<chest->data+chest->num; chest_p++){
		printf("No(%2d)",       chest_p - chest->data + 1);
		printf(" checked(%c)",  (chest_p->checked==1)?'o':' ');
		printf(" keyType(%2d)", chest_p->keyType - keyType->data + 1);
		printf(" keyRest(%2d)", chest_p->keyType->rest);
		printf(" keys");
		for(jj=0; jj<chest_p->numKey; jj++){
			printf(" %2d", chest_p->keys[jj] - keyType->data + 1);
		}
		printf("\n");
	}
	printf("KeyTypes\n");
	for(key_p=keyType->data;key_p<keyType->data+keyType->num;key_p++){
		printf("No(%2d)",       key_p - keyType->data + 1);
		printf(" total(%2d)",   key_p->total);
		printf(" used(%2d)",    key_p->used);
		printf(" rest(%d)",     key_p->rest);
		printf(" chestNum(%d)", key_p->numChest);
		printf(" chests");
		for(jj=0; jj<key_p->numChest; jj++){
			printf(" %2d", key_p->chests[jj] - chest->data + 1);
		}
		printf("\n");
	}
	printf("History :");
	for(chest_pp=history->data; chest_pp<history->data+history->num; chest_pp++){
		printf(" %2d", *chest_pp - chest->data + 1);
	}
	printf("\n");
}

void update(ChestArrayList* checked, Chest* checkchest_p, KeyArray* allKeys){
	Key** key_pp;

	checkchest_p->checked = 1;
	checked->data[checked->num] = checkchest_p;
	checked->num++;

	checkchest_p->keyType->rest--;
	checkchest_p->keyType->used++;
	for(key_pp=checkchest_p->keys; key_pp<checkchest_p->keys + checkchest_p->numKey; key_pp++){
		(*key_pp)->rest++;
	}
}

void rollback(ChestArrayList* checked, Chest* checkchest_p){
	Key** key_pp;

	checkchest_p->checked = 0;
	checked->data[checked->num] = NULL;
	checked->num--;

	checkchest_p->keyType->rest++;
	checkchest_p->keyType->used--;
	for(key_pp=checkchest_p->keys; key_pp<checkchest_p->keys + checkchest_p->numKey; key_pp++){
		(*key_pp)->rest--;
	}
}

int lockcheck(ChestArray* allChest, Key* keyType_p){
	Key** key_pp;
	Chest* chest_p;

	if(keyType_p->rest  != 0) return 1;
	if(keyType_p->numChest == keyType_p->used) return 1;
	for(chest_p=allChest->data; chest_p<allChest->data+allChest->num; chest_p++){
		if(chest_p->checked==1)continue;
		if(chest_p->keyType!=keyType_p){
			for(key_pp=chest_p->keys; key_pp<chest_p->keys+chest_p->numKey; key_pp++){
				if(*key_pp==keyType_p) return 1;
			}
		}
	}
	return 0;
}

void depthsearch(ChestArrayList* history, ChestArray* allChest, KeyArray* allKeys){
	Chest* chest_p;

	//check(allChest, allKeys, history);
	for(chest_p=allChest->data; chest_p<allChest->data+allChest->num; chest_p++){
		if(chest_p->checked==1) continue;
		if(chest_p->keyType->rest==0) continue;

		update(history, chest_p, allKeys);
		if(lockcheck(allChest, chest_p->keyType)){
			depthsearch(history, allChest, allKeys);
			if(history->num == allChest->num) return;
		}
		rollback(history, chest_p);
	}
}

void calc(FILE* fp_i, FILE* fp_o){
	int T;
	int No;
	char buff[1000];
	char* tok;
	int ii;
	int jj;
	int keyNo;

	KeyArray       keyType;
	ChestArray     chest;
	ChestArrayList history;

	int initKeyNum;

	fgets(buff, sizeof(buff), fp_i);
	tok = strtok(buff, "\r\n");
	T = atoi(tok);
	for(No=1; No<=T; No++){
		printf("Case %d/%d\n", No, T);

		memset(&keyType, 0, sizeof(keyType));
		memset(&chest,   0, sizeof(chest));
		memset(&history, 0, sizeof(history));

		fgets(buff, sizeof(buff), fp_i);
		printf(buff);
		tok = strtok(buff, " \r\n");
		initKeyNum = atoi(tok);
		tok = strtok(NULL, " \r\n");
		chest.num = atoi(tok);

		// Initial Key
		fgets(buff, sizeof(buff), fp_i);
		printf(buff);
		tok = strtok(buff, " \r\n");
		for(ii=0; ii<initKeyNum; ii++){
			keyNo = atoi(tok)-1;
			keyType.data[keyNo].rest++;
			keyType.data[keyNo].total++;
			tok = strtok(NULL, " \r\n");
		}

		// Chest
		for(ii=0; ii<chest.num; ii++){
			fgets(buff, sizeof(buff), fp_i);
			printf(buff);

			tok = strtok(buff, " \r\n");
			keyNo = atoi(tok)-1;
			chest.data[ii].keyType = &(keyType.data[keyNo]);
			chest.data[ii].keyType->numChest++;

			tok = strtok(NULL, " \r\n");
			chest.data[ii].numKey = atoi(tok);
			chest.data[ii].keys = (Key**) calloc(chest.data[ii].numKey, sizeof(Key*));

			for(jj=0; jj<chest.data[ii].numKey; jj++){
				tok = strtok(NULL, " \r\n");
				keyNo = atoi(tok)-1;
				chest.data[ii].keys[jj] = &(keyType.data[keyNo]);
				keyType.data[keyNo].total++;
			}
		}

		for(ii=0; ii<400; ii++){
			if(keyType.data[ii].numChest+keyType.data[ii].total>0) keyType.num = ii;
		}
		keyType.num++;

		for(ii=0; ii<keyType.num; ii++){
			keyType.data[ii].chests = (Chest**) calloc(keyType.data[ii].numChest, sizeof(Chest*));
			keyType.data[ii].numChest = 0;
		}

		for(ii=0; ii<chest.num; ii++){
			chest.data[ii].keyType->chests[chest.data[ii].keyType->numChest] = &(chest.data[ii]);
			chest.data[ii].keyType->numChest++;
		}

		// depth search
		//check(&chest, &keyType, &history);
		history.num = 0;
		for(ii=0; ii<keyType.num; ii++){
			if(keyType.data[ii].numChest > keyType.data[ii].total){
				goto END;
			}
		}
		depthsearch(&history, &chest, &keyType);

END:
		fprintf(fp_o, "Case #%d:", No);
		if(history.num==chest.num){
			for(ii=0; ii<history.num; ii++){
				fprintf(fp_o, " %d", history.data[ii] - chest.data + 1);
				printf(" %d", history.data[ii] - chest.data + 1);
			}
		}else{
			fprintf(fp_o, " IMPOSSIBLE");
			printf(" IMPOSSIBLE");
		}
		fprintf(fp_o, "\n");
		printf("\n");
	}

	printf("finish!!");
}
