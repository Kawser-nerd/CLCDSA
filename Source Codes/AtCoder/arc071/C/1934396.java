import java.io.*;
import java.util.*;
	
public class Main {
	private static int[] prep(String s) {
		int[] sPre = new int[s.length() + 1];
		for(int i = 1; i <= s.length(); i++) {
			char c = s.charAt(i - 1);
			if(c == 'A') {
				sPre[i] = sPre[i - 1] + 1;
			} else {
				sPre[i] = sPre[i - 1] + 2;
			}
		}
		return sPre;
	}
	public static void main(String[] args) throws IOException {
		BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
		String s = f.readLine();
		String t = f.readLine();
		int[] sPre = prep(s);
		int[] tPre = prep(t);
		int q = Integer.parseInt(f.readLine());
		for(int i = 0; i < q; i++) {
			StringTokenizer st = new StringTokenizer(f.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			int d = Integer.parseInt(st.nextToken());
			if((sPre[b] - sPre[a - 1]) % 3 == (tPre[d] - tPre[c - 1]) % 3) {
				System.out.println("YES");
			} else {
				System.out.println("NO");
			}
		}
	}
}