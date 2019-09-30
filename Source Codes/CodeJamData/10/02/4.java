import java.io.*;
import java.math.*;
import java.util.*;

public class b {
	BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
	StringTokenizer st=new StringTokenizer("");
	String LINE() throws Exception { return in.readLine(); }
	String STR() throws Exception {
		while(!st.hasMoreTokens()) st=new StringTokenizer(LINE());
		return st.nextToken();
	}
	int INT() throws Exception { return Integer.parseInt(STR()); }
	long LONG() throws Exception { return Long.parseLong(STR()); }
	double DOUBLE() throws Exception { return Double.parseDouble(STR()); }
	String PD(double d,int n) {
		return String.format("%."+n+"f",d).replace(",",".");
	}

	public static void main(String args[]) throws Exception {
		new b().go();
	}

	BigInteger gcd(BigInteger a,BigInteger b) {
		if(b.equals(BigInteger.ZERO)) return a;
		return gcd(b,a.mod(b));
	}

	public void go() throws Exception {
		int cases=INT();
		int caseno=1;
		while(cases-->0) {
			int N=INT();
			BigInteger a[]=new BigInteger[N];
			for(int i=0;i<N;i++) a[i]=new BigInteger(STR());
			BigInteger g=a[0].subtract(a[1]).abs();
		ferdig:
			for(int i=0;i<N-1;i++) for(int j=i+1;j<N;j++) {
				BigInteger x=a[i].subtract(a[j]).abs();
				g=gcd(g,x);
				if(g.equals(BigInteger.ONE)) break ferdig;
			}
			BigInteger res=a[0].mod(g);
			if(res.compareTo(BigInteger.ZERO)>0) res=g.subtract(res);
			System.out.printf("Case #%d: %s\n",caseno++,res.toString());
		}
	}
}
