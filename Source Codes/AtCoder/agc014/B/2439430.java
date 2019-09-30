import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();

		boolean[] odd = new boolean[n];

		for (int i=0;i<2*m;i++) {
			int x = sc.nextInt();
			odd[x-1] = !odd[x-1];
		}

		boolean ng = false;
		for (int i=0;i<n;i++) {
			ng |= odd[i];
		}

		System.out.println(ng? "NO" : "YES");

	}

}