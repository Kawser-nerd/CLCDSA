import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N, b, c = 0, d = 0;
		N = sc.nextInt();
		Integer[] a = new Integer[N];
		for (int i = 0; i < N; i++) {
			b = sc.nextInt();
			a[i] = b;
		}
		Arrays.sort(a, Collections.reverseOrder());
		for (int i = 0; i < N; i++) {
			c += a[i];
			i++;
			if(i<N) {
			d += a[i];
			}
		}
		System.out.println(c - d);
		sc.close();
	}

}