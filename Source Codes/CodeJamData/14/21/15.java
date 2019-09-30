import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;


public class Repeater {
	static BufferedReader stdin = new BufferedReader(
			new InputStreamReader(System.in));
	static StringTokenizer st = new StringTokenizer("");

	// Read next input-token as string.
	static String readString() throws Exception {
		while (!st.hasMoreTokens()) {
			st = new StringTokenizer(stdin.readLine());
		}
		return st.nextToken();
	}

	// Read next input-token as integer.
	static int readInt() throws Exception {
		return Integer.parseInt(readString());
	}

	// Read next input-token as double.
	static double readDouble() throws Exception {
		return Double.parseDouble(readString());
	}
	
	public static void main(String[] args) throws Exception {
		int T = readInt();
		for (int t=1; t<=T ; t++) {
			System.out.printf("Case #%d: ", t);
			solve();
		}
	}
	
	static void solve() throws Exception {
		int N = readInt();
		List<String> words = new ArrayList<String>();
		for (int i = 0 ; i<N; i++) {
			words.add(readString());
		}
		String stripped = func(words.get(0));
		ArrayList<ArrayList<Integer>> freqs = new ArrayList<ArrayList<Integer>> ();
		for (int i = 0 ; i<N; i++) {
			freqs.add(func2(words.get(i)));
			if (!stripped.equals(func(words.get(i)))) {
				System.out.printf("%s\n", "Fegla won");
				return;
			}
		}
		int totalmoves = 0;
		for (int k = 0; k<stripped.length() ; k++) {
			int[] freq2 = new int[N];
			for (int i=0; i<N; i++) {
				freq2[i] = (freqs.get(i).get(k));
			}
			Arrays.sort(freq2);
			int median = freq2[N/2];
			for (int i=0; i<N; i++) {
				totalmoves += Math.abs(median - freq2[i]);
			}
		}
		System.out.printf("%d\n", totalmoves);
		return;
	}
	
	static String func(String input) {
		String res = input.substring(0,1);
		char prevChar = input.charAt(0);
		for (int i = 1; i < input.length() ; i++) {
			if (input.charAt(i) != prevChar) {
				res += input.charAt(i);
				prevChar = input.charAt(i);
			}
		}
		return res;
	}
	
	static ArrayList<Integer> func2(String input) {
		ArrayList<Integer> res = new ArrayList<Integer>();
		res.add(1);
		int idx = 0;
		char prevChar = input.charAt(0);
		for (int i = 1; i < input.length() ; i++) {
			if (input.charAt(i) != prevChar) {
				res.add(1);
				idx++;
				prevChar = input.charAt(i);
			} else {
				res.set(idx, res.get(idx) + 1);
			}
		}
		return res;
	}
}
