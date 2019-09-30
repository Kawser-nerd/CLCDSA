package cj2016.r3;
import java.io.*;
import java.util.*;

public class D {
	Scanner sc;
	PrintWriter pw;
	int N, L;
	String[] G;
	String B;

	public static void main(String[] args) throws Exception{
		String filePrefix = args.length>0?args[0]:"D-small-attempt0";

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
		N = sc.nextInt();
		L = sc.nextInt();
		G = new String[N];
		for(int i=0; i<N; i++)
			G[i] = sc.next();
		B = sc.next();
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
		for(int i=0; i<N; i++) {
			if(G[i].equals(B)) {
				println("IMPOSSIBLE");
				return;
			}
		}
		
		String p1 = "0";
		for(int i=0; i<L-1; i++)
			p1 += "?";
		String p2 = "";
		for(int i=0; i<L; i++)
			p2 += (i%2)^1;
		p2 += "0?";
		for(int i=0; i<L; i++)
			p2 += (i%2)^1;
		
		println(p1 + " " + p2);
	}
}
