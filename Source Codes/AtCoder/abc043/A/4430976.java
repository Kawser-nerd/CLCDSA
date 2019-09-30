import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
      	Main main = new Main();
		main.solve();
	}

	void solve() {
		Scanner sc = new Scanner(System.in);
		int n = Integer.parseInt(sc.next());
		long res = 0;
		for(int i=1;i<=n;i++)res += i;
		System.out.println(res);
		sc.close();
	}
}