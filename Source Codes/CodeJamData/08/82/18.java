import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.InputStream;
import java.util.*;

import static java.lang.Math.*; 
import static java.util.Arrays.*;
import static java.lang.Integer.*;
import static java.lang.Character.*;  




public class B {

	Scanner  scan;
	InputStream in;
	
	int intLine(){
		return parseInt(scan.nextLine());
	}
	
	class e{
		int c;
		int a;
		int b;
	}
	
	e[]E;
	
	
	
	
	long solve(){
		HashMap<String,Integer>C = new HashMap<String, Integer>();
		long res=0;
		int n = intLine();
		int cc=0;
		E = new e[n];
		for(int i=0;i<n;i++){
			String s = scan.nextLine();
			String[]ss = s.split(" ");
			int c=0;
			if(C.containsKey(ss[0])){
				c = C.get(ss[0]);
			}else{
				c = cc;
				C.put(ss[0], c);
				cc++;
			}
			E[i]=new e();
			E[i].c=c;
			E[i].a = parseInt(ss[1]);
			E[i].b = parseInt(ss[2]);
		}
		res = 1000;
		for(int c1=0;c1<cc;c1++)for(int c2=c1;c2<cc;c2++)for(int c3=c2;c3<cc;c3++){
			int[]A = new int[10001];
			A[0]=0;
			for(int i=1;i<A.length;i++){
				A[i]=1000;
				for(int j=0;j<E.length;j++){
					if(E[j].c!=c1 &&E[j].c!=c2&&E[j].c!=c3)continue;
					if(i<E[j].a || i>E[j].b)continue;
					int beg = E[j].a-1;
					A[i]=min(A[i], 1+A[beg]);
				}
			}
			res = min(res, A[10000]);
		}
	    return res;
	}
	
	void solveAll(){
		int N = parseInt(scan.nextLine());
		for(int i=0;i<N;i++){
			long r =solve();
			if(r==1000)System.out.format("Case #%d: IMPOSSIBLE\n",i+1);
			else System.out.format("Case #%d: %d\n",i+1,r);
		}
	}
	
	B() throws Exception{
		in = new BufferedInputStream(new FileInputStream("B-small-attempt0.in"));
		//in = new BufferedInputStream(new FileInputStream("B.in"));
		scan = new Scanner(in);
	}
	
	public static void main(String[] args) throws Exception{
	    Locale.setDefault(Locale.US); 
	    new B().solveAll();
	}

}
