import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String N = sc.next();
		int X = Integer.parseInt(N);
		String[] s = N.split("");
		int har = 0;
		for(int i = 0; i < s.length; i++) {
			har += Integer.parseInt(s[i]);
		}
		if(X % har == 0) {
			System.out.println("Yes");
		}else {
			System.out.println("No");
		}
	}

}