import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Main main = new Main();
		main.solve();
	}

	void solve() {
		Scanner sc = new Scanner(System.in);
		int a = Integer.parseInt(sc.next());
		int b = Integer.parseInt(sc.next());
		int c = Integer.parseInt(sc.next());
		int d = Integer.parseInt(sc.next());
		sc.close();

		double PlayerA = (double)b/a;
		double PlayerB = (double)d/c;
		if(PlayerA>PlayerB) System.out.println("TAKAHASHI");
		else if (PlayerA<PlayerB) System.out.println("AOKI");
		else System.out.println("DRAW");
	}
}