import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;


public class ProblemD {
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("D-large.in"));
		System.setOut(new PrintStream(new FileOutputStream("D-large.out")));
		
		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt();
		
		for (int caseNum = 1; caseNum <= T; caseNum++) {
			int N = in.nextInt();
			
			double[] b1 = new double[N];
			for (int i = 0; i < N; i++) {
				b1[i] = in.nextDouble();
			}
			double[] b2 = new double[N];
			for (int i = 0; i < N; i++) {
				b2[i] = in.nextDouble();
			}
			
			Arrays.sort(b1);
			Arrays.sort(b2);
			
			//System.err.println(Arrays.toString(b1));
			//System.err.println(Arrays.toString(b2));
			
			System.out.printf("Case #%d: %d %d%n", caseNum, dwar(b1,b2),war(b1,b2));
		}
	}
	
	public static int war(double[] b1, double[] b2) {
		int N = b1.length;
		int score = 0;
		boolean[] used = new boolean[N];
		for (int i = 0; i < N; i++) {
			int mini = -1;
			double min = Double.POSITIVE_INFINITY;
			int maxi = -1;
			double max = Double.POSITIVE_INFINITY;
			for (int j = 0; j < N; j++) {
				if (used[j]) continue;
				if (b2[j] < min) {
					mini = j;
					min = b2[j];
				}
				if (b2[j] > b1[i] && b2[j] < max) {
					maxi = j;
					max = b2[j];
				}
			}
			if (maxi >= 0) {
				used[maxi] = true;
			} else {
				used[mini] = true;
				score++;
			}
		}
		return score;
	}
	
	public static int dwar(double[] b1, double[] b2) {
		int N = b1.length;
		
		int l2 = 0, r2 = N-1;
		
		int count = 0;
		
		for (int i = 0; i < N; i++) {
			if (b1[i] > b2[l2]) {
				l2++;
				count++;
			} else {
				r2--;
			}
		}
		return count;
	}
}
