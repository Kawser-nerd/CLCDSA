import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.InputStream;
import java.util.*;

import static java.lang.Math.*; 
import static java.util.Arrays.*;
import static java.lang.Integer.*;
import static java.lang.Character.*;  




public class C {

	Scanner  scan;
	InputStream in;
	
	int intLine(){
		return parseInt(scan.nextLine());
	}
	
	static long mod =1000000009;
					 
	
	static final int nwd( int a, int b ){
		return b==0?a:nwd( b, a % b);
	}
	
	static HashMap<Long,Long> H = new HashMap<Long,Long>();
	
	static long npok(int n, int k){
		long key = n | ((long)k)<<32;
		//if(H.containsKey(key))return H.get(key);
		if(n==k)return 1;
		if(k==0)return 1;
		long res =1;
		for(int i=0;i<k;i++)res = (res *(n-i))%mod;
//		int[]A = new int[k];
//		for(int i=0;i<A.length;i++)A[i]=n-i;
//		for(int j=2;j<=k;j++){
//			int jj=j;
//			for(int i=0;i<A.length;i++){
//				
//				int x =nwd(A[i],jj); 
//				if(x>1){
//					A[i]/=x;
//					jj/=x;
//					if(jj==1)
//						break;
//				}
//			}
//		}
//		
//		for(long x:A)res = (res*x)%mod;
		//H.put(key,res);
		return res;
	}
	int[]C;
	int k;
	int n;
	boolean[][]M;
	long count(int x, int p){
		int aval = k-C[p];
		int chl = C[x];
		if(p!=n)chl--;
		if(aval<chl)return 0;
		long res = 1;//npok(aval,chl);
		for(int i=0;i<n;i++)if(M[x][i] &&i!=p){
			res = (res*count(i,x))%mod;
			res = (res *aval)%mod;
			aval--;
		}
		return res;
	}
	
	long solve(){
		long res=0;
		n = scan.nextInt();
		k = scan.nextInt();
		M = new boolean[n][n];
		C = new int[n+1];
		for(int i=0;i<n-1;i++){
			int a = scan.nextInt()-1;
			int b = scan.nextInt()-1;
			M[a][b]=M[b][a]=true;
			C[a]++;C[b]++;
		}
		res = count(0,n);
	    return res;
	}
	
	void solveAll(){
		int N = parseInt(scan.nextLine());
		for(int i=0;i<N;i++){
			long r =solve();
			System.out.format("Case #%d: %d\n",i+1,r);
		}
	}
	
	C() throws Exception{
		in = new BufferedInputStream(new FileInputStream("C-large.in"));
		//in = new BufferedInputStream(new FileInputStream("C.in"));
		scan = new Scanner(in);
	}
	
	public static void main(String[] args) throws Exception{
	    Locale.setDefault(Locale.US); 
	    new C().solveAll();
//	    for(int n=0;n<10;n++){
//	    	for(int k=0;k<=n;k++)System.out.print(npok(n,k)+" ");
//	    	System.out.println();
//	    }
//	    System.out.println(npok(4,2));
	}

}
