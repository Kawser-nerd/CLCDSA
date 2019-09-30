import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class R1CQ3 {

	public static void main(String[] args) {
		try {
			String fileName = "C-large";
			Scanner in = new Scanner(new File(fileName + ".in"));
			PrintWriter out = new PrintWriter(fileName + ".out");
			int numberOfTestCases = in.nextInt();
			for (int caseNum = 1; caseNum <= numberOfTestCases; caseNum++) {
				int J = in.nextInt();
				int P = in.nextInt();
				int S = in.nextInt();
				int k = in.nextInt();
				int dayCount = 0;
				String result = "";
				for (int j = 1; j <= J; j++) {
					for (int p = 1; p <= P; p++) {
						for (int i = 0; i < S && i < k; i++) {
							dayCount++;
							int a = (((i + p + j) % S) + 1);
							result += j + " " + p + " " + a + "\n";
						}
					}
				}
				out.println("Case #" + caseNum + ": " + dayCount + "\n" + result.substring(0, result.length() - 1));
			}
			in.close();
			out.close();
		} catch (Exception ex) {
			ex.printStackTrace();
		}
	}

}
