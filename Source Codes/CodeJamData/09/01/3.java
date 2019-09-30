import java.io.*;
import java.util.*;


public class Solution {

	public static BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));
	public static StringTokenizer tok = null;
	
	public static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(cin.readLine());
		}
		return tok.nextToken();
	}
	
	public static int nextInt() throws NumberFormatException, IOException {
		return Integer.parseInt(next());
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		int L = nextInt();
		int D = nextInt();
		int N = nextInt();
		String[] dict = new String[D];
		for (int i = 0; i < D; i++)
			dict[i] = cin.readLine();
		
		for (int i = 0; i < N; i++) {
			String pat = cin.readLine();
			TreeSet[] st = new TreeSet[L];
			for (int j = 0; j < L; j++) {
				st[j] = new TreeSet();
			}
			int k = 0;
			for (int j = 0; j < pat.length(); j++) {
				if (pat.charAt(j) != '(') {
					st[k].add(Character.valueOf(pat.charAt(j)));
					k++;
				} else {
					j++;
					while (pat.charAt(j) != ')') {
						st[k].add(Character.valueOf(pat.charAt(j)));
						j++;
					}
					k++;
				}
			}
			int ans = 0;
			for (int j = 0; j < D; j++) {
				boolean ok = true;
				for (int t = 0; t < L; t++) {
					if (!st[t].contains(Character.valueOf(dict[j].charAt(t)))) {
						ok = false;
						break;
					}
				}
				if (ok)
					ans++;
			}
			System.out.println("Case #" + (i + 1) + ": " + ans);
		}

	}

}
