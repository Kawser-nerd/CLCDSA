import java.util.*;
import java.io.*;

public class Solution {
	public void doMain() throws Exception {
		boolean[] isPrime = new boolean[2000001];
		Arrays.fill(isPrime, true);
		isPrime[1] = false;
		for (int i=2; i <= 2000000; i++)
			if (isPrime[i])
				for (int j=2*i; j <= 2000000; j += i)
					isPrime[j] = false;
		
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		
		int caseCnt = sc.nextInt();
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {
			System.out.println(caseNum);
			
			long N = sc.nextLong();
			long res = (N == 1 ? 0 : 1);
			for (int i=2; i <= 1000000; i++) if (isPrime[i]) {
				long x = i;
				int p = 1;
				while (x * (long)i <= N) {
					x *= (long)i;
					p++;
				}
				res += p - 1;
			}
			pw.println("Case #" + caseNum + ": " + res);
		}
		
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new Solution()).doMain();
	}
}
