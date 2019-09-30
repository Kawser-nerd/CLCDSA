import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String a = sc.next();
		String b = sc.next();
		int c = Integer.parseInt(a + b);
		
		for(int i = 1 ; i * i < 100100 ; i++) {
			if(c == i * i) {
				System.out.println("Yes");
				return;
			}
		}
		
		System.out.println("No");
	}

}