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
	
	long solve(){
		long res=0;
		int onkey = scan.nextInt();
		int k = scan.nextInt();
		int n = scan.nextInt();
		int[]A = new int[n];
		for(int i=0;i<n;i++){
			A[i]=scan.nextInt();
		}
		sort(A);
		if(n>onkey*k)return -1;
		int j = n-1;
		for(int i=0;i<n;i++){
			res += A[j]*(i/k+1);
			j--;
		}
	    return res;
	}
	
	void solveAll(){
		int N = parseInt(scan.nextLine());
		for(int i=0;i<N;i++){
			long r =solve();
			if(r==-1)System.out.format("Case #%d: Impossible\n",i+1);
			System.out.format("Case #%d: %d\n",i+1,r);
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
