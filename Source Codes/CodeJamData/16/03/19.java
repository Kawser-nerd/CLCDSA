package cj2016.qr;
import java.io.*;
import java.util.*;

public class C {
	Scanner sc;
	PrintWriter pw;
	int N;
	int J;

	public static void main(String[] args) throws Exception{
		String filePrefix = args.length>0?args[0]:"C-large";

		try {
			new C().run(filePrefix);
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
		J = sc.nextInt();
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
		int M = N/2;
		
		//base : 1000...01 (M digits)
		int base = (1<<(M-1))+1;
		
		//divisor is always 10...01 (N-M+1 digits)
		long[] div = new long[9];
		Arrays.fill(div, 1);
		for(int i=0; i<N-M; i++)
			for(int j=0; j<9; j++)
				div[j] *= j+2;
		for(int i=0; i<9; i++)
			div[i]++;
		
		println("");
		for(int i=0; i<J; i++) {
			String x = Integer.toBinaryString(base+i*2);
			print(x + (N%2==0 ? "" : "0") + x);
			for(int j=0; j<9; j++)
				print(" " + div[j]);
			println("");
		}
	}
}
