import java.util.*;
import java.io.*;

public class GCJ_B {
	public void doIt() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int caseCnt = sc.nextInt();
		for (int caseNum = 0; caseNum < caseCnt; caseNum++) {
			pw.print("Case #" + (caseNum + 1) + ": ");
			int combCnt = sc.nextInt();
			boolean[][] isComb = new boolean[26][26];
			char[][] comb = new char[26][26];
			for (int i=0; i < combCnt; i++) {
				String s = sc.next();
				isComb[s.charAt(0) - 'A'][s.charAt(1) - 'A'] = true;
				isComb[s.charAt(1) - 'A'][s.charAt(0) - 'A'] = true;
				comb[s.charAt(0) - 'A'][s.charAt(1) - 'A'] = s.charAt(2);
				comb[s.charAt(1) - 'A'][s.charAt(0) - 'A'] = s.charAt(2);
			}
			
			int oppCnt = sc.nextInt();
			boolean[][] isOpp = new boolean[26][26];
			for (int i=0; i < oppCnt; i++) {
				String s = sc.next();
				isOpp[s.charAt(0) - 'A'][s.charAt(1) - 'A'] = true;
				isOpp[s.charAt(1) - 'A'][s.charAt(0) - 'A'] = true;
			}
			
			int N = sc.nextInt();
			
			String s = sc.next();
			
			List<Character> cur = new ArrayList<Character>();
			
			for (char c : s.toCharArray()) {
				cur.add(c);
				if (cur.size() > 1) {
					char p = cur.get(cur.size() - 2);
					if (isComb[p-'A'][c-'A']) {
						cur.remove(cur.size() - 1);
						cur.remove(cur.size() - 1);
						cur.add(comb[p-'A'][c-'A']);
					} else {
						for (int i=0; i < cur.size() - 1; i++) {
							char x = cur.get(i);
							if (isOpp[x-'A'][c-'A']) {
								cur = new ArrayList<Character>();
								break;
							}
						}
					}
				}
			}
			
			pw.print("[");
			for (int i=0; i < cur.size(); i++) {
				if (i >= 1) pw.print(", ");
				pw.print(cur.get(i));
			}
			pw.println("]");
		}
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		new GCJ_B().doIt();
	}
}
