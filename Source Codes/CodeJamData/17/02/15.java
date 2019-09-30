import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class b {
	public static void main(String[] Args) throws Exception {
		// Scanner sc = new Scanner(System.in);
		Scanner sc = new Scanner(new File("B-large.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(new File("b.out"))));
		// PrintWriter out = new PrintWriter(System.out);
		int cc = 0;
		int t = sc.nextInt();
		while (t-- > 0) {
			// Read input
			String x = sc.next();

			// Greedily convert to trailing 9s
			for (int i = 0; i < x.length(); i++)
				for (int j = 0; j + 1 < x.length(); j++)
					if (x.charAt(j) > x.charAt(j + 1)) {
						String nx = x.substring(0, j);
						nx = nx + (char) (x.charAt(j) - 1);
						while (nx.length() < x.length())
							nx = nx + "9";
						x = nx;
					}

			// remove leading zeros flip pancakes
			while (x.length() > 1 && x.charAt(0) == '0')
				x = x.substring(1);

			// Print
			out.printf("Case #%d: %s%n", ++cc, x);
		}
		out.close();
	}
}
