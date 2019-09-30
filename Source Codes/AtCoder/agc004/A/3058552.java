import java.util.Scanner;

public class Main{
	public static void main(String args[])throws Exception{

		Scanner sc = new Scanner(System.in);
		long a = sc.nextLong();
		long b = sc.nextLong();
		long c = sc.nextLong();
		
		if(a%2 == 1 && b%2 == 1 && c%2 == 1) {
			if(a < b) {
				if(b < c) {
					System.out.println(a*b);
				}else {
					System.out.println(a*c);
				}
			}else {
				if(a < c) {
					System.out.println(a*b);
				}else {
					System.out.println(b*c);
				}
			}
			
		}else {
			System.out.println(0);
		}	
	}
}