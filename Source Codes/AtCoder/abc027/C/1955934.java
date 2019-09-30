import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		boolean win = false;
		long now = n+1;//????????
		while(now!=1) {
			now = now / 2 + now % 2;
			win = false;
			if(now==1) {
				break;
			}
			now = (now-1)/2 + (now+1)%2;
			win = true;
		}
		System.out.println(win ? "Takahashi" : "Aoki");
	}
}