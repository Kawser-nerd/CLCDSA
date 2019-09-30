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
		int k = Integer.parseInt(sc.next());
		sc.close();

		for(int i=a;i<=a+k-1&&i<=b;i++) {
			System.out.println(i);
			if(i==a+k-1||i==b) {
				i++;
				for(int j=Math.max(i,b-k+1);j<=b;j++)System.out.println(j);
			}
		}
	}
}