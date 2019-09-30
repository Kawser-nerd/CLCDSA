using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class C {
	int c, n;
	double[,] f;
	public C() {
		string[] s=Console.ReadLine().Split();
		c=int.Parse(s[0]); n=int.Parse(s[1]);
		f=new double[c+1,c+1];
		for (int i=0; i<=c; ++i) {
			f[i,0]=1; f[i,i]=1;
			for (int j=1; j<i; ++j) f[i,j]=f[i-1,j]+f[i-1,j-1];
		}
	}
	public string main() {
		double[] ans=new double[c+1];
		ans[c]=0;
		for (int k=c-1; k>=0; --k) {
			for (int i=0; i<=k&&i<n; ++i) {
				if (n-i>c-k) continue;
				ans[k]+=f[k,i]*f[c-k,n-i]/f[c,n]*ans[k+n-i];
			}
			if (k>=n) {
				double p0=f[k,n]/f[c,n];
				ans[k]=(ans[k]+p0)/(1-p0);
			}
			ans[k]+=1;
		}
		return string.Format("{0:F7}", ans[0]);
	}
}