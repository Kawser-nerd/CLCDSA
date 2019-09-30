package cj2015.qr;
import java.io.*;
import java.util.*;

public class A {
	Scanner sc;
	PrintWriter pw;
	int smax;
	String s;
	
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
		smax = sc.nextInt();
		s = sc.next();
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
		int ans = 0;
		int sum = 0;
		for(int i=0; i<smax+1; i++) {
			 int num = s.charAt(i)-'0';
			 if(sum < i) {
				 ans += i-sum;
				 sum += i-sum;
			 }
			 sum += num;
		}
		println(ans);
	}
	
}
