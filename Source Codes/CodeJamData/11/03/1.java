import java.util.*;
import java.io.*;

public class Solution {
	public void doMain() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		
		int caseCnt = sc.nextInt();
		
		for (int caseNum = 0; caseNum < caseCnt; caseNum++) {
			pw.print("Case #" + (caseNum + 1) + ": ");
			int N = sc.nextInt();
			int xor = 0, min = Integer.MAX_VALUE, sum = 0;
			for (int i=0; i < N; i++) {
				int x = sc.nextInt();
				xor ^= x;
				sum += x;
				min = Math.min(min, x);
			}
			pw.println(xor == 0 ? sum - min : "NO");
		}
		
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		new Solution().doMain();
	}
}
