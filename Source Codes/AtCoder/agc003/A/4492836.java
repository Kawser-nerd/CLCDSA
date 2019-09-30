import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		sc.close();
		int n = 0;
		int w = 0;
		int s = 0;
		int e = 0;
		for(int i = 0; i < S.length(); i++) {
			char c = S.charAt(i);
			if(c == 'N') {
				n++;
			}else if(c == 'S') {
				s++;
			}else if(c == 'E') {
				e++;
			}else {
				w++;
			}
		}
		if((n == 0 && s != 0) || (n != 0 && s == 0)) {
			System.out.println("No");
		}else if((e == 0 && w != 0) || (e != 0 && w == 0)) {
			System.out.println("No");
		}else {
			System.out.println("Yes");
		}
	}
}