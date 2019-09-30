
import java.io.*;
import java.util.*;

public class A {
	int getInt(BufferedReader in) throws IOException {
		return Integer.parseInt(in.readLine());
	}   
	int[] getInts(BufferedReader in) throws IOException {
		String[] words = in.readLine().split(" ");
		int[] ret = new int[words.length];
		for (int i = 0 ; i < words.length ; i++) ret[i] = Integer.parseInt(words[i]);
		return ret;
	}

	String[] NUM = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

	int diff(int[] sig, String pos, String neg) {
		int sum = 0;
		for (char c : pos.toCharArray()) {
			sum += sig[c-'A'];
		}
		for (char c : neg.toCharArray()) {
			sum -= sig[c-'A'];
		}
		return sum;
	}

	String compute(int[] sig) {
		int[] s = {
			diff(sig, "Z", ""),      // 0
			diff(sig, "O", "ZWU"),   // 1
			diff(sig, "W", ""),      // 2
			diff(sig, "H", "G"),     // 3
			diff(sig, "U", ""),      // 4
			diff(sig, "F", "U"),     // 5
			diff(sig, "X", ""),      // 6
			diff(sig, "S", "X"),     // 7
			diff(sig, "G", ""),      // 8
			diff(sig, "IU", "FXG"),  // 9
		};
		StringBuilder sb = new StringBuilder();
		for (int d = 0 ; d < 10 ; d++) {
			while (s[d]-- > 0) sb.append(d);
		}
		return sb.toString();
	}

	void run(String[] args) {
		try {
			BufferedReader in = new BufferedReader(new FileReader(args[0]));
		    PrintStream out = new PrintStream(args[0] + ".out");
			int T = getInt(in);
			for (int t = 1 ; t <= T ; t++) {
				String s = in.readLine();
				int[] sig = new int[30];
				for (char c : s.toCharArray()) {
					sig[c-'A']++;
				}
				out.printf("Case #%d: %s\n", t, compute(sig));
			}
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	public static void main (String[] args) {
		new A().run(args);
	}
}
