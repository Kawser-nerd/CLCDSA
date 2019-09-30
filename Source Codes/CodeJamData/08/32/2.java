import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.InputStream;
import java.util.*;

import static java.lang.Math.*; 
import static java.util.Arrays.*;
import static java.lang.Integer.*;
import static java.lang.Character.*;  



public class B {

	Scanner scan;
	InputStream in;
	
	int intLine(){
		return parseInt(scan.nextLine());
	}
	
	boolean ugly(long x){
		if(x%2==0)return true;
		if(x%2==2)return true;
		if(x%3==0)return true;
		if(x%5==0)return true;
		if(x%7==0)return true;
		return false;
	}
	int n;
	
	long getVal(int a, int b){
		long r =0;
		for(int i = a;i<=b;i++){
			r*=10;
			r+= D[i]-'0';
			r%=mod;
		}
		return r;
	}
	
	long[][][] M;
	
	long val[][];
	
	char[] D;
	
	int mod = 2*3*5*7;
	
	long[] count(int a, int b){
		if(M[a][b]!=null)return M[a][b];
		long[]r = new long[mod];
		r[(int)(val[a][b]%mod)]=1;
		for(int i =a+1;i<=b;i++){
			long x = val[a][i-1];
			long[]vals = count(i,b);
			for(int j=0;j<mod;j++){
				r[(int)((x+j)%mod)] += vals[j];
				r[(int)((mod+x-j)%mod)] += vals[j];
			}
		}
		return M[a][b]=r;
	}
	
	long solve(){
		long res=0;
		String s = scan.next();
		D = s.toCharArray();
		n = D.length;
		M = new long[n+1][n+1][];
		val = new long[n][n];
		for(int i=0;i<n;i++)for(int j=i;j<n;j++)val[i][j]=getVal(i,j);
		long[]x=count(0,n-1);
		for(int i=0;i<mod;i++)if(ugly(i))res+=x[i];
	    return res;
	}
	
	void solveAll(){
		int N = parseInt(scan.nextLine());
		for(int i=0;i<N;i++){
			long r =solve();
			System.out.format("Case #%d: %d\n",i+1,r);
		}
	}
	
	B() throws Exception{
		in = new BufferedInputStream(new FileInputStream("B-large.in"));
		//in = new BufferedInputStream(new FileInputStream("B.in"));
		scan = new Scanner(in);
	}
	
	public static void main(String[] args) throws Exception{
	    Locale.setDefault(Locale.US); 
	    new B().solveAll();
	}

}
