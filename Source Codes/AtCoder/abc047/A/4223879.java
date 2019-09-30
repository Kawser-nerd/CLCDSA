import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long a[] = new long[3];
		for(int i = 0; i < 3; i ++) {
			a[i] = sc.nextLong();
		}
		long max = 0;
		long sum = 0;
		for(int i = 0; i < 3; i ++) {
			max = Math.max(max, a[i]);
			sum += a[i];
		}
		System.out.println(sum == max * 2 ? "Yes" : "No");
	}
}