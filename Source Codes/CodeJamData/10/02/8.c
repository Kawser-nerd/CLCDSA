#include <stdio.h>
#include <string.h>
#define N 1005
#define MAX 205

void IntSubtration(char *minuend, char *subtrahend, char *difference)
{
	if (strcmp(minuend, subtrahend) == 0)//如果两数相等，返回"0"
	{
		strcpy(difference, "0");
		return;
	}

	int cM[MAX] = {0};//用来存储被减数的整型数组
	int cS[MAX] = {0};//用来存储减数的整型数组
	int cD[MAX] = {0};//用来存储两数之差的整型数组
	int lenM = strlen(minuend), lenS = strlen(subtrahend);//被减数和减数字符串的长度
	int lenMin = lenM < lenS ? lenM : lenS;//两个减数的长度中的较小值
	int i;

   for (i=0; i<lenM; i++)
	   cM[i] = minuend[lenM-1-i] - '0';
   for (i=0; i<lenS; i++)
	   cS[i] = subtrahend[lenS-1-i] - '0';

	for (i=0; i<lenMin; i++)//减法运算过程
	{
		if (cM[i] >= cS[i])//被减数大于减数，直接相减
			cD[i] = cM[i] - cS[i];
		else //否则要向前借位
		{
			cD[i] = cM[i] + 10 - cS[i];
			--cM[i+1];
		}
	}

	//处理减数或被减数超出长度lenMin的部分
	int len = lenM > lenS ? lenM : lenS;
	while (i < len)
	{
		if (cM[i] >= 0)
			cD[i] = cM[i];
		else
		{
			cD[i] = cM[i] + 10;
			--cM[i+1];
		}
		i++;
	}
	while (cD[i-1] == 0)
		i--;

	int j = 0;

	int k;
	for (k=i-1; k>=0; k--,j++)//逆序存储两数之差到字符串sum
		difference[j] = cD[k] + '0';
	difference[j] = '\0';
}

//比较两个用字符串存储的超长正整数的大小，若a>b，返回1；a==b，返回0；a<b，返回-1
int compare(const char *a, const char *b)
{
	int lenA = strlen(a);
	int lenB = strlen(b);

	if (lenA != lenB)
		return lenA > lenB ? 1 : -1;
	else
		return strcmp(a, b);
}

void division(char *dividend, char *divisor, char *quotient, char *remainder)
{
	if (compare(dividend, divisor) == 0)//被除数等于除数
	{
		strcpy(quotient, "1");
		strcpy(remainder, "0");
		return ;
	}
	if (strcmp(divisor, "0") == 0 || compare(dividend, divisor) < 0)//被除数小于除数
	{
		strcpy(quotient, "0");
		strcpy(remainder, dividend);
		return ;
	}

	char buf[2] = "0";//临时数组依次存储被除数的每一位数
	int i, s, k;

	strcpy(remainder, ""); //先使product的值为空
	for (i=0,k=0; dividend[i]!='\0'; i++)
	{
		s = 0;
		buf[0] = dividend[i];
		strcat(remainder, buf);//接上被除数的一位数，改变当前余数
		while (compare(remainder, divisor) >= 0)//连减试商
		{
			s++;
			IntSubtration(remainder, divisor, remainder);
		}
		quotient[k++] = s + '0';//记录每一位得到的商值
		if (strcmp(remainder, "0") == 0)
			strcpy(remainder, ""); //使product的值为空，去掉多余的0
	}
	quotient[k] = '\0';

	//去掉多余的0
	int j;
	for (i=0; quotient[i]=='0'; i++);
	for (j=i; j<=k; j++)
		quotient[j-i] = quotient[j];
}

