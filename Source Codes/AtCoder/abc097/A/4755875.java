import static java.lang.System.*;
import java.util.*;
 
public class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		int a=sc.nextInt(), b=sc.nextInt(), c=sc.nextInt(), d=sc.nextInt();
		int difAB = (int)Math.abs(a-b);
		int difBC = (int)Math.abs(b-c);
		int difAC = (int)Math.abs(a-c);
		if (difAB<=d && difBC<=d) {
			out.println("Yes");
		}
		else if (difAC <= d) out.println("Yes");
		else out.println("No");
	}
}