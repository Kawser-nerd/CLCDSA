import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;

public class C {

	public String solve(int[] a) {
		Arrays.sort(a);
		int n = a.length;
		int total = 0;
		int xor = 0;
		for (int i=0; i<n; i++) {
			xor ^= a[i];
			total += a[i];
		}
		if (xor != 0) {
			return "NO\n";
		}

		total -= a[0];
		return total + "\n";
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
		C c = new C();
		try {
			c.parseFile("C-sample");
			c.parseFile("C-small-attempt0");
			c.parseFile("C-large");
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
