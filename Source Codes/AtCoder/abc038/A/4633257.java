import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Main main = new Main();
		main.solve();
	}

	void solve() {
		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		sc.close();
		if(S.substring(S.length()-1,S.length()).equals("T")) {
			System.out.println("YES");
		}else {
			System.out.println("NO");
		}
	}
}