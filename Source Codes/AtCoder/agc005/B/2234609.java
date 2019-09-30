import java.util.Scanner;
import java.util.TreeSet;

public class Main {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] arr = new int[n];
		int[] rev = new int[n+1];
		for(int i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
			rev[arr[i]] = i;
		}
		long count = 0;

		TreeSet<Integer> sorted = new TreeSet<>();
		sorted.add(-1);
		sorted.add(n);

		for(int i = 1; i <= n; i++) {
			int l = sorted.lower(rev[i]);
			int r = sorted.higher(rev[i]);
			count += (long)i*(rev[i] - l)*(r - rev[i]);
			sorted.add(rev[i]);
		}
		System.out.println(count);
	}
}