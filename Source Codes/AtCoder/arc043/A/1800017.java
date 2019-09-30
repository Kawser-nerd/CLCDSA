import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int a = sc.nextInt();
		int b = sc.nextInt();
		long[] s = new long[n];
		for(int i = 0 ; i < n ; i++) s[i] = sc.nextLong();
		Arrays.sort(s);
		long dis = s[n - 1] - s[0];
		long sum = 0;
		for(int i = 0 ; i < n ; i++) sum += s[i];
		double avg = 1.0 * sum / n;
		if(dis == 0) {
			System.out.println(-1);
			return;
		}
		double p = 1.0 * b / dis;
		double q = 1.0 * a - 1.0 * b * avg / dis;
		System.out.printf("%.10f", p);
		System.out.print(" ");
		System.out.printf("%.10f\n", q);
	}
}