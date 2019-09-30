import java.util.*;
import java.io.*;

public class Alphabetomials {
	int[][] cnt;
	
	int pow(int a, int b) {
		int res = 1;
		for (int i=1; i <= b; i++)
			res *= a;
		return res;
	}
	
	int getValue(String s) {
		int sum = 0;
		for (int i=0; i < cnt.length; i++) {
			int add = 1;
			for (int j=0; j < s.length(); j++)
				add = (add * cnt[i][s.charAt(j) - 'a']) % 10009;
			sum = (sum + add) % 10009;
		}
		return sum;
	}
	
	public int solve(String item, int k) {
		int mx = pow(k, item.length());
		int[] ind = new int[item.length()];
		int sum = 0;
		for (int pos=0; pos < mx; pos++) {
			int tmp = pos;
			for (int i=0; i < item.length(); i++) {
				ind[i] = tmp % k;
				tmp /= k;
			}
			
			int add = 1;
			for (int i=0; i < k; i++) {
				String s = "";
				for (int j=0; j < item.length(); j++)
					if (ind[j] == i) s += item.charAt(j);
				add = (add * getValue(s)) % 10009;
			}
			sum = (sum + add) % 10009;
		}
		return sum;
	}
	
	public int solveSlow(String item, int k) {
		int mx = pow(cnt.length, k);
		int[] ind = new int[k];
		int sum = 0;
		for (int pos=0; pos < mx; pos++) {
			int tmp = pos;
			for (int i=0; i < k; i++) {
				ind[i] = tmp % cnt.length;
				tmp /= cnt.length;
			}
			int add = 1;
			for (int i=0; i < item.length(); i++) {
				int tot = 0;
				for (int j=0; j < k; j++)
					tot += cnt[ind[j]][item.charAt(i)-'a'];
				add = (add * tot) % 10009;
			}
			sum = (sum + add) % 10009;
		}
		return sum;
	}
	
	public void doMain() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		
		int caseCnt = sc.nextInt();
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {
			System.out.println(caseNum);
			
			// input
			StringTokenizer st = new StringTokenizer(sc.next(), "+");
			List<String> items = new ArrayList<String>();
			while (st.hasMoreTokens())
				items.add(st.nextToken());
			
			int K = sc.nextInt();
			int N = sc.nextInt();
			cnt = new int[N][26];
			for (int i=0; i < N; i++) {
				String w = sc.next();
				//if (caseNum==16) System.out.println(w);
				for (int j=0; j < w.length(); j++)
					cnt[i][w.charAt(j) - 'a']++;
			}
			
			// output
			pw.print("Case #" + caseNum + ":");
			for (int k=1; k <= K; k++) {
				int res = 0;
				for (String item : items)
					res = (res + solve(item, k)) % 10009;
				pw.print(" " + res);
			}
			pw.println();
		}
		
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new Alphabetomials()).doMain();
	}
}