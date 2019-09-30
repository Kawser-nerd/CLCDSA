import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	
	public static void main(String[] args) {
		new A().solve();
	}

	Scanner sc;

	private void solve() {
		try {
			sc = new Scanner(new File("a.in"));
		} catch (FileNotFoundException e) {
			throw new AssertionError(e);
		}
		
		int N = sc.nextInt();
		for (int n = 0; n < N; n++) {
			System.out.print("Case #" + (n + 1) + ": ");
			solveTest();
		}
	}

	private void solveTest() {
		int p = sc.nextInt();
		int k = sc.nextInt();
		int l = sc.nextInt();
		
		int[] a = new int[l];
		for (int i = 0; i < a.length; i++) {
			a[i] = sc.nextInt();
		}
		Arrays.sort(a);
		
		long ans = 0;
		for (int j = 0; j < a.length; j++) {
			int i = a.length - j - 1;
			ans += (a[i] * ((j / k) + 1));
		}
		
		System.out.println(ans);
	}

}
