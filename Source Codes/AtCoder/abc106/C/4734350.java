import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		long K = sc.nextLong();
		String[] s = S.split("");
		String ans = "1";
		if(K <= 100) {
			for(int i = 0; i < K; i++) {
				if(!s[i].equals("1")) {
					ans = s[i];
					break;
				}
			}
		}
		else {
			for(int i = 0; i < s.length; i++) {
				if(!s[i].equals("1")) {
					ans = s[i];
					break;
				}
			}
		}
		System.out.println(ans);
	}

}