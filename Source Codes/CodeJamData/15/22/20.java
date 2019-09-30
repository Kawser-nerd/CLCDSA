package cj2015.r1b;
import java.io.*;
import java.util.*;

public class B {
	Scanner sc;
	PrintWriter pw;
	int R,C,N;
	
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
		R = sc.nextInt();
		C = sc.nextInt();
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
		int ans=1000000;
		int[] dx = {0, 1, 0, -1};
		int[] dy = {1, 0, -1, 0};
		if(R>C) {
			int temp = R;
			R = C;
			C = temp;
		}
		
		for(int t=0; t<2; t++) {
			int[] noise = new int[5];
			
			for(int i=0; i<R; i++) {
				for(int j=0; j<C; j++) {
					if((i+j+t)%2==0) {
						int cnt=0;
						for(int d=0; d<4; d++) {
							int ny = i+dy[d];
							int nx = j+dx[d];
							if(0<=ny && ny<R && 0<=nx && nx<C)
								cnt++;
						}
						noise[cnt]++;
					} else {
						noise[0]++;
					}
				}
			}
			
			int temp = 0;
			int unit=N;
			for(int i=0; i<5; i++) {
				if(unit>0) {
					int in = Math.min(unit, noise[i]);
					unit -= in;
					temp += in*i;
				}
			}
			ans = Math.min(ans, temp);
		}
		
		println(ans);
	}
	
}
