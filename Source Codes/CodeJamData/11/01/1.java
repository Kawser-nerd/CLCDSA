import java.util.*;
import java.io.*;

public class Solution {
	public void doMain() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		
		int caseCnt = sc.nextInt();
		
		for (int caseNum = 0; caseNum < caseCnt; caseNum++) {
			pw.print("Case #" + (caseNum + 1) + ": ");
			
			int curO = 1, spareStepsO = 0, curB = 1, spareStepsB = 0;
			
			int N = sc.nextInt();
			int res = 0;
			for (int i=0; i < N; i++) {
				String who = sc.next();
				if (who.equals("O")) {
					int pos = sc.nextInt();
					int dist = Math.abs(curO - pos) + 1;
					dist -= Math.min(spareStepsO, dist - 1);
					res += dist;
					spareStepsB += dist;
					spareStepsO = 0;
					curO = pos;
				} else {
					int pos = sc.nextInt();
					int dist = Math.abs(curB - pos) + 1;
					dist -= Math.min(spareStepsB, dist - 1);
					res += dist;
					spareStepsO += dist;
					spareStepsB = 0;
					curB = pos;
				}
			}
			
			pw.println(res);
		}
		
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		new Solution().doMain();
	}
}
