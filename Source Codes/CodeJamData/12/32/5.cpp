#include<stdio.h>
#include<math.h>

//�O�̎Ԃ��~�肫��܂ł̎���
double MaxT(const double x[], const double t[], int N, double D)
{
	if(x[0]>=D)
		return 0;
	for(int i=1; i<N; ++i)
	{
		if(x[i]>=D)
			return t[i-1] + (D-x[i-1])/(x[i]-x[i-1])*(t[i]-t[i-1]);
	}
	return -1e100;
}


//�J�nm�b�܂��āA�˂����߂邩�ǂ���
bool F(const double x[], const double t[], int N, double D,double a,double m,double maxT)
{
	for(int i=0; i<N; ++i)
	{
		if(m<=t[i])
		{
			double d=(t[i]-m)*(t[i]-m)*a/2;
			if(d > x[i])
			{
				//�O�̎Ԃ��A�u���~��؂��Ă�����Z�[�t
				if(x[i]>=D && maxT<=m+sqrt(2*D/a))
					;
				else
					return false;
			}
		}
	}
	return true;
}

double Solve(const double x[], const double t[], int N, double D,double a)
{
	double maxT = MaxT(x,t,N,D);
	//printf("maxT:%f\n",maxT);
	//printf("�K�v�Œ᎞��:%f\n",sqrt(2*D/a));
	double l=0, r=maxT,m;
	for(int i=0; i<40; ++i)
	{
		m=(l+r)/2;
		if(F(x,t,N,D,a,m,maxT))
			r=m;
		else
			l=m;
		//printf("m:%f\n",m);
	}
	return l+sqrt(2*D/a);
}
//v0=0���Ax=/2 * a*t^2�A t= sqrt(2*x/a);

int main()
{
	int T, caseNum;
	scanf("%d",&T);
	for(caseNum = 1; caseNum <= T; ++caseNum)
	{
		double D;
		int N,A;
		double t[2000],x[2000],a[250];
		scanf("%lf%d%d",&D,&N,&A);
		int i,j,k;
		for(i=0; i<N; ++i)
		{
			scanf("%lf%lf",t+i,x+i);
		}
		for(i=0; i<A; ++i)
		{
			scanf("%lf",a+i);
		}

		printf("Case #%d:\n", caseNum);
		for(i=0; i<A; ++i)
			printf("%.10f\n",Solve(x,t,N,D,a[i]));
	}
	return 0;
}
/*

�E�E�E�O�ɎԂ����A�K���ȑ��x�ő����Ă��܂�
�����𔲂����Ȃ��悤�ɂ��Ȃ���A�d�͂ɔC���ċu���~�肽��

�E�E�E�ǂ��l���Ă��A�Ԃ����ɍ~���u�ԂɁA�����ɉ��ɍ~���̂��ő�
�O�̎Ԃ����ɍ~�肫��^�C�~���O�͂킩��A
�ŁA�ő��ňړ�����ɂ́A�r���ň�x���u���[�L���|���Ȃ���΂���

�ŏ��ɑ҂��Ԃœ񕪒T��������
���̂��Ƃ͐����V�~�����[�g���K�v�����肻�������ǁA�����N��ŏ\��

�E�E�E�d�͉����x��A�ʂ�̏ꍇ�ɂ��Ă��ꂼ�������߂�΂����悤������A
���Ȃ���O(N*A)�͂�����
�񕪒T������ɂ́A�ő�l�ƍŏ��l���K�v
�ŏ��l��0�ł�������A���͍ő�l
�E�E�E�ň��A�O�̎Ԃ��u���~�肫�鎞�Ԃ��g���΂�����
t_i<10^5���A��������e�������or���Ό덷�A10^-6�܂ŉ�����΂���
40�񂭂炢�񂹂�12��������炵���A�悵�̗p

*/
