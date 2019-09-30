import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigInteger;

public class Bq {
	public static void main(String[] args) throws NumberFormatException, IOException {
		String fileName = "B-large";
		BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream(fileName + ".in")));
		BufferedWriter out = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(fileName + ".out")));
		int T = Integer.parseInt(in.readLine());
		for (int u = 1; u <= T; ++u) {
			String line = in.readLine();
			String[] nums = line.split(" ");
			int N = Integer.parseInt(nums[0]);
			BigInteger[] a = new BigInteger[N];
			for (int i = 0; i < N; ++i)
				a[i] = new BigInteger(nums[i+1]);
			BigInteger g = BigInteger.ZERO;
			for (int i = 0; i < N; ++i)
				for (int j = i+1; j < N; ++j)
					g = gcd(g, a[i].subtract(a[j]).abs());
			BigInteger r = a[0].mod(g);
			for (int i = 0; i < N; ++i)
				if (!a[i].mod(g).equals(r)) {
					System.out.println("Error: Case: " + u);
					for (int j = 0; j < N; ++j)
						System.out.print(a[j] + " ");
					System.out.println();
				}
			if (!r.equals(BigInteger.ZERO)) r = g.subtract(r);
			out.write("Case #" + u + ": " + r + "\n");
		}
		out.close();
	}

	private static BigInteger gcd(BigInteger a, BigInteger b) {
		if (a.compareTo(b) < 0) {
			BigInteger temp = a;
			a = b;
			b = temp;
		}
		if (b.equals(BigInteger.ZERO)) return a;
		return gcd(b, a.mod(b));
	}
}
