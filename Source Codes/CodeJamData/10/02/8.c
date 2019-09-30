#include <stdio.h>
#include <string.h>
#define N 1005
#define MAX 205

void IntSubtration(char *minuend, char *subtrahend, char *difference)
{
	if (strcmp(minuend, subtrahend) == 0)//���������ȣ�����"0"
	{
		strcpy(difference, "0");
		return;
	}

	int cM[MAX] = {0};//�����洢����������������
	int cS[MAX] = {0};//�����洢��������������
	int cD[MAX] = {0};//�����洢����֮�����������
	int lenM = strlen(minuend), lenS = strlen(subtrahend);//�������ͼ����ַ����ĳ���
	int lenMin = lenM < lenS ? lenM : lenS;//���������ĳ����еĽ�Сֵ
	int i;

   for (i=0; i<lenM; i++)
	   cM[i] = minuend[lenM-1-i] - '0';
   for (i=0; i<lenS; i++)
	   cS[i] = subtrahend[lenS-1-i] - '0';

	for (i=0; i<lenMin; i++)//�����������
	{
		if (cM[i] >= cS[i])//���������ڼ�����ֱ�����
			cD[i] = cM[i] - cS[i];
		else //����Ҫ��ǰ��λ
		{
			cD[i] = cM[i] + 10 - cS[i];
			--cM[i+1];
		}
	}

	//��������򱻼�����������lenMin�Ĳ���
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
	for (k=i-1; k>=0; k--,j++)//����洢����֮��ַ���sum
		difference[j] = cD[k] + '0';
	difference[j] = '\0';
}

//�Ƚ��������ַ����洢�ĳ����������Ĵ�С����a>b������1��a==b������0��a<b������-1
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
	if (compare(dividend, divisor) == 0)//���������ڳ���
	{
		strcpy(quotient, "1");
		strcpy(remainder, "0");
		return ;
	}
	if (strcmp(divisor, "0") == 0 || compare(dividend, divisor) < 0)//������С�ڳ���
	{
		strcpy(quotient, "0");
		strcpy(remainder, dividend);
		return ;
	}

	char buf[2] = "0";//��ʱ�������δ洢��������ÿһλ��
	int i, s, k;

	strcpy(remainder, ""); //��ʹproduct��ֵΪ��
	for (i=0,k=0; dividend[i]!='\0'; i++)
	{
		s = 0;
		buf[0] = dividend[i];
		strcat(remainder, buf);//���ϱ�������һλ�����ı䵱ǰ����
		while (compare(remainder, divisor) >= 0)//��������
		{
			s++;
			IntSubtration(remainder, divisor, remainder);
		}
		quotient[k++] = s + '0';//��¼ÿһλ�õ�����ֵ
		if (strcmp(remainder, "0") == 0)
			strcpy(remainder, ""); //ʹproduct��ֵΪ�գ�ȥ�������0
	}
	quotient[k] = '\0';

	//ȥ�������0
	int j;
	for (i=0; quotient[i]=='0'; i++);
	for (j=i; j<=k; j++)
		quotient[j-i] = quotient[j];
}

void IntAddition(char *augend, char *addend, char *sum)
{
	int cAug[MAX] = {0};//�����洢����������������
	int cAdd[MAX] = {0};//�����洢��������������
	int cSum[MAX] = {0};//�����洢����֮�͵���������
	int lenAug = strlen(augend), lenAdd = strlen(addend);//�������ͼ����ַ����ĳ���
	int lenMin = lenAug < lenAdd ? lenAug : lenAdd;//���������ĳ����еĽ�Сֵ
	int i;

	//�����Ƽ����ͱ��������������飨��Ϊ�ӷ������Ǵӵ�λ��ʼ��
	for (i=0; i<lenAug; i++)
		cAug[i] = augend[lenAug-1-i] - '0';
	for (i=0; i<lenAdd; i++)
		cAdd[i] = addend[lenAdd-1-i] - '0';

	int carry = 0;//��λ
	int s = 0; //����֮��

	for (i=0; i<lenMin; i++)//�ӷ��������
	{
		s = cAug[i] + cAdd[i] + carry;//���������ͽ�λ֮����Ϊ��ǰλ�ĺ�
		cSum[i] = s % 10;//�洢��ǰλ
		carry = s / 10;//��ȡ��λ
	}

	//��������򱻼�����������lenMin�Ĳ���
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

	if (carry > 0)//�������һ����λ
		cSum[i++] = carry;

	int j;
	for (j=0; j<i; j++)//����洢����֮�͵��ַ���sum
		sum[j] = cSum[i-1-j] + '0';
	sum[i] = '\0';
}

void IntMultiplication(char *multiplicand, char *multiplier, char *product)
{
	int cD[MAX] = {0};//�����洢����������������
	int cR[MAX] = {0};//�����洢��������������
	int cP[MAX] = {0};//�����洢����֮�˻�����������
	char tcP[MAX] = "";//�����洢����֮�˻�����������
	int lenD = strlen(multiplicand), lenR = strlen(multiplier);//�������ͳ����ַ����ĳ���
	int i, j, k;

	//�����Ƴ����ͱ��������������飨��Ϊ�˷������Ǵӵ�λ��ʼ��
	for (i=0; i<lenD; i++)
	   cD[i] = multiplicand[lenD-1-i] - '0';
	for (i=0; i<lenR; i++)
	   cR[i] = multiplier[lenR-1-i] - '0';

	int carry;//��λ
	int mul = 0; //����֮�˻�

	strcpy(product, "0"); //��ʹproduct��ֵΪ0
	for (i=0; i<lenR; i++)//�˷��������
	{
	   carry = 0;//��λ
	   for (j=0; j<lenD; j++)//������ÿһλ���ͱ��������г˷�����
	   {
		   mul = cD[j] * cR[i] + carry;//��������֮�����λ�����Ϊ��ǰλ�˻�
		   cP[j] = mul % 10;//�洢��ǰλ
		   carry = mul / 10;//��ȡ��λ
	   }
	   if (carry > 0)//��ȡ���һ����λ
		   cP[j++] = carry;
	   
	   while (cP[j-1] == 0)//ȥ�������0
		   --j;
  
	   //�����Ƶ�ǰλ�ĳ˻�tP���ַ���tcP
	   for (k=0; k<j; k++)
		   tcP[k] = cP[j-1-k] + '0';
	   for (j=0; j<i; j++)//ע���λ���õ��Ľ��Ӧ��Ӧ����
		   tcP[k++] = '0';
	   tcP[k] = '\0';
	   IntAddition(product, tcP, product);//���ַ������мӷ�����
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
