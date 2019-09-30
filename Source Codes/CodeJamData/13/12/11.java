import java.util.*;
import java.lang.*;
import java.math.*;
import java.io.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;

public class B{
	Scanner sc=new Scanner(System.in);

	int INF=1<<28;
	double EPS=1e-9;

	int caze, T;
	long E, R;
	int n;
	int[] vs;

	void run(){
		T=sc.nextInt();
		sc.nextLine();
		for(caze=1; caze<=T; caze++){
			E=sc.nextInt();
			R=sc.nextInt();
			n=sc.nextInt();
			vs=new int[n];
			for(int i=0; i<n; i++){
				vs[i]=sc.nextInt();
			}
			solveLarge();
		}
	}

	void solveSmall(){
		int E=(int)this.E;
		int R=(int)this.R;
		int[][] dp=new int[n+1][E+1];
		for(int j=0; j<n; j++){
			for(int i=0; i<=E; i++){
				// dp[j][i]‚©‚ç
				for(int d=0; d<=i; d++){
					int next=min(i-d+R, E);
					dp[j+1][next]=max(dp[j+1][next], dp[j][i]+vs[j]*d);
				}
			}
			// debug(j, dp[j+1]);
		}
		int max=0;
		for(int i=0; i<=E; i++){
			max=max(max, dp[n][i]);
		}
		answer(""+max);
	}

	RMQ rmq;
	long[] use;

	void solveLarge(){
		rmq=new RMQ(vs);
		use=new long[n];
		rec(0, n, E, 0);
		long res=0;
		for(int i=0; i<n; i++){
			res+=use[i]*vs[i];
		}
		answer(""+res);
	}

	void rec(int s, int t, long e, long f){
		if(s==t){
			return;
		}
		int i=rmq.query(s, t);
		long nextLB=max(f-R*(t-i), 0);
		long nowUB=min(e+R*(i-s), E);
		use[i]=nowUB-nextLB;
		rec(s, i, e, nowUB);
		rec(i+1, t, min(nextLB+R, E), f);
	}

	class RMQ{
		int[][] max;
		int[] a;

		RMQ(int[] a){
			this.a=a;
			int n=a.length, m=log2(n)+1;
			max=new int[m][n];
			for(int i=0; i<n; i++)
				max[0][i]=i;
			for(int j=1, k=1; j<m; j++, k<<=1)
				for(int i=0; i+k<n; i++)
					max[j][i]=a[max[j-1][i]]>=a[max[j-1][i+k]]?max[j-1][i]
							:max[j-1][i+k];
		}

		int query(int from, int to){
			int k=log2(to-from);
			return a[max[k][from]]>=a[max[k][to-(1<<k)]]?max[k][from]:max[k][to
					-(1<<k)];
		}

		int log2(int b){
			return 31-Integer.numberOfLeadingZeros(b);
		}
	}

	void answer(String s){
		println("Case #"+caze+": "+s);
	}

	void println(String s){
		System.out.println(s);
	}

	void print(String s){
		System.out.print(s);
	}

	void debug(Object... os){
		System.err.println(deepToString(os));
	}

	public static void main(String[] args){
		new B().run();
	}
}
