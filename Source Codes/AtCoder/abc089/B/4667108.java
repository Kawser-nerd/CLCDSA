import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		String[] s = new String[N];
		for(int i = 0; i < N; i++) {
			s[i] = sc.next();
		}
		
		boolean f = false;
		for(int i = 0; i < s.length; i++) {
			if(s[i].equals("Y")) f = true;
		}
		
		if(f) {
			System.out.println("Four");
		} else {
			System.out.println("Three");
		}
		
		sc.close();

	}

}