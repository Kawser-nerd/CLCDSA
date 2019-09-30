import java.io.*;
import java.math.*;
import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Printer pr = new Printer(System.out);

		String a = sc.next();

		BigInteger ba = new BigInteger(a);
		BigInteger bao = ba.add(BigInteger.ONE);
		ba = ba.multiply(ba);
		bao = bao.multiply(bao);

		String sa = ba.toString();
		if (sa.length() % 2 != 0) {
			sa = "0" + sa;
		}
//		String sao = bao.toString();

		for (int i = 1; i < a.length() + 1; i++) {
			String tmp = sa.substring(0, i * 2);
			BigInteger btmp = new BigInteger(tmp);
			BigInteger btmpo = btmp.add(BigInteger.ONE);

			String tmp2 = btmp.toString();
			if (tmp2.length() % 2 != 0) {
				tmp2 = "0" + tmp2;
			}
			while (tmp2.length() < sa.length()) {
				tmp2 += "00";
			}

			BigInteger bt = new BigInteger(tmp2);

			if (bt.compareTo(ba) >= 0 && bt.compareTo(bao) < 0) {
				pr.println(btmp);
				break;
			}

			tmp2 = btmpo.toString();
			if (tmp2.length() % 2 != 0) {
				tmp2 = "0" + tmp2;
			}
			while (tmp2.length() < sa.length()) {
				tmp2 += "00";
			}

			bt = new BigInteger(tmp2);

			if (bt.compareTo(ba) >= 0 && bt.compareTo(bao) < 0) {
				pr.println(btmpo);
				break;
			}

		}

		pr.close();
		sc.close();
	}

	@SuppressWarnings("unused")
	private static class Scanner {
		BufferedReader br;
		Iterator<String> it;

		Scanner (InputStream in) {
			br = new BufferedReader(new InputStreamReader(in));
		}

		String next() throws RuntimeException  {
			try {
				if (it == null || !it.hasNext()) {
					it = Arrays.asList(br.readLine().split(" ")).iterator();
				}
				return it.next();
			} catch (IOException e) {
				throw new IllegalStateException();
			}
		}

		int nextInt() throws RuntimeException {
			return Integer.parseInt(next());
		}

		long nextLong() throws RuntimeException {
			return Long.parseLong(next());
		}

		float nextFloat() throws RuntimeException {
			return Float.parseFloat(next());
		}

		double nextDouble() throws RuntimeException {
			return Double.parseDouble(next());
		}

		void close() {
			try {
				br.close();
			} catch (IOException e) {
//				throw new IllegalStateException();
			}
		}
	}

	private static class Printer extends PrintWriter {
		Printer(PrintStream out) {
			super(out);
		}
	}
}