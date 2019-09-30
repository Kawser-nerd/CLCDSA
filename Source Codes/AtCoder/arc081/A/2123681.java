import java.math.BigInteger;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = Integer.parseInt(sc.next());
		Long[] a = new Long[n];
		for (int i = 0; i < n; i++)
			a[i] = Long.parseLong(sc.next());
		Arrays.sort(a, Comparator.reverseOrder());
		long edge1 = 0, edge2 = 0;
		int index = 0;
		for (int i = 1; i < n; i++) {
			if (a[i].equals(a[i - 1])) {
				if (edge1 == 0) {
					edge1 = a[i];
					index = i;
				}
				else if (edge2 == 0 && index != i - 1) {
					edge2 = a[i];
					break;
				}
			}
		}
		BigInteger ans = new BigInteger(Long.toString(edge1)).multiply(new BigInteger(Long.toString(edge2)));
		System.out.println(ans);
	}
}