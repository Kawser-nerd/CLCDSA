import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] x = new int[n];
		int[] y = new int[n];
		for(int i = 0; i < n; i++) {
			x[i] = sc.nextInt();
			y[i] = sc.nextInt();
		}

		for(int i = 0; i < n; i++) {
			double[] angle = new double[n];
			int p = 0;
			for(int j = 0; j < n; j++) {
				if(j != i) {
					angle[p++] = Math.atan2(y[j] - y[i], x[j] - x[i]);
				}
			}
			Arrays.sort(angle, 0, p);
			angle[p++] = angle[0] + 2 * Math.PI;
			double max = 0;
			for(int j = 0; j + 1 < angle.length; j++) {
				max = Math.max(max, angle[j+1] - angle[j]);
			}
			max = Math.max(max - Math.PI, 0.0);
			System.out.printf("%.15f\n", max / (2 * Math.PI));
		}
	}
}