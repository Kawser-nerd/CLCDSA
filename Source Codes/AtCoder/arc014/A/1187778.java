import java.util.*;
public class Main {
	static Scanner s = new Scanner(System.in);

	static int n,min,max,a[];
	public static void main(String __[]){
		input();
		solve(s.nextInt());
	}
	private static void input() {
	}
	private static void solve(int a){
		System.out.println(a%2==1?"Red":"Blue");
	}
}