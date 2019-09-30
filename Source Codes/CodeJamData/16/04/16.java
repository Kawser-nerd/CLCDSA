package cj2016.qr;
import java.io.*;
import java.util.*;

public class D {
	Scanner sc;
	PrintWriter pw;
	int K,C,S;

	public static void main(String[] args) throws Exception{
		String filePrefix = args.length>0?args[0]:"D-large";

		try {
			new D().run(filePrefix);
		} catch(Exception e) {
			System.err.println(e);
		}
	}
	
	public void run(String filePrefix) throws Exception {
		sc = new Scanner(new FileReader(filePrefix + ".in"));
		pw = new PrintWriter(new FileWriter(filePrefix + ".out"));
		int ntest = sc.nextInt();
		for(int test=1; test<=ntest; test++) {
			read(sc);
			pw.print("Case #" + test + ": ");
			System.out.print("Case #" + test + ": ");
			solve();
		}
		System.out.println("Finished.");
		sc.close();
		pw.close();
		
	}
	
	void read(Scanner sc) {
		K = sc.nextInt();
		C = sc.nextInt();
		S = sc.nextInt();
	}
	
	void print(Object s) {
		pw.print(s);
		System.out.print(s);
	}
	
	void println(Object s) {
		pw.println(s);
		System.out.println(s);
	}	
	
	public void solve() {
		if(C*S<K) {
			println("IMPOSSIBLE");
			return;
		}
		int M = (K+C-1)/C;
		long[] pos = new long[M];
		for(int i=0; i<K; i++) {
			pos[i/C] += pow(K, i%C)*i;
		}
		
		for(int i=0; i<M; i++)
			print((pos[i]+1) + (i==M-1 ? "\n" : " "));
	}
	
	long pow(long a, int b) {
		long ans = 1;
		for(int i=0; i<b; i++)
			ans *= a;
		return ans;
	}
}
