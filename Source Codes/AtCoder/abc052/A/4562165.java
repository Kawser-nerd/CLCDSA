import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Main main = new Main();
		main.solve();
	}

	void solve() {
		Scanner sc = new Scanner(System.in);
		int h1 = Integer.parseInt(sc.next());
		int w1 = Integer.parseInt(sc.next());
		int h2 = Integer.parseInt(sc.next());
		int w2 = Integer.parseInt(sc.next());
		sc.close();

		long n1 = h1*w1, n2=h2*w2;

		System.out.println(n1>n2?n1:n2);
	}

}