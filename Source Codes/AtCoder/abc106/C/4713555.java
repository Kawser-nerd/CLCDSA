import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		String s = sc.next();
		long k = Long.parseLong(sc.next());
		
		for(int i = 0; i < k; i++) {
			if(s.charAt(i) >= '2') {
				System.out.println(s.charAt(i));
				return;
			}
		}
		System.out.println(1);
		
	}
}