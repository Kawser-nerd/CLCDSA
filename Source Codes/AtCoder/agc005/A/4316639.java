import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String X = sc.next();
		sc.close();
		int l = X.length();
		int cnt = 0;
		int t = 0;
		for(int i = 0; i < l; i++) {
			char c = X.charAt(i);
			if(c == 'S') {
				t++;
			}else {
				if(t > 0) {
					t--;
					cnt += 2;
				}
			}
		}
		System.out.println(l - cnt);
	}
}