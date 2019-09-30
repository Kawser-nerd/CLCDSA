import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		char x=sc.next().charAt(0);
		char y=sc.next().charAt(0);
		if(x<y) {
			System.out.println("<");
		}else if(x>y) {
			System.out.println(">");
		}else {
			System.out.println("=");
		}
	}
}