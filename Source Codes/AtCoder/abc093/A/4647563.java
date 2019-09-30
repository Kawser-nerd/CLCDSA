import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Main main = new Main();
		main.solve();
	}

	void solve() {
		Scanner sc = new Scanner(System.in);
		char[] C = sc.next().toCharArray();
		sc.close();

		if(C[0]!=C[1]&&C[0]!=C[2]&&C[1]!=C[2])System.out.println("Yes");
		else System.out.println("No");
	}
}