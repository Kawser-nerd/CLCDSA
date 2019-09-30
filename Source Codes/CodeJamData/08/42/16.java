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
	
	
	String find(long A, long B, long area){
		for(long a =1;a<=A;a++)for(long b=1;b<=B;b++){
			for(long x =0;x<=b;x++)for(long y = 0;y<=a;y++){
				long r = x*a+y*b -x*y;
				if(r==area){
					return
					String.format("%d %d %d %d %d %d", 0,x,y,0,a,b);
				}
			}
		}
		return null;
	}
	
	String solve(){
		long res=0;
		int A = scan.nextInt();
		int B = scan.nextInt();
		long area = scan.nextLong();
		if(find(A,B,area)!=null)return find(A,B,area);
	    return "IMPOSSIBLE";
	}
	
	void solveAll(){
		int N = parseInt(scan.nextLine());
		for(int i=0;i<N;i++){
			String r =solve();
			System.out.format("Case #%d: %s\n",i+1,r);
		}
	}
	
	B() throws Exception{
		in = new BufferedInputStream(new FileInputStream("B-small-attempt0.in"));
	//	in = new BufferedInputStream(new FileInputStream("B.in"));
		scan = new Scanner(in);
	}
	
	public static void main(String[] args) throws Exception{
	    Locale.setDefault(Locale.US); 
	    new B().solveAll();
	}

}
