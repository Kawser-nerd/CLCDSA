import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;


public class ProblemC {
	public static void main(String[] args) throws Exception {
		new ProblemC();
	}

	public ProblemC() throws Exception {
		BufferedReader in = new BufferedReader(new FileReader("input_c.txt"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				"output-C-large.txt")));
		Scanner scan = new Scanner(in);
		int tests = scan.nextInt();
		for (int test = 0; test < tests; test++) {
			int k = scan.nextInt();
			int n = scan.nextInt();
			int[] indices = new int[n];
			for ( int i = 0; i < n; i++) indices[i] = scan.nextInt()-1;
			int[] deck = new int[k];
			int pos = 0;
//			int[] allowed = new int[k];
			tree = new int[1 << (BITS + 1)];
			for ( int i = 0; i < k; i++) put(i);
//			for ( int i = 0; i < k; i++) allowed[i] = i;
			int size = k;
			for ( int i = 1; i <= k; i++) {
				int target = (pos + i - 1) % size;
				deck[get(target)] = i;
//				int[] nAllowed = new int[allowed.length-1];
//				for ( int j = 0; j < target; j++ ) nAllowed[j] = allowed[j];
//				for ( int j = target; j < nAllowed.length; j++) nAllowed[j] = allowed[j+1];
//				allowed = nAllowed;
				pos = target;
				size--;
			}
			String numbers = "";
			for ( int i : indices) numbers += deck[i] + " ";
			numbers = numbers.trim();
			String answer = String.format("Case #%d: %s\n", test + 1, numbers);
			System.out.print(answer);
			out.print(answer);
		}
		out.close();
	}
	final int BITS = 20;
	int[] tree = new int[1 << (BITS + 1)];

	public void put(int x) {
		int k = 1;
		tree[k]++;
		for (int i = BITS - 1; i >= 0; i--)
			if (((1 << i) & x) != 0) {
				tree[2 * k + 1]++;
				k = 2 * k + 1;
			} else {
				tree[2 * k]++;
				k *= 2;
			}
	}

	public int get(int x) {
		// returns x-th element in set (0-based).
		if (x > tree[1])
			return -1;
		tree[1]--;
		int result = 0;
		int k = 1;
		for (int i = BITS - 1; i >= 0; i--) {
			if (x < tree[2 * k])
				k *= 2;
			else {
				result |= 1 << i;
				x -= tree[2 * k];
				k = 2 * k + 1;
			}
			tree[k]--;
		}
		return result;
	}
}
