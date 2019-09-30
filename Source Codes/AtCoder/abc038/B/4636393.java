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

		if(h1==h2||h1==w2||w1==h2||w1==w2) {
			System.out.println("YES");
		}else {
			System.out.println("NO");
		}
	}

}