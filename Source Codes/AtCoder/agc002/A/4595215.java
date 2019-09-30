import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		long a=sc.nextLong();
		long b=sc.nextLong();
		if(a==0||b==0) {
			System.out.println("zero");
			return;
		}
		if(a>0) {
			System.out.println("Positive");
			return;
		}
		if(b>0) {
			System.out.println("Zero");
			return;
		}
		if((b-a)%2==0) {
			System.out.println("Negative");
		}else {
			System.out.println("Positive");
		}
	}
}