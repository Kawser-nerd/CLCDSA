import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		s = s.toLowerCase();
		int n = s.length();
		for(int i  = 0 ; i < n ; i++) {
			for(int j = i + 1 ; j < n ; j++) {
				for(int k = j + 1 ; k < n ; k++) {
					if(s.charAt(i) == 'i' && s.charAt(j) == 'c' && s.charAt(k) == 't') {
						System.out.println("YES");
						return;
					}
				}
			}
		}
		System.out.println("NO");
	}
}