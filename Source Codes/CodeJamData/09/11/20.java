import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.Scanner;

public class A {
	
// 	private static String PNAME = "A-test";
//	private static String PNAME = "A-small-attempt0";
	private static String PNAME = "A-large";
 	
 	private static int BOUND = 11814485;  // < 12M
 	
 	private static int[] ret = new int[1024];

	public static void main(String[] args) throws Exception {
		// I first run genTable() to generate a file with all the answers.
		//genTable();

		BufferedReader preBr = new BufferedReader(new FileReader("A.data"));
		Scanner preIn = new Scanner(preBr);
		while (preIn.hasNextInt()) {
			int key = preIn.nextInt();
			int value = preIn.nextInt();
			ret[key] = value;
		}
		preBr.close();

		BufferedReader br = new BufferedReader(new FileReader(PNAME + ".in"));
		PrintStream out = new PrintStream(PNAME + ".out");
		
		int TC = Integer.parseInt(br.readLine());
		
		for (int tc = 1; tc <= TC; tc++) {
			String line = br.readLine();
			String[] tokens = line.split(" ");
			int bases = 0;
			for (int i = 0; i < tokens.length; i++) {
				int b = Integer.parseInt(tokens[i]);
				bases |= 1 << (b - 2);
			}
			out.println("Case #" + tc + ": " + ret[bases]);
		}
		br.close();
		out.close();
	}

	private static void genTable() throws FileNotFoundException {
		PrintStream out = new PrintStream("A.data");
		precalc();
		for (int b = 1; b < 512; b++) {
			System.out.println(b);
			for (int n = 2; n <= BOUND; n++) {
				if (isVeryHappy(n, b)) {
					out.println(b + " " + n);
					break;
				}
			}
		}
		out.close();
	}

	private static void precalc() {
		for (int n = 2; n <= BOUND; n++)
			for (int b = 2; b <= 10; b++)
				happy[n][b] = isHappy(n, b);
	}

	private static boolean isVeryHappy(int n, int bits) {
		for (int bit = 0; bit <= 8; bit++) if ((bits & (1 << bit)) != 0){
			int base = bit + 2;
			if (!happy[n][base])
				return false;
		}
		return true;
	}
	
	private static boolean[][] happy = new boolean[BOUND + 1][11];

	
	private static boolean isHappy(int n, int b) {
		n = next(n, b);
		boolean[] seen = new boolean[700];
		while (n != 1) {
			if (seen[n]) return false;
			seen[n] = true;
			n = next(n, b);
		}
		return true;
	}

	private static int next(int n, int b) {
		int ret = 0;
		for ( ; n > 0; n /= b)
			ret += (n%b) * (n%b);
		return ret;
	}

}
