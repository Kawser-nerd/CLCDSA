import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Main main = new Main();
		main.solve();
	}

	void solve() {
		Scanner sc = new Scanner(System.in);
		for(int i=0;i<3;i++) {
			String S  = sc.next();
			System.out.print(S.substring(i, i+1));
		}
		System.out.println();
		sc.close();
	}

}