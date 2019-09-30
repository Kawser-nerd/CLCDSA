package cj2016.r1a;
import java.io.*;
import java.util.*;

public class B {
	Scanner sc;
	PrintWriter pw;
	int N;
	int[][] h;
	
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
		N = sc.nextInt();
		h = new int[2*N-1][N];
		for(int i=0; i<2*N-1; i++)
			for(int j=0; j<N; j++)
				h[i][j] = sc.nextInt();
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
		int[] count = new int[2500];
		for(int i=0; i<2*N-1; i++)
			for(int j=0; j<N; j++)
				count[h[i][j]-1]++;
		
		int[] ans = new int[N];
		int idx=0;
		for(int i=0; i<2500; i++)
			if(count[i]%2!=0)
				ans[idx++] = i+1;
		
		for(int i=0; i<N; i++)
			print(ans[i] + (i==N-1 ? "\n" : " "));
	}
	
}
