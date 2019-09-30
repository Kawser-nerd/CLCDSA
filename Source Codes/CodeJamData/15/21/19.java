package cj2015.r1b;
import java.io.*;
import java.util.*;

public class A {
	Scanner sc;
	PrintWriter pw;
	long N;
	
	public static void main(String[] args) throws Exception{
		String filePrefix = args.length>0?args[0]:"A-large";

		try {
			new A().run(filePrefix);
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
		N = sc.nextLong();
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
		long[] m = new long[18];
		m[0] = 1;
		for(int i=1; i<18; i++)
			m[i] = m[i-1]*10;
		
		if(N==1) {
			println(1);
			return;
		}
		long ans = 0;
		
		while(N>1) {
			int L = String.valueOf(N).length();
						
			long dif = N%m[L/2]==0 ? m[L/2]-1 : N%m[L/2]-1;
			ans += dif;
			N -= dif;
			if(N-reverse(N)>1) {
				N = reverse(N);
				ans++;
			}
			
			L = String.valueOf(N).length();
			dif = N-(m[L-1]-1);
			ans += dif;
			N -= dif;
		}
		
		println(ans);
	}
	
	public long reverse(long x) {
		long ans = 0;
		do {
			ans *= 10;
			ans += x%10;
			x /= 10;
		} while(x>0);
		return ans;
	}
}
