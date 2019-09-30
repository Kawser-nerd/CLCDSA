import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class D {

	public void doexp() {
		if (exp.length < 3) {
			return;
		}
		exp[2] = 2;
		for (int i=3; i<exp.length; i++) {
			exp[i] = i;
		}
	}
	double[] exp;

	public String solve(int[] a) {
		int n = a.length;
		exp = new double[n+1];
		doexp();
		boolean[] v = new boolean[n];
		double ret = 0;

		for (int i=0; i<n; i++) {
			int cnt = 0;
			int idx = i;
			while (!v[idx] && (idx != a[idx]-1)) {
				cnt ++;
				v[idx] = true;
				idx = a[idx] - 1;
			}
			if (cnt > 0) {
				ret += exp[cnt];
			}
		}

		return ret + "\n";
	}

	////////////////////////////////////////
	// read input
	////////////////////////////////////////
	public String runInput(BufferedReader br) throws IOException {
		int n = Integer.parseInt(br.readLine().trim());
		String[] items = br.readLine().trim().split("\\s+");
		int[] a = new int[n];
		for (int i=0; i<n; i++) {
			a[i] = Integer.parseInt(items[i]);
		}

		return solve(a);
	}

	////////////////////////////////////////
	// main
	////////////////////////////////////////
	public static void main(String[] args) {
		D d = new D();
		try {
			d.parseFile("D-sample");
			d.parseFile("D-small-attempt0");
			d.parseFile("D-large");
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
