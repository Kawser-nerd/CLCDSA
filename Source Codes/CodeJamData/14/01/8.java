import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;


public class ProblemA {
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("A-small-attempt0.in"));
		System.setOut(new PrintStream(new FileOutputStream("A-small-attempt0.out")));
		
		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt();
		
		for (int caseNum = 1; caseNum <= T; caseNum++) {
			int[] counts = new int[17];
			for (int turn = 0; turn < 2; turn++) {
				int row = in.nextInt() - 1;
				for (int r = 0; r < 4; r++) {
					for (int c = 0; c < 4; c++) {
						int n = in.nextInt();
						if (r == row) {
							counts[n]++;
						}
					}
				}
			}
			int res = -2;
			for (int i = 1; i <= 16; i++) {
				if (counts[i] == 2) {
					if (res == -2) {
						res = i;
					} else {
						res = -1;
					}
				}
			}
			if (res > 0) {
				System.out.printf("Case #%d: %d%n", caseNum, res);
			} else {
				System.out.printf("Case #%d: %s%n", caseNum, (res==-2)?"Volunteer cheated!":"Bad magician!");
			}
		}
	}
}
