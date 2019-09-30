import java.util.Scanner;

public class Main {


	public static void main(String[] args) {
		Main main = new Main();
		main.solve();
	}

	void solve() {
		Scanner sc = new Scanner(System.in);
		int n = Integer.parseInt(sc.next());
		sc.close();
		long num = 1;
		long mod= 1000_000_007;
		for(int i=1;i<=n;i++) {
			num = num * i % mod;
		}
		System.out.println(num);

	}

}