package cj2016.r1a;
import java.io.*;
import java.util.*;

public class C {
	Scanner sc;
	PrintWriter pw;
	int N;
	int[] F;

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
		F = new int[N];
		for(int i=0; i<N; i++)
			F[i] = sc.nextInt()-1;
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
		// find a largest circle
		int largestSingleCircle = 0;
		for(int i=0; i<N; i++) {
			int next = i;
			int size = 0;
			for(int j=0; j<N; j++) {
				size++;
				next = F[next];
				if(next==i)
					break;
			}
			if(next==i)
				largestSingleCircle = Math.max(largestSingleCircle, size);
		}
		
		// find BFF pair and Longest arms
		// ex.  1 > 2 > 3 >< 4 < 5 < 6 
		int sum = 0;
		
		for(int i=0; i<N; i++) {
			for(int j=i+1; j<N; j++) {
				if(F[i]==j && F[j]==i) {
					sum += 2 + findMaxDepth(i, j) + findMaxDepth(j, i);
				}
			}
		}
		
		println(Math.max(largestSingleCircle, sum));
	}
	
	int findMaxDepth(int root, int ex) {
		int[] pos = new int[N];
		int[] cnt = new int[N];
		for(int i=0; i<N; i++)
			pos[i] = i;
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				if(pos[j]==ex) {
					cnt[j] = -1;
				} else if(pos[j]!=root) {
					pos[j] = F[pos[j]];
					cnt[j]++;
				}
			}
		}
		int ans = 0;
		for(int i=0; i<N; i++)
			if(pos[i]==root)
				ans = Math.max(ans, cnt[i]);
		
		return ans;
	}
}
