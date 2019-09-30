import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int L = sc.nextInt();
		String S = sc.next();
		int cnt = 1;
		int clash = 0;
		for(int i = 0 ; i < N ; i++) {
			if(S.charAt(i) == '+') {
				cnt++;
				if(cnt > L) {
					clash++;
					cnt = 1;
				}
			} else if(S.charAt(i) == '-') {
				cnt--;
				if(cnt == 0) {
					cnt = 1;
				}
			}
		}
		System.out.println(clash);
	}
}