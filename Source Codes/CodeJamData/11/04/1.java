import java.util.*;
import java.io.*;

public class Solution {
	public void doIt() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		
		final int MAX = 1000;
		
		double[] invFact = new double[MAX+1];
		invFact[0] = 1.0;
		for (int i=1; i <= MAX; i++)
			invFact[i] = invFact[i-1] / (double)i;
		
		double[] derang = new double[MAX+1];
		derang[0] = invFact[0];
		for (int i=1; i <= MAX; i++)
			derang[i] = derang[i-1] + (i % 2 == 1 ? -1 : 1) * invFact[i];
		
		double[] avgTime = new double[MAX+1];
		avgTime[0] = 0.0;
		for (int i=1; i <= MAX; i++) {
			double sum = 1.0;
			for (int j=1; j <= i; j++)
				sum += avgTime[i - j] * invFact[j] * derang[i - j];
			
			avgTime[i] = sum / (1 - invFact[0] * derang[i]);
		}
		
		int caseCnt = sc.nextInt();
		
		for (int caseNum = 0; caseNum < caseCnt; caseNum++) {
			int N = sc.nextInt();
			int ans = 0;
			for (int i=1; i<=N; i++) {
				int x = sc.nextInt();
				if (x != i) ans++;
			}
			pw.println("Case #" + (caseNum+1) + ": " + ans);
		}
		
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		new Solution().doIt();
	}
}
