import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		int n = s.length();
		int min = n;
		for (int i=0;i<n-1;i++) {
			if(s.charAt(i) != s.charAt(i+1)) {
				min = Math.min(min, Math.max(i+1, n-i-1));
			}
		}
		System.out.println(min);
	}

}