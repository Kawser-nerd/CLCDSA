package src.code;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.ArrayList;
import java.util.List;

public class CodeSeq {

	static Integer c0;
	static List<Integer> seq;


	static void reset() {

		c0 = -1;
	}

	static int mod(int x) {
		return ((x % 10007) + 10007) % 10007;
	}

	public static void solve(int cas, Writer w) throws Exception {
		Integer c0odd = null, c0even = null;
		boolean odd = true, even = true;
		int l = seq.size();
		for(int i = 0; i < l; i += 2) {
			if (i < l - 1 && odd) {
				int guess = mod( seq.get(i+1) - seq.get(i) );
				if (c0odd == null) c0odd = guess;
				else if (c0odd != guess) odd = false;
			}
			if (i > 0) {
				int guess = mod (seq.get(i) - seq.get(i-1));
				if (c0even == null) c0even = guess;
				else if (c0even != guess) even = false;
			}
		}
		Integer c0 = null;
		boolean unk = false;
		if (!odd && !even) {
			unk = true;
		} else if (odd && even) {
			if (c0odd != null && c0even != null) unk = true;
			else if (c0odd != null) c0 = c0odd;
			else if (c0even != null) c0 = c0odd;
			else unk = true;
		} else if (odd) {
			if (c0odd != null && l % 2 == 1) c0 = c0odd;
			else unk = true;
		} else if (even) {
			if (c0even != null && l % 2 == 0) c0 = c0even;
			else unk = true;
		}

		if (l < 4) unk = true;

		String answer;
		if (unk) {
			answer = "UNKNOWN";
		} else {
			if (c0 == null) System.out.println("NULL!!!");
			answer = "" + mod(seq.get(l-1) + c0);
		}

		answer = "Case #" + cas + ": " + answer;
		System.out.println(answer);
		w.write(answer + "\n");
	}

	public static void main(String[] args) {
		try {
			FileInputStream fstream = new FileInputStream("c:\\in.txt");
			DataInputStream in = new DataInputStream(fstream);

			FileOutputStream out = new FileOutputStream("c:\\out.txt");
			PrintWriter pw  = new PrintWriter(out);

			runOnInput(in, pw);

			pw.close();
		} catch (Exception e) {
			System.err.println("Error: " + e.getMessage());
		}
	}

	public static void runOnInput(InputStream in, Writer w) throws Exception {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(in));
			int testCount = Integer.parseInt(br.readLine());
			for (int i = 1; i <= testCount; ++i) {
				seq = new ArrayList<Integer>();
				String rootItem = null;
				int K = Integer.parseInt(br.readLine());
				String [] pts = br.readLine().split(" ");
				for (int j = 0; j < K; j++) {
					seq.add(Integer.parseInt(pts[j]));
				}

				solve(i, w);
			}
			in.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.err.println("Error: " + e.getMessage());
		}
	}
}
