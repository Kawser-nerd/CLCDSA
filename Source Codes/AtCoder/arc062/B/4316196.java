import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		sc.close();
		int N = s.length();
		int p = 0;
		int g = 0;
		int t = 0;
		for(int i = 0; i < N; i++) {
			char c = s.charAt(i);
			if(c == 'g') {
				if(p < g) {
					p++;
					t++;
				}else {
					g++;
				}
			}else {
				if(p < g) {
					p++;
				}else {
					g++;
					t--;
				}
			}
		}
		System.out.println(t);
	}
}