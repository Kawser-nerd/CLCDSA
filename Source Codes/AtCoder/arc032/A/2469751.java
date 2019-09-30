import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = Integer.parseInt(sc.next());
		int upper = 1000000;
		int a[] = new int[upper+1];
		for (int i = 2; i <= upper; i++) {
			a[i] = i;
		}
		for (int i = 2; i <= Math.sqrt(upper); i++) {
			for (int j = i + i; j <= upper; j += i) {
				a[j] = 0;
			}
		}
		int sum = 0;
		for (int i = 1; i <= n; i++)
			sum += i;
		if (a[sum] == 0)
			System.out.println("BOWWOW");
		else
			System.out.println("WANWAN");
	}
}