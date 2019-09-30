import java.util.*;

public class Main {
	public static void main (String[] args) {
		int[] POINTS = new int[]{4, 3, 2, 1, 0, 0};
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		char[] arr = sc.next().toCharArray();
		int sum = 0;
		for (char c : arr) {
			sum += POINTS[c - 'A'];
		}
		System.out.println((double)sum / (double)n);
	}
}