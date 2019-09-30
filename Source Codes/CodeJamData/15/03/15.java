package cj2015.qr;
import java.io.*;
import java.util.*;

public class C {
	Scanner sc;
	PrintWriter pw;
	int L;
	long X;
	String s;
	static final int[][] matrix = 
		{{1,  2,  3,  4},
		 {2, -1,  4, -3},
		 {3, -4, -1,  2},
		 {4,  3, -2, -1}};

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
		L = sc.nextInt();
		X = sc.nextLong();
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
		int R = (int)Math.min(X, 12+X%4);
		
		int cur = 1;
		int state = 0;
		for(int i=0; i<R; i++) {
			for(int j=0; j<L; j++) {
				int next = s.charAt(j)-'i'+2;
				cur = mul(cur, next);
				if(state==0 && cur==2) {
					cur = 1;
					state = 1;
				} else if(state==1 && cur==3) {
					cur = 1;
					state = 2;
				}
			}
		}
		if(state==2 && cur == 4)
			println("YES");
		else
			println("NO");
	}
	
	public int mul(int a, int b) {
		int flag = a<0 ^ b<0 ? -1:1;
		return flag * matrix[Math.abs(a)-1][Math.abs(b)-1];
	}
}
