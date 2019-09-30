import java.util.*;
import java.math.*;
import java.io.*;

public class Solution {
	public void go() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int caseCnt = sc.nextInt();
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {
			System.out.println("Processing case " + caseNum);
			pw.print("Case #" + caseNum + ": ");
			
			int N = sc.nextInt();
			
			if (N==0) {
				pw.println(0);
				continue;
			}
			
			int[] cnt = new int[10002];
			for (int i=0; i < N; i++) {
				int x = sc.nextInt();
				cnt[x]++;
			}
			
			int res = Integer.MAX_VALUE;
			for (int pos=0; pos <= 10000; pos++)
				while (cnt[pos] > 0) {
					int i = pos;
					while (cnt[i] <= cnt[i+1]) i++;
					res = Math.min(res, i - pos + 1);
					for (int x=pos; x <= i; x++)
						cnt[x]--;
				}
			
			pw.println(res);
		}
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new Solution()).go();
	}
}