void IntAddition(char *augend, char *addend, char *sum)
{
	int cAug[MAX] = {0};//用来存储被加数的整型数组
	int cAdd[MAX] = {0};//用来存储加数的整型数组
	int cSum[MAX] = {0};//用来存储两数之和的整型数组
	int lenAug = strlen(augend), lenAdd = strlen(addend);//被加数和加数字符串的长度
	int lenMin = lenAug < lenAdd ? lenAug : lenAdd;//两个加数的长度中的较小值
	int i;

	//逆序复制加数和被加数到整型数组（因为加法运算是从低位开始）
	for (i=0; i<lenAug; i++)
		cAug[i] = augend[lenAug-1-i] - '0';
	for (i=0; i<lenAdd; i++)
		cAdd[i] = addend[lenAdd-1-i] - '0';

	int carry = 0;//进位
	int s = 0; //两数之和

	for (i=0; i<lenMin; i++)//加法运算过程
	{
		s = cAug[i] + cAdd[i] + carry;//两个加数和进位之和作为当前位的和
		cSum[i] = s % 10;//存储当前位
		carry = s / 10;//获取进位
	}

	//处理加数或被加数超出长度lenMin的部分
	while (i < lenAug)
	{
		s = cAug[i] + carry;
		cSum[i] = s % 10;
		carry = s / 10;
		i++;
	}

	while (i < lenAdd)
	{
		s = cAdd[i] + carry;
		cSum[i] = s % 10;
		carry = s / 10;
		i++;
	}

	if (carry > 0)//处理最后一个进位
		cSum[i++] = carry;

	int j;
	for (j=0; j<i; j++)//逆序存储两数之和到字符串sum
		sum[j] = cSum[i-1-j] + '0';
	sum[i] = '\0';
}

void IntMultiplication(char *multiplicand, char *multiplier, char *product)
{
	int cD[MAX] = {0};//用来存储被乘数的整型数组
	int cR[MAX] = {0};//用来存储乘数的整型数组
	int cP[MAX] = {0};//用来存储两数之乘积的整型数组
	char tcP[MAX] = "";//用来存储两数之乘积的整型数组
	int lenD = strlen(multiplicand), lenR = strlen(multiplier);//被乘数和乘数字符串的长度
	int i, j, k;

	//逆序复制乘数和被乘数到整型数组（因为乘法运算是从低位开始）
	for (i=0; i<lenD; i++)
	   cD[i] = multiplicand[lenD-1-i] - '0';
	for (i=0; i<lenR; i++)
	   cR[i] = multiplier[lenR-1-i] - '0';

	int carry;//进位
	int mul = 0; //两数之乘积

	strcpy(product, "0"); //先使product的值为0
	for (i=0; i<lenR; i++)//乘法运算过程
	{
	   carry = 0;//进位
	   for (j=0; j<lenD; j++)//乘数的每一位都和被乘数进行乘法运算
	   {
		   mul = cD[j] * cR[i] + carry;//两个乘数之积与进位相加作为当前位乘积
		   cP[j] = mul % 10;//存储当前位
		   carry = mul / 10;//获取进位
	   }
	   if (carry > 0)//获取最后一个进位
		   cP[j++] = carry;
	   
	   while (cP[j-1] == 0)//去掉多余的0
		   --j;
  
	   //逆序复制当前位的乘积tP到字符串tcP
	   for (k=0; k<j; k++)
		   tcP[k] = cP[j-1-k] + '0';
	   for (j=0; j<i; j++)//注意各位数得到的结果应相应左移
		   tcP[k++] = '0';
	   tcP[k] = '\0';
	   IntAddition(product, tcP, product);//对字符串进行加法运算
	}
}

void gcd(char str1[], char str2[], char res[])
{
	char *s1, *s2, *ptemp;
	char temp[205], ttemp[205];
	int a;
	if (compare(str1, str2) > 0)
	{
		s1 = str1;
		s2 = str2;
	}
	else
	{
		s1 = str2;
		s2 = str1;
	}
	while(compare(s2, "0") != 0 && compare(s2, "") != 0)
	{
		division(s1, s2, ttemp, temp);
		if (compare(s2, temp) > 0)
		{
			ptemp = s1;
			s1 = s2;
			s2 = ptemp;
			strcpy(s2, temp);
		}
		else
			strcpy(s1, temp);
	}
	strcpy(res, s1);
}

char time[N][205], dis[N * N][205];
char res[N];
char disR[N];
char yu[N];

int main()
{
	int ncase;
	int i, j, cc;
	int n, cnt;
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	scanf("%d", &ncase);

	for(cc = 0;cc < ncase;cc++)
	{
		scanf("%d", &n);
		for(i = 0;i < n;i++)
			scanf("%s", time[i]);

		cnt = 0;
		for (i = 0;i < n;i++)
			for(j = 0;j < n;j++)
				if (compare(time[i], time[j]) > 0)
					IntSubtration(time[i], time[j], dis[cnt++]);

		strcpy(res, dis[0]);
		for (i = 1;i < cnt;i++)
			gcd(res, dis[i], res);

		IntSubtration(time[0], "1", disR);
		division(disR, res, disR, yu);
		IntAddition(disR, "1", disR);
		IntMultiplication(res, disR, res);
		
		IntSubtration(res, time[0], res);
		printf("Case #%d: %s\n", cc + 1, res);
	}
	return 0;
}
