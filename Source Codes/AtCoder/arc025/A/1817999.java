import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int [] d = new int[7];
		int [] j = new int[7];
		for(int i = 0 ; i < 7 ; i++) {
			d[i] = sc.nextInt();
		}
		for(int i = 0 ; i < 7 ; i++) {
			j[i] = sc.nextInt();
		}
		int ans = 0;
		for(int i = 0 ; i < 7 ; i++) {
			if(d[i] >= j[i]) {
				ans += d[i];
			} else {
				ans += j[i];
			}
		}
		System.out.println(ans);
	}
}