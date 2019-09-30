import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.ArrayList;
 
public class Main {
	public static void main(String args[])throws IOException  {
 
	
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		long ans = -1;
		long n=in.nextInt();
		long p=in.nextInt();
		String s = in.nextString();
		String t = in.nextString();

		
		ans = findAns(n,p,s,t);
		
		//ans = findAns(n,p,out);

		out.print(ans);
		out.close();
	}

	static long findAns(long n,long p, String s, String t){
		long ans = -1;
		boolean findSame = true;		
		long gcd = gcd(n,p);
		long lcm = n*p/gcd;
		
		n=n/gcd;
		p=p/gcd;
		for(int i=0; i<gcd;i++){
			if(s.charAt((int)n*i) != t.charAt((int)p*i)){
				findSame = false;
				break;
			}
		}
		if(findSame)
			ans = lcm;
		else
			ans = -1;		
		
		return ans;
	}
	
    static long gcd(long a, long b) 
    { 
        return b>0?gcd(b, a%b):a; 
    } 

    static long lcm(long a, long b) 
    { 
        return (a*b)/gcd(a, b); 
    } 

	
	
	static class InputReader {
		BufferedReader in;
		StringTokenizer tok;
 
		public String nextString() {
			while (!tok.hasMoreTokens()) {
				try {
					tok = new StringTokenizer(in.readLine(), " ");
				} catch (IOException e) {
					throw new InputMismatchException();
				}
			}
			return tok.nextToken();
		}
 
		public int nextInt() {
			return Integer.parseInt(nextString());
		}
 
		public long nextLong() {
			return Long.parseLong(nextString());
		}
 
		public double nextDouble() {
			return Double.parseDouble(nextString());
		}
 
		public int[] nextIntArray(int n) {
			int[] res = new int[n];
			for (int i = 0; i < n; i++) {
				res[i] = nextInt();
			}
			return res;
		}
 
		public int[] nextIntArrayDec(int n) {
			int[] res = new int[n];
			for (int i = 0; i < n; i++) {
				res[i] = nextInt() - 1;
			}
			return res;
		}
 
		public int[] nextIntArray1Index(int n) {
			int[] res = new int[n + 1];
			for (int i = 0; i < n; i++) {
				res[i + 1] = nextInt();
			}
			return res;
		}
 
		public long[] nextLongArray(int n) {
			long[] res = new long[n];
			for (int i = 0; i < n; i++) {
				res[i] = nextLong();
			}
			return res;
		}
 
		public long[] nextLongArrayDec(int n) {
			long[] res = new long[n];
			for (int i = 0; i < n; i++) {
				res[i] = nextLong() - 1;
			}
			return res;
		}
 
		public long[] nextLongArray1Index(int n) {
			long[] res = new long[n + 1];
			for (int i = 0; i < n; i++) {
				res[i + 1] = nextLong();
			}
			return res;
		}
 
		public double[] nextDoubleArray(int n) {
			double[] res = new double[n];
			for (int i = 0; i < n; i++) {
				res[i] = nextDouble();
			}
			return res;
		}
 
		public InputReader(InputStream inputStream) {
			in = new BufferedReader(new InputStreamReader(inputStream));
			tok = new StringTokenizer("");
		}
	}
 
	
}