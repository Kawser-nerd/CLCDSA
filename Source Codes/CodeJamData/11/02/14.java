import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;

public class B {

	public boolean ops(int e, boolean[][] op, int[] cnt) {
		for (int i=0; i<op[e].length; i++) {
			if (op[e][i] && cnt[i] > 0) {
				return true;
			}
		}
		return false;
	}

	public String solve(int[][] cb, boolean[][] op, int[] seq) {
		int N = seq.length;
		int[] ret = new int[N];
		int idx = 0;
		int[] cnt = new int[26];

		for (int i=0; i<N; i++) {
			ret[idx++] = seq[i];
			cnt[seq[i]] ++;
			while (idx >= 2) {
				int e1 = ret[idx-1];
				int e2 = ret[idx-2];
				if (cb[e1][e2] > 0) {
					idx -= 2;
					ret[idx] = cb[e1][e2] - 1;
					cnt[e1] --;
					cnt[e2] --;
					cnt[ret[idx]] ++;
					idx ++;
				} else if (ops(e1, op, cnt)) {
					Arrays.fill(cnt, 0);
					idx = 0;
				} else {
					break;
				}
			}
		}
		if (idx == 0) {
			return "[]\n";
		} else {
			StringBuilder sb = new StringBuilder();
			sb.append("[");
			char c = (char)(ret[0] + 'A');
			sb.append(c);
			for (int i=1; i<idx; i++) {
				c = (char)(ret[i] + 'A');
				sb.append(", " + c);
			}
			sb.append("]\n");
			return sb.toString();
		}
	}

	////////////////////////////////////////
	// read input
	////////////////////////////////////////
	public String runInput(BufferedReader br) throws IOException {
		String[] items = br.readLine().trim().split("\\s+");
		int idx = 0;

		int C = Integer.parseInt(items[idx++]);
		int[][] cb = new int[26][26];
		for (int i=0; i<C; i++) {
			int e1 = items[idx].charAt(0) - 'A';
			int e2 = items[idx].charAt(1) - 'A';
			int e3 = items[idx].charAt(2) - 'A';
			cb[e1][e2] = e3 + 1;
			cb[e2][e1] = e3 + 1;
			idx ++;
		}

		int D = Integer.parseInt(items[idx++]);
		boolean[][] op = new boolean[26][26];
		for (int i=0; i<D; i++) {
			int e1 = items[idx].charAt(0) - 'A';
			int e2 = items[idx].charAt(1) - 'A';
			op[e1][e2] = true;
			op[e2][e1] = true;
			idx ++;
		}

		int N = Integer.parseInt(items[idx++]);
		int[] seq = new int[N];
		for (int i=0; i<N; i++) {
			int e1 = items[idx].charAt(i) - 'A';
			seq[i] = e1;
		}

		return solve(cb, op, seq);
	}

	////////////////////////////////////////
	// main
	////////////////////////////////////////
	public static void main(String[] args) {
		B b = new B();
		try {
			//b.parseFile("B-sample");
			//b.parseFile("B-small-attempt0");
			b.parseFile("B-large");
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	////////////////////////////////////////
	// library
	////////////////////////////////////////
	public void parseFile(String filePrefix) throws IOException {
		String fileIn = filePrefix + ".in";
		String fileOut = filePrefix + ".out";

		BufferedReader br = new BufferedReader(new FileReader(fileIn));
		BufferedWriter bw = new BufferedWriter(new FileWriter(fileOut));

		int n = Integer.parseInt(br.readLine());
		for (int i=1; i<=n; i++) {
			String ret = "Case #" + i + ": ";
			ret += runInput(br);
			System.out.print(ret);
			bw.write(ret);
		}
		br.close();
		bw.close();
	}

}
