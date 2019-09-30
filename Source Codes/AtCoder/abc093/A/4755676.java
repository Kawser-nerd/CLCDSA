import static java.lang.System.*;
import java.util.*;
 
public class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		String s = sc.next();
		boolean a=false,b=false,c=false;
		if (s.contains("a")) a = true;
		if (s.contains("b")) b = true;
		if (s.contains("c")) c = true;
		
		if (a && b && c) out.println("Yes");
		else out.println("No");
	}
}