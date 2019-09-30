import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Main main = new Main();
		main.solve();
	}

	void solve() {
		Scanner sc = new Scanner(System.in);
		double n = Integer.parseInt(sc.next());
		double m = Integer.parseInt(sc.next());
		sc.close();
		if(n >= 12) n-=12;
		n*=5*6; m*=(11.0/2);
		//System.out.println(n +" "+m);
		double rad =  Math.abs(n-m);
		rad = Math.min(rad, 360-rad);

		System.out.println(rad);
	}
}