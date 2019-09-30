package round1c;

import java.util.Locale;
import java.util.Scanner;

public class B {
	public static void main(String[] args) {
		Locale.setDefault(Locale.ENGLISH);
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i=0;i<t;i++) {
			double d = sc.nextDouble();
			int n = sc.nextInt();
			int a = sc.nextInt();
			double times [] = new double[n];
			double positions[] = new double[n];
			                             
			
			for (int j =0;j<n;j++) {
				times[j] = sc.nextDouble();
				positions[j] = sc.nextDouble();
			}
			
			System.out.println("Case #" + (i + 1) + ":" );
			
			for (int j=0;j<a;j++) {
				double acc = sc.nextDouble();
				double otherTime = n == 1 ? 0 : (d - positions[0]) / (positions[1] - positions[0]) * (times[1] - times[0]) + times[0];
				double myTime = Math.sqrt(d * 2 / acc);
				System.out.println("" + Math.max(otherTime, myTime));
			}
		}
	}
}
