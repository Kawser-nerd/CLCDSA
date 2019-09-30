import java.util.Scanner;
public class Main{
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		String s=sc.nextLine();
		char c=s.charAt(0);
		for(int i=1;i<4;i++) {
			if(s.charAt(i)!=c) {
				System.out.println("DIFFERENT");
				return;
			}
		}
		System.out.println("SAME");
	}
}