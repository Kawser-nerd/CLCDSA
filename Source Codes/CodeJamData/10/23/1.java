import java.util.*;
import java.io.*;
import java.math.*;

public class Solution {
	final long MODULE = 100003;
	
	final int MAX = 500;
	
	long[][] memo;
	
	long[][] C = new long[MAX+1][MAX+1];
	
	public void doMain() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		
		int caseCnt = sc.nextInt();
		
		long time = System.currentTimeMillis();
		
		for (int i=0; i<=MAX; i++) {
			C[i][0] = C[i][i] = 1;
			for (int j=1; j<i; j++)
				C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MODULE;
		}
		
		memo = new long[MAX+1][MAX+1];
		
		for (int n=2; n<=MAX; n++) {
			memo[n][1] = 1;
			for (int pos=2; pos<n; pos++) {
				memo[n][pos] = 0;
				for (int prev=1; prev<pos; prev++) {
					int slots = pos - prev - 1;
					int variants = n - pos - 1;
					if (variants < slots) continue;
					memo[n][pos] = (memo[n][pos] + C[variants][slots] * memo[pos][prev]) % MODULE;					
				}
				
				//System.out.println(n + " " + pos + " " + memo[n][pos]);
			}
		}
		
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {			
			pw.print("Case #" + caseNum + ": ");
			
			int n = sc.nextInt();
			
			long res = 0;
			for (int pos=1; pos<n; pos++) res = (res + memo[n][pos]) % MODULE;
			
			pw.println(res);
			
			System.out.println("Finished testcase " + caseNum + ", time = " + (System.currentTimeMillis() - time));
		}
		
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new Solution()).doMain();
	}
}