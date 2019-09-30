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
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class Testing {

	static int Q;
	static int M;
	static double[][] probs;

	static Double savedProbs[];
	public static Double probForOption(int option) {
		if (savedProbs[option] != null) return savedProbs[option];
		double pr = 1.0;
		int p = 1;
		for (int i = 0; i < Q; i++, p *= 4) {
			int selection = (option / p) % 4;
			//System.out.print(selection + " ");
			pr *= probs[i][selection];
		}
		//System.out.println(": " + pr);
		savedProbs[option] = pr;
		return pr;
	}

	public static void solve(int cas, Writer w) throws Exception {
		for (int i = 0; i < Q; i++) {
			for (int j = 0; j < 4; j++) {
				System.out.print(probs[i][j] + " ");
			}
			System.out.println();
		}

		List<Integer> options = new ArrayList<Integer>(1 << (2*Q));
		for (int i = 0; i < (1 << (2*Q)); i++) {
			options.add(i);
			probForOption(i);
		}
		Collections.sort(options, new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {

				return -probForOption(o1).compareTo(probForOption(o2));
		} });

		double pr = 0.0;
		for (int i = 0; i < M && i < options.size(); i++) {
			pr += probForOption(options.get(i));
		}
		String prs = Double.toString(pr);
		if (prs.length() > 8) prs = prs.substring(0, 8);
		String answer = "Case #" + cas + ": " + prs;
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
				String MQ = br.readLine();
				String[] parts = MQ.split(" ");
				M = Integer.parseInt(parts[0]);
				Q = Integer.parseInt(parts[1]);
				probs = new double[Q][4];
				savedProbs = new Double[1 << (2*Q)];
				for (int j = 0; j < Q; j++) {
					String[] prbs  = br.readLine().split(" ");
					for (int k = 0; k < 4; k++) {
						probs[j][k] = Double.parseDouble(prbs[k]);
					}
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
