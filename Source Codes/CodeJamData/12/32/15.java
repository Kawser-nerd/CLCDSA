
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;

public class ProblemB {
	public static void main(String[] args) throws FileNotFoundException {
//		Scanner sc = new Scanner(new File("B-practice.in"));
		 Scanner sc = new Scanner(new File("B-small-attempt0.in"));
		// Scanner sc = new Scanner(new File("B-large.in"));
		sc.useLocale(Locale.US);
		int cases = sc.nextInt();

		for (int i = 1; i <= cases; i++) {
			double D = sc.nextDouble();
			int N = sc.nextInt();
			int A = sc.nextInt();

			double[][] car = new double[N][2];

			for (int j = 0; j < car.length; j++) {
				car[j][0] = sc.nextDouble();
				car[j][1] = sc.nextDouble();
			}

			double[] a = new double[A];

			for (int j = 0; j < a.length; j++) {
				a[j] = sc.nextDouble();
			}

			double[] times = new double[A];

			for (int j = 0; j < a.length; j++) {
				double max = 0;
				for (int k = 0; k < car.length; k++) {
					double time = car[k][0];
					double pos = car[k][1];
					if (pos >= D) {
						if (k == 0) {
							break;
						}
						double endPos = D;
						double endTime = (car[k][0]-car[k-1][0])/(car[k][1]-car[k-1][1])*(D-car[k-1][1]);
						double myTime = Math.sqrt(2 * endPos / a[j]);
						if (endTime - myTime > max) {
							max = endTime - myTime;
						}
						break;
					}
					double myTime = Math.sqrt(2 * pos / a[j]);
					if (time - myTime > max) {
						max = time - myTime;
					}
					
				}
				times[j] = max;
				times[j] += Math.sqrt(2 * D / a[j]);
			}

			// do case things here
			System.out.format(Locale.US, "Case #%d: \n", i);
			for (int j = 0; j < times.length; j++) {
				System.out.println(times[j]);
			}
		}
	}
}