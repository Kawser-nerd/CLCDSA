package cj2016.qr;
import java.io.*;
import java.util.*;

public class A {
	Scanner sc;
	PrintWriter pw;
	int N;
	
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
		N = sc.nextInt();
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
		if(N==0) {
			println("INSOMNIA");
		} else {
			boolean[] show = new boolean[10];
			for(int i=1; i<105; i++) {
				int num = N*i;
				while(num>0) {
					show[num%10]=true;
					num/=10;
				}
				boolean sleep = true;
				for(int j=0; j<10; j++) {
					if(!show[j]) {
						sleep = false;
						break;
					}
				}
				if(sleep) {
					println(N*i);
					return;
				}
			}
		}
	}
	
}
