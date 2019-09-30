import java.util.Arrays;
import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] a = new int[3];
		for (int i = 0; i < 3; i++)
			a[i] = Integer.parseInt(sc.next());
		int c = 0;
		while (true) {
			Arrays.sort(a);
			if (a[0] == a[1] && a[1] == a[2])
				break;
			else if (a[1] == a[2])
				a[0] += 2;
			else {
				a[0]++;
				a[1]++;
			}
			c++;
		}
		System.out.println(c);
	}
}