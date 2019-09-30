import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		double n = sc.nextDouble();
		double a = sc.nextDouble();
		double b = sc.nextDouble();
		long[] arr = new long[(int) n];
		long max = Long.MIN_VALUE;
		long min = Long.MAX_VALUE;
		double ave = 0;
		for (int i = 0; i < n; i++) {
			arr[i] = sc.nextLong();
			if(arr[i] > max) {
				max = arr[i];
			}
			if(arr[i] < min) {
				min = arr[i];
			}
			ave += (double)arr[i] / n;
		}
		long sa = max - min;
		double p = (double)b / sa;
		double q = (double)a - (double)ave*p;
		if(Double.isInfinite(p) || Double.isInfinite(q)) {
			System.out.println(-1);
			return;
		}
		System.out.println(p+" "+q);
	}
}