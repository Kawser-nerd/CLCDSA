import java.util.Scanner;

public class Main {
	static Scanner s = new Scanner(System.in);
	public static void main(String[] args) {
		solve(s.nextInt());
	}
	static void solve(int n) {
		for(int i=0;i<(n+8)/9;i++) {
			System.out.print((n-1)%9+1);
		}
		System.out.println();
	}
}