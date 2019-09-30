import java.util.*;
import java.util.stream.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		int left = 0;
		long sum = 0, xor = 0;
		for (int right = 0; right < n; right++) {
			while((xor ^ a[right]) != (xor + a[right])) {
				xor ^= a[left++];
			}
			xor ^= a[right];
			sum += right - left + 1;
		}
		System.out.println(sum);
	}
}