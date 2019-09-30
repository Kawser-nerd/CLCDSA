import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class R1CQ1 {

	public static void main(String[] args) {
		try {
			String fileName = "A-large";
			Scanner in = new Scanner(new File(fileName + ".in"));
			PrintWriter out = new PrintWriter(fileName + ".out");
			int numberOfTestCases = Integer.parseInt(in.nextLine());
			for (int caseNum = 1; caseNum <= numberOfTestCases; caseNum++) {
				int N = Integer.parseInt(in.nextLine());
				String str = in.nextLine();
				String[] countsStr = str.split("\\s+");
				int[] counts = new int[countsStr.length];
				for (int i = 0; i < counts.length; i++) {
					counts[i] = Integer.parseInt(countsStr[i]);
				}
				String result = "";
				int crowd1 = maxIndex(counts, -1);
				int crowd2 = maxIndex(counts, crowd1);
				while (counts[crowd1] != counts[crowd2]) {
					if ((counts[crowd1] - counts[crowd2]) > 1) {
						result += senateParty(crowd1) + senateParty(crowd1) + " ";
						counts[crowd1] -= 2;
					} else {
						result += senateParty(crowd1) + " ";
						counts[crowd1] -= 1;
					}
				}
				for (int i = 0; i < counts.length; i++) {
					if (i == crowd1 || i == crowd2) {
						continue;
					}
					while (counts[i] > 0) {
						if (counts[i] > 1) {
							result += senateParty(i) + senateParty(i) + " ";
							counts[i] -= 2;
						} else {
							result += senateParty(i) + " ";
							counts[i] -= 1;
						}
					}
				}
				for (int i = 0; i < counts[crowd1]; i++) {
					result += senateParty(crowd1) + senateParty(crowd2) + " ";
				}
				out.println("Case #" + caseNum + ": " + result.substring(0, result.length() - 1));
			}
			in.close();
			out.close();
		} catch (Exception ex) {
			ex.printStackTrace();
		}
	}

	public static int maxIndex(int[] a, int ignoreIndex) {
		int max = -1;
		int index = -1;
		for (int i = 0; i < a.length; i++) {
			if (i == ignoreIndex) {
				continue;
			}
			if (a[i] > max) {
				max = a[i];
				index = i;
			}
		}
		return index;
	}

	public static String ALPAHBET = "abcdefghijklmnopqrstuvwxyz".toUpperCase();

	public static String senateParty(int i) {
		return ALPAHBET.substring(i, i + 1);
	}

}
