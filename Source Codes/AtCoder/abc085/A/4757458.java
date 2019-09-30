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
		S = S.replace("2017","2018");
		System.out.println(S);
	}

}