package cj2015.qr;
import java.io.*;
import java.util.*;

public class D {
	Scanner sc;
	PrintWriter pw;
	int X,R,C;

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
		X = sc.nextInt();
		R = sc.nextInt();
		C = sc.nextInt();
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
		if(canFill(X,R,C))
			println("GABRIEL");
		else
			println("RICHARD");
	}

	public boolean canFill(int x, int r, int c) {
		if(r>c) {
			int temp = r;
			r = c;
			c = temp;
		}
		
		// single N-omino can make a hole
		if(x>=7)
			return false;
		
		// number of cells mismatch
		if((r*c)%x!=0)
			return false;
		
		// extend outside the grid
		if(x>c || (x+1)/2>r)
			return false;
		
		// obviously true
		if(x<=3)
			return true;
		
		// single N-omino can separate the grid into the 2 parts which size never be multiple of x
		if((x+1)/2==r)
			if(x==4 || x==6 || (x==5 && c==5))
				return false;
		
		return true;
	}
}
