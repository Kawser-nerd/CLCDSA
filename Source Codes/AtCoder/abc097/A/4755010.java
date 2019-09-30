import java.util.*;

public class Main{
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int a = Integer.parseInt(sc.next());
		int b = Integer.parseInt(sc.next());
		int c = Integer.parseInt(sc.next());
		int d = Integer.parseInt(sc.next());
		if(Math.abs(a-b)<=d&&Math.abs(b-c)<=d) {
			System.out.println("Yes");
		}else if(Math.abs(c-a)<=d) {
			System.out.println("Yes");
		}else {
			System.out.println("No");
		}

	}
}