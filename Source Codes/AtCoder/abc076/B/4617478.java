import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Main main = new Main();
		main.solve();
	}

	void solve() {
		Scanner sc = new Scanner(System.in);
		int n = Integer.parseInt(sc.next());
		int k = Integer.parseInt(sc.next());
		sc.close();
		long num=1;
		for(int i=0;i<n;i++) {
			num += Math.min(num, k);
		}
		System.out.println(num);
	}

}