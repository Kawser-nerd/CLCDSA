import java.util.*;
import java.lang.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int[] s = new int[n];
		for (int i = 0; i < n; i++) {
			s[i] = sc.nextInt();
		}
		long seki = 1;
		int max = 0;
		int len = 0;
		int start = 0;
		for (int i = 0; i < n; i++) {
			seki *= s[i];
			if (seki == 0) {
				max = n;
				break;
			}
			len++;
			if (seki > k) {
				max = Math.max(max, len - 1);
				while (seki > k && len > 0) {
					seki /= s[start];
					start++;
					len--;
				}
			}
		}
		max = Math.max(max, len);
		System.out.println(max);
	}
}