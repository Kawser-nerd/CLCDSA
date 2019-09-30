package cj2015.qr;
import java.io.*;
import java.util.*;

public class B {
	Scanner sc;
	PrintWriter pw;
	int D;
	int[] P;
	
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
		D = sc.nextInt();
		P = new int[D];
		for(int i=0; i<D; i++)
			P[i] = sc.nextInt();
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
		final int INF = 1000000;
		int min = INF;
		
		for(int x=1; x<=1000; x++) {
			int time=0;
			for(int i=0; i<D; i++)
				time += (P[i]+x-1)/x - 1;
			min = Math.min(min, time+x);
		}
		
		println(min);
	}
	
}
