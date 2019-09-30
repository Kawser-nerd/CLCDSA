import java.util.*;
import java.io.*;

public class Solution {
	public void doMain() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		
		int T = sc.nextInt();
		
		for (int caseNum=1; caseNum <= T; caseNum++) {
			System.out.println("case " + caseNum);
			
			int L = sc.nextInt();
			long t = sc.nextLong();
			int N = sc.nextInt();
			int C = sc.nextInt();
			long[] a = new long[N];
			for (int i=0; i < C; i++)
				a[i] = sc.nextLong();
			for (int i=C; i < N; i++)
				a[i] = a[i-C];

			long res = 0;
			for (int i=0; i < N; i++)
				res += 4 * a[i];
			
			int pos = 0;
			while (pos < N && 2 * a[pos] <= t) {
				t -= 2 * a[pos];
				pos++;
			}
			
			if (pos < N) {
				List<Long> ll = new ArrayList<Long>();
				ll.add(2 * a[pos] - t);
				for (int i=pos+1; i < N; i++)
					ll.add(2 * a[i]);
				Collections.sort(ll);
				for (int i=ll.size()-1; i >= 0 && i >= ll.size() - L; i--) {
					res -= ll.get(i);
				}
			}
			
			if (res % 2 == 1) {
				System.out.println("failure");
				System.exit(0);
			} else pw.println("Case #" + caseNum + ": " + res/2);
		}
		
		sc.close();
		pw.flush();
		pw.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new Solution()).doMain();
	}
}
