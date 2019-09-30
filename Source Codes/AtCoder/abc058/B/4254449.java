import java.util.Scanner;
 
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		String a = sc.next();
		String b = sc.next();
		
		for (int i = 0; i < a.length(); i++) {
			System.out.print(a.charAt(i));
			try {
				System.out.print(b.charAt(i));
			} catch (Exception ex) {
				
			}
		}
		
		System.out.println();
	}
	
}