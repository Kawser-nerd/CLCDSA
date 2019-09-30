#include<stdio.h>
#include<math.h>

//前の車が降りきるまでの時間
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


//開始m秒まって、突っ込めるかどうか
bool F(const double x[], const double t[], int N, double D,double a,double m,double maxT)
{
	for(int i=0; i<N; ++i)
	{
		if(m<=t[i])
		{
			double d=(t[i]-m)*(t[i]-m)*a/2;
			if(d > x[i])
			{
				//前の車が、丘を降り切っていたらセーフ
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
	//printf("必要最低時間:%f\n",sqrt(2*D/a));
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
//v0=0より、x=/2 * a*t^2、 t= sqrt(2*x/a);

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

・・・前に車が一台、適当な速度で走っています
そいつを抜かさないようにしながら、重力に任せて丘を降りたい

・・・どう考えても、車が下に降りる瞬間に、同時に下に降りるのが最速
前の車が下に降りきるタイミングはわかる、
で、最速で移動するには、途中で一度もブレーキを掛けなければいい

最初に待つ時間で二分探索かしら
そのあとは随時シミュレート剃る必要がありそうだけど、それはN回で十分

・・・重力加速度がA通りの場合についてそれぞれ回を求めればいいようだから、
少なくとO(N*A)はかかる
二分探索するには、最大値と最小値が必要
最小値は0でいいから、問題は最大値
・・・最悪、前の車が丘を降りきる時間を使えばいいか
t_i<10^5より、それを許容される絶対or相対誤差、10^-6まで下げればいい
40回くらい回せば12桁下がるらしい、よし採用

*/
