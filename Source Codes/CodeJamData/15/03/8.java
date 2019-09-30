import java.io.*;
import java.util.*;

class Dijkstra {
	static char[][] ab = {
		{ '+', '-', 'i', 'I', 'j', 'J', 'k', 'K' },
		{ '-', '+', 'I', 'i', 'J', 'j', 'K', 'k' },
		{ 'i', 'I', '-', '+', 'k', 'K', 'J', 'j' },
		{ 'I', 'i', '+', '-', 'K', 'k', 'j', 'J' },
		{ 'j', 'J', 'K', 'k', '-', '+', 'i', 'I' },
		{ 'J', 'j', 'k', 'K', '+', '-', 'I', 'i' },
		{ 'k', 'K', 'j', 'J', 'I', 'i', '-', '+' },
		{ 'K', 'k', 'J', 'j', 'i', 'I', '+', '-' },
	};
	static int index(char a) {
		switch (a) {
			case '+': return 0;
			case '-': return 1;
			case 'i': return 2;
			case 'I': return 3;
			case 'j': return 4;
			case 'J': return 5;
			case 'k': return 6;
			case 'K': return 7;
		}
		return -1;
	}
	static char mult(char a, char b) {
		return ab[index(a)][index(b)];
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int l = Integer.parseInt(st.nextToken());
			long x = Long.parseLong(st.nextToken());
			char[] cc = br.readLine().toCharArray();
			char a = '+';
			for (int i = 0; i < l; i++)
				a = mult(a, cc[i]);
			boolean ijk = false;
			if (a == '-' && x % 2 == 1 || a != '-' && a != '+' && x % 4 == 2) {
				int m = l * (int) Math.min(8, x);
				int step = 1;
				a = '+';
				for (int i = 0; i < m; i++) {
					a = mult(a, cc[i % l]);
					if (step == 1 && a == 'i') {
						step = 2;
						a = '+';
					} else if (step == 2 && a == 'j') {
						step = 3;
						ijk = true;
						break;
					}
				}
			}
			pw.println("Case #" + t + ": " + (ijk ? "YES" : "NO"));
		}
		pw.close();
	}
}
