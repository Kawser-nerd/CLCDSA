import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class B {

	void solve() throws IOException {
		int t=nextInt();
		for(int testCase=0;testCase<t;testCase++){
			long n=nextInt();
			long p=nextLong();
			long max=1l<<n;
			long a1=0,a2=max-2;
			if(p==1){
				a1=a2=0;
			}
			else
				if(p==max){
					a1=a2=max-1;
				}
				else{
					long x=max>>1l;
					long y=x>>1l;
					long z=2;
					while(p>x){
						a1+=z;
						z<<=1l;
						x|=y;
						y>>=1l;
					}
					x=max>>1l;
					z=2;
					while(p<x){
						a2-=z;
						z<<=1l;
						x>>=1l;
					}
				}
			out.printf("Case #%d: %d %d\n",testCase+1,a1,a2);
		}
	}

	public static void main(String[] args) throws IOException {
		new B().run();
	}

	void run() throws IOException {
//		reader = new BufferedReader(new InputStreamReader(System.in));
//
//		out = new PrintWriter(new OutputStreamWriter(System.out));
		reader = new BufferedReader(new FileReader("input.txt"));

		out = new PrintWriter(new FileWriter("output.txt"));
		tokenizer = null;
		solve();
		reader.close();
		out.flush();

	}

	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter out;

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}
}
