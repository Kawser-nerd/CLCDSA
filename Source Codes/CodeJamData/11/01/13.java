import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class A {

	public String solve(boolean[] r, int[] p) {
		int n = r.length;
		int ret = 0;
		int i1 = 1;
		int i2 = 1;
		int last1 = 0;
		int last2 = 0;
		for (int i=0; i<n; i++) {
			if (r[i]) {
				int d = Math.abs(p[i] - i1) - (ret - last1);
				if (d < 0) {
					d = 0;
				}
				ret += d + 1;
				last1 = ret;
				i1 = p[i];
			} else {
				int d = Math.abs(p[i] - i2) - (ret - last2);
				if (d < 0) {
					d = 0;
				}
				ret += d + 1;
				last2 = ret;
				i2 = p[i];
			}
		}
		return ret + "\n";
	}

	////////////////////////////////////////
	// read input
	////////////////////////////////////////
	public String runInput(BufferedReader br) throws IOException {
		String[] items = br.readLine().trim().split("\\s+");
		int n = Integer.parseInt(items[0]);
		boolean[] r = new boolean[n];
		int[] p = new int[n];
		for (int i=0; i<n; i++) {
			int i1 = i * 2 + 1;
			int i2 = i * 2 + 2;
			if (items[i1].equals("B")) {
				r[i] = true;
			}
			p[i] = Integer.parseInt(items[i2]);
		}

		return solve(r, p);
	}

	////////////////////////////////////////
	// main
	////////////////////////////////////////
	public static void main(String[] args) {
		A a = new A();
		try {
			a.parseFile("A-sample");
			a.parseFile("A-small-attempt0");
			a.parseFile("A-large");
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
