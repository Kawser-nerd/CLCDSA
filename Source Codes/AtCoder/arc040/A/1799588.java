import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String[] s = new String[n];
		for(int i = 0 ; i < n ; i++) {
			s[i] = sc.next();
		}
		int cnt1 = 0;
		int cnt2 = 0;
		for(int i = 0 ; i < n ; i++) {
			for(int j = 0 ; j < n ; j++) {
				if(s[i].charAt(j) == 'R') {
					cnt1++;
				} else if(s[i].charAt(j) == 'B') {
					cnt2++;
				}
			}
		}
		if(cnt1 > cnt2) {
			System.out.println("TAKAHASHI");
		} else if(cnt1 < cnt2) {
			System.out.println("AOKI");
		} else {
			System.out.println("DRAW");
		}
	}
}