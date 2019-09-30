import static java.lang.System.*;
import java.util.*;
 
public class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		int a=sc.nextInt(), b=sc.nextInt(), x=sc.nextInt();
		
		if (x < a) out.println("NO");
		else {
			out.println(x-a<=b?"YES":"NO");
		}
	}
}