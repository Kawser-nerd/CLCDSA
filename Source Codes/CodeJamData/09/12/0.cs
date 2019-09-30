using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class B {
	int n, m, N, M;
	int[,] s, w, t, c;
	int[,] best;
	public B() {
		string[] ss=Console.ReadLine().Split();
		n=int.Parse(ss[0]); m=int.Parse(ss[1]);
		N=n*2; M=m*2;
		s=new int[n,m]; w=new int[n,m]; t=new int[n,m]; c=new int[n,m];
		for (int i=n-1; i>=0; --i) {
			ss=Console.ReadLine().Split();
			for (int j=0; j<m; ++j) {
				s[i,j]=int.Parse(ss[j*3]);
				w[i,j]=int.Parse(ss[j*3+1]);
				t[i,j]=int.Parse(ss[j*3+2]);
				c[i,j]=s[i,j]+w[i,j];
				t[i,j]=t[i,j]%c[i,j]-c[i,j];
			}
		}
		best=new int[N,M];
		for (int i=0; i<N; ++i)
			for (int j=0; j<M; ++j)
				best[i,j]=1000000000;
	}
	public string main() {
		Queue<int> qx=new Queue<int>(), qy=new Queue<int>();
		qx.Enqueue(0); qy.Enqueue(0); best[0,0]=0;
		while (qx.Count>0) {
			int x=qx.Dequeue(), y=qy.Dequeue(), st=best[x,y];
			int x2=x/2, y2=y/2, nx=x^1, ny=y^1;
			if (x%2==0) {
				if (x>0&&best[x-1,y]>best[x,y]+2) {
					best[x-1,y]=best[x,y]+2;
					qx.Enqueue(x-1); qy.Enqueue(y);
				}
			} else {
				if (x!=N-1&&best[x+1,y]>best[x,y]+2) {
					best[x+1,y]=best[x,y]+2;
					qx.Enqueue(x+1); qy.Enqueue(y);
				}
			}
			int t0=st-t[x2,y2];
			if (t0%c[x2,y2]>=s[x2,y2]) {
				t0=t0+c[x2,y2]-t0%c[x2,y2];
			}
			if (best[nx,y]>t0+t[x2,y2]+1) {
				best[nx,y]=t0+t[x2,y2]+1;
				qx.Enqueue(nx); qy.Enqueue(y);
			}
			if (y%2==0) {
				if (y>0&&best[x,y-1]>best[x,y]+2) {
					best[x,y-1]=best[x,y]+2;
					qx.Enqueue(x); qy.Enqueue(y-1);
				}
			} else {
				if (y!=M-1&&best[x,y+1]>best[x,y]+2) {
					best[x,y+1]=best[x,y]+2;
					qx.Enqueue(x); qy.Enqueue(y+1);
				}
			}
			t0=st-t[x2,y2];
			if (t0%c[x2,y2]<s[x2,y2]) {
				t0=t0+s[x2,y2]-t0%c[x2,y2];
			}
			if (best[x,ny]>t0+t[x2,y2]+1) {
				best[x,ny]=t0+t[x2,y2]+1;
				qx.Enqueue(x); qy.Enqueue(ny);
			}
		}
		return best[N-1,M-1].ToString();
	}
}