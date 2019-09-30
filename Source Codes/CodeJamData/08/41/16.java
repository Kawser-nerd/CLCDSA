import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.InputStream;
import java.util.*;

import static java.lang.Math.*; 
import static java.util.Arrays.*;
import static java.lang.Integer.*;
import static java.lang.Character.*;  



public class A {

	Scanner scan;
	InputStream in;
	
	int intLine(){
		return parseInt(scan.nextLine());
	}
	int[]T;int[]op;boolean[]ch;
	int inf = 100000000;
	int n;
	int[][]M;
	int doit(int p, int v){
		if(M[p][v]!=-1)return M[p][v];
		int res =inf;
		if(p*2 >n){
			if(T[p]==v)return 0;
			else return inf;
		}else{
			if(op[p] == 0 || ch[p]){
				for(int a =0;a<2;a++)for(int b =0;b<2;b++){
					if((a|b)!=v)continue;
					int r =doit(p*2,a)+doit(p*2+1,b);
					if(op[p]==1)r++;
					res = min(res,r);
				}
			}
			if(op[p]==1 || ch[p]){
				for(int a =0;a<2;a++)for(int b =0;b<2;b++){
					if((a&b)!=v)continue;
					int r =doit(p*2,a)+doit(p*2+1,b);
					if(op[p]==0)r++;
					res = min(res,r);
				}
			}
		}
		return M[p][v]=res;
	}
	
	long solve(){
		 n = scan.nextInt();
		int v = scan.nextInt();
		T = new int[n+1];
		long res=0;
		op = new int[n+1];
		ch = new boolean[n+1];
		M = new int[n+1][2];
		for(int[]a:M)fill(a,-1);
		for(int i=1;i<=n;i++){
			if(i<=(n-1)/2){
				op[i]=scan.nextInt();
				ch[i]= scan.nextInt()==1;
			}else{
				T[i]= scan.nextInt();
			}
		}
	    return doit(1,v);
	}
	
	void solveAll(){
		int N = parseInt(scan.nextLine());
		for(int i=0;i<N;i++){
			long r =solve();
			if(r>=inf)System.out.format("Case #%d: IMPOSSIBLE\n",i+1);
			else System.out.format("Case #%d: %d\n",i+1,r);
		}
	}
	
	A() throws Exception{
		in = new BufferedInputStream(new FileInputStream("A-large.in"));
		//in = new BufferedInputStream(new FileInputStream("A.in"));
		scan = new Scanner(in);
	}
	
	public static void main(String[] args) throws Exception{
	    Locale.setDefault(Locale.US); 
	    new A().solveAll();
	}

}
