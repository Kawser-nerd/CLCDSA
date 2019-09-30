import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int x = sc.nextInt();
		int[] m = new int[n];
		int min = 1001;
		int sum = 0;
		int c = 0;
		for (int i = 0; i < n; i++) {
			m[i] = sc.nextInt();
			if (min > m[i]) {
				min = m[i];
			}
			sum += m[i];
		}
		int sa = x - sum;
		c = n;
		int kosu = sa / min;
		c += kosu;
		System.out.println(c);
	}

}