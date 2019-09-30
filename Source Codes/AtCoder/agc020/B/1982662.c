long long n,a[100005];
long long mx[100005],mn[100005];
signed main()
{
	__builtin_scanf("%lld",&n);
	for (int i=0;i<n;++i) __builtin_scanf("%lld",&a[i]);
	mx[n]=2;mn[n]=2;
	for (long long i=n-1;i>=0;i--)
	{
		mx[i]=(mx[i+1]/a[i]+1)*a[i]-1;
		mn[i]=((mn[i+1]-1)/a[i]+1)*a[i];
		if (mx[i]<mn[i])
		{
			__builtin_printf("-1");
			return 0;
		}
	}
	__builtin_printf("%lld %lld",mn[0],mx[0]);
	return 0;
}