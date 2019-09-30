package round1a;

import java.util.Scanner;

public class A {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int cases = sc.nextInt();
		for (int caze = 1; caze <= cases; caze++) {
			int N = sc.nextInt();
			int[] cant = new int[N];
			for (int i = 0; i < cant.length; i++) {
				cant[i] = sc.nextInt();
			}
			int first = 0, second = 0, max = 0;
			for (int i = 1; i < N; i++) {
				if (cant[i - 1] > cant[i]) {
					int dif = cant[i - 1] - cant[i];
					first += dif;
					max = Math.max(max, dif);
				}
			}
			for (int i = 1; i < N; i++) {
				second += Math.min(max, cant[i-1]);
			}

			System.out.println("Case #" + caze + ": " + first + " " + second);
		}
	}

}
