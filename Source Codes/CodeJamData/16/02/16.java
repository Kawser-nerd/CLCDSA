package cj2016.qr;
import java.io.*;
import java.util.*;

public class B {
	Scanner sc;
	PrintWriter pw;
	char[] s;
	
	public static void main(String[] args) throws Exception{
		String filePrefix = args.length>0?args[0]:"B-large";

		try {
			new B().run(filePrefix);
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
		s = sc.next().toCharArray();
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
		int N = s.length;
		char last = s[0];
		int ans = 0;
		for(int i=1; i<N; i++) {
			if(s[i]!=last) {
				ans++;
				last = s[i];
			}
		}
		if(last=='-')
			ans++;
		println(ans);
	}
	
}
