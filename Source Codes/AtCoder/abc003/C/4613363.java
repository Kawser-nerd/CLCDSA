import java.util.Scanner;
import java.util.Arrays;
import java.util.Comparator;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner (System.in);
		int n = sc.nextInt(), k = sc.nextInt();
		Integer r[] = new Integer[n];
		for(int i = 0; i < n; ++i) r[i] = sc.nextInt();
		sc.close();
		double ans = 0;
		Arrays.sort(r, Comparator.reverseOrder());
		for(int i = 0; i < k; ++i) {
			double tmp = (double)r[i] / Math.pow(2, i + 1);
			ans += tmp;
		}
		System.out.println(ans);
	}

}