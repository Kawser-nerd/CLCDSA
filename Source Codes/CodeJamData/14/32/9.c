#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N_LIMIT 100
#define STR_LEN_LIMIT 100
void getAbbreviation(char *str, char *abb)
{
    int abbLen = 0;
	
    int idx = 0;
    abb[abbLen++] = str[idx];
    
	for(idx=1; str[idx]!=0; idx++){
        if(str[idx]==str[idx-1])
            continue;
        else{
            abb[abbLen++] = str[idx];
        }
    }
    abb[abbLen]=0;
}

#define TYPE0 0 // 0
#define TYPE1 1 // 1
#define TYPE2 2 // 01
#define TYPE3 3 // 10
#define TYPE4 4 // 010
#define TYPE5 5 // 101, 0101, 1010, etc

int getType(char *str, char c)
{
    int len = strlen(str), i;
    if(len==1){
	    if(str[0]==c) return TYPE1;
		else return TYPE0;
	}else if(len==2){
	    if(str[0]==c) return TYPE3;
		else if(str[1]==c) return TYPE2;
		else return TYPE0;
	}else{
	    int occurence=0, flag;
	    
		if(str[0]==c){ occurence++; flag = TYPE3;}
		if(str[len-1]==c){ occurence++; flag = TYPE2;}
		
		for(i=1;i<len-1;i++)
		    if(str[i]==c){
			    occurence++;
				flag = TYPE4;
			}
		
		if(occurence==0) return TYPE0;
		else if(occurence==1) return flag;
		else return TYPE5;
	}
}
int factorial(int n)
{
    static int f[]={1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 227020758, 178290591, 674358851, 789741546, 425606191, 660911389, 557316307, 146326063, 72847302, 602640637, 860734560, 657629300, 440732388, 459042011, 394134213, 35757887, 36978716, 109361473, 390205642, 486580460, 57155068, 943272305, 14530444, 523095984, 354551275, 472948359, 444985875, 799434881, 776829897, 626855450, 954784168, 10503098, 472639410, 741412713, 846397273, 627068824, 726372166, 318608048, 249010336, 948537388, 272481214, 713985458, 269199917, 75195247, 286129051, 595484846, 133605669, 16340084, 996745124, 798197261, 286427093, 331333826, 536698543, 422103593, 280940535, 103956247, 172980994, 108669496, 715534167, 518459667, 847555432, 719101534, 932614679, 878715114, 661063309, 562937745, 472081547, 766523501, 88403147, 249058005, 671814275, 432398708, 753889928, 834533360, 604401816, 187359437, 674989781, 749079870, 166267694, 296627743, 586379910, 119711155, 372559648, 765725963, 275417893, 990953332, 104379182, 437918130};;
	if(n<=100) return f[n];
	else{ printf("JIZZ-too big"); exit(1); }
}
int multi(int a, int b)
{
    return ( ((long long int)(a) * (long long int)(b)) % 1000000007 );
}
int process()
{
    int N;
    char dict[N_LIMIT+1][STR_LEN_LIMIT+1];
    scanf("%d", &N);
    int i;
	for(i=0; i<N; i++){
        scanf("%s", dict[i]);
	}

    char abb[N_LIMIT+1][STR_LEN_LIMIT+1];
    for(i=0; i<N; i++){
        getAbbreviation(dict[i], abb[i]);
    }
	
	int ans=1, alphabet, j;
	for(alphabet=0; alphabet<26; alphabet++){
#ifdef TEST
	    printf("---%d---\n", ans);
#endif
	    int typeBook[5][N_LIMIT+1], typeBookLen[5]={0};
	    for(i=0; i<N; i++){
		    int type = getType(abb[i], alphabet+'a');
#ifdef TEST
			printf("=%c: %s %d=\n", alphabet+'a', abb[i], type);
#endif
			if(type==TYPE5) return 0;
			if(type!=TYPE0) typeBook[type][typeBookLen[type]++] = i;
		}
		if(typeBookLen[TYPE4]>=1){
		    if(typeBookLen[TYPE1]+typeBookLen[TYPE2]+
			   typeBookLen[TYPE3]+typeBookLen[TYPE4] != 1)
			    return 0;
			else
			    continue;
		} else if(typeBookLen[TYPE2]>1){
		    return 0;
		} else if(typeBookLen[TYPE3]>1){
		    return 0;
		} else if(typeBookLen[TYPE2]==1 && typeBookLen[TYPE3]==1){
		    char mergeStr[STR_LEN_LIMIT+1];
			strcpy(mergeStr, abb[typeBook[TYPE2][0]]);
			strcpy(mergeStr+strlen(mergeStr)-1, abb[typeBook[TYPE3][0]]);
			ans = multi(ans, factorial(typeBookLen[TYPE1]) );
			for(i=1; i<5; i++)
			    for(j=0; j<typeBookLen[i]; j++)
				    abb[typeBook[i][j]][0]=0;
			strcpy(abb[typeBook[TYPE2][0]], mergeStr);
		} else if(typeBookLen[TYPE2]==1 && typeBookLen[TYPE3]==0){
		    ans = multi(ans, factorial(typeBookLen[TYPE1]) );
			for(i=1; i<5; i++){
			    if(i==TYPE2) continue;
			    for(j=0; j<typeBookLen[i]; j++)
				    abb[typeBook[i][j]][0]=0;
			}
		} else if(typeBookLen[TYPE2]==0 && typeBookLen[TYPE3]==1){
		    ans = multi(ans,  factorial(typeBookLen[TYPE1]) );
			for(i=1; i<5; i++){
			    if(i==TYPE3) continue;
			    for(j=0; j<typeBookLen[i]; j++)
				    abb[typeBook[i][j]][0]=0;
			}
		} else if(typeBookLen[TYPE2]==0 && typeBookLen[TYPE3]==0){
		    ans = multi(ans, factorial(typeBookLen[TYPE1]) );
			for(j=1; j<typeBookLen[TYPE1]; j++)
				abb[typeBook[TYPE1][j]][0]=0;
		} else{
		    printf("JIZZ");
			for(i=0; i<5; i++)printf("%d ", typeBookLen[i]);
		    exit(1);
		}
	}
	
	int nonEmptyCnt = 0;
    for(i=0; i<N; i++)
	    if(strlen(abb[i])!=0) nonEmptyCnt++;
#ifdef TEST
	printf("xxx %d xxx\n", nonEmptyCnt);
#endif
	
	return multi(ans, factorial(nonEmptyCnt) );
}
int main()
{
    int caseNum;
    scanf("%d", &caseNum);
	int i;
    for(i=1; i<=caseNum; i++){
        int ans = process();
        printf("Case #%d: %d\n", i, ans);
    }
    return 0;
}
