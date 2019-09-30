package cj2016.r1a;
import java.io.*;
import java.util.*;

public class A {
	Scanner sc;
	PrintWriter pw;
	char[] S;
	
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
		S = sc.next().toCharArray();
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
		String ans = "";
		for(char c : S) {
			String s1 = ans + c;
			String s2 = c + ans;
			ans = s1.compareTo(s2) < 0 ? s2 : s1;
		}
		println(ans);
	}
	
}
