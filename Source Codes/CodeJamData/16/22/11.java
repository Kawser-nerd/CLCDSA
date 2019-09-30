
import java.io.*;
import java.util.*;
import java.math.*;

public class B {
	int getInt(BufferedReader in) throws IOException {
		return Integer.parseInt(in.readLine());
	}   
	int[] getInts(BufferedReader in) throws IOException {
		String[] words = in.readLine().split(" ");
		int[] ret = new int[words.length];
		for (int i = 0 ; i < words.length ; i++) ret[i] = Integer.parseInt(words[i]);
		return ret;
	}

	String rep(char[] A, int i, char c, char d) {
		char[] res = A.clone();
		res[i] = c;
		for (int j = i + 1 ; j < A.length ; j++) if (res[j] == '?') res[j] = d;
		return new String(res);
	}

	String compute(String a, String b) {
		int N = a.length();
		char[] A = a.toCharArray();
		char[] B = b.toCharArray();
		List<String> sol = new ArrayList<>();
		for (int i = 0 ; i < N ; i++) {
			if (A[i] == '?') {
				if (B[i] == '?') {
					sol.add(rep(A, i, '1', '0') + " " + rep(B, i, '0', '9'));
					sol.add(rep(A, i, '0', '9') + " " + rep(B, i, '1', '0'));
					A[i] = B[i] = '0';
				} else {
					if (B[i] < '9') sol.add(rep(A, i, (char)(B[i]+1), '0') + " " + rep(B, i, B[i], '9'));
					if (B[i] > '0') sol.add(rep(A, i, (char)(B[i]-1), '9') + " " + rep(B, i, B[i], '0'));
					A[i] = B[i];
				}
			} else {
				if (B[i] == '?') {
					if (A[i] < '9') sol.add(rep(A, i, A[i], '9') + " " + rep(B, i, (char)(A[i]+1), '0'));
					if (A[i] > '0') sol.add(rep(A, i, A[i], '0') + " " + rep(B, i, (char)(A[i]-1), '9'));
					B[i] = A[i];
				} else if (A[i] < B[i]) {
					for (int j = i + 1 ; j < N ; j++) {
						if (A[j] == '?') A[j] = '9';
						if (B[j] == '?') B[j] = '0';
					}
				} else if (B[i] < A[i]) {
					for (int j = i + 1 ; j < N ; j++) {
						if (A[j] == '?') A[j] = '0';
						if (B[j] == '?') B[j] = '9';
					}
				}
			}
		}
		String cur = new String(A) + " " + new String(B);
		for (String s : sol) {
			String[] cw = cur.split(" ");
			BigInteger ca = new BigInteger(cw[0]);
			BigInteger cb = new BigInteger(cw[1]);
			String[] sw = s.split(" ");
			BigInteger sa = new BigInteger(sw[0]);
			BigInteger sb = new BigInteger(sw[1]);
			if (ca.subtract(cb).abs().compareTo(sa.subtract(sb).abs()) > 0 ||
				ca.subtract(cb).abs().equals(sa.subtract(sb).abs()) && (
					ca.compareTo(sa) > 0 ||
					(ca.compareTo(sa) == 0 && cb.compareTo(sb) > 0))) {
				cur = s;
			}
		}
		return cur;
	}

	void run(String[] args) {
		try {
			BufferedReader in = new BufferedReader(new FileReader(args[0]));
		    PrintStream out = new PrintStream(args[0] + ".out");
			int T = getInt(in);
			for (int t = 1 ; t <= T ; t++) {
				String[] w = in.readLine().split(" ");
				out.printf("Case #%d: %s\n", t, compute(w[0],w[1]));
			}
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	public static void main (String[] args) {
		new B().run(args);
	}
}
