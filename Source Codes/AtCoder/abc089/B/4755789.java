import java.util.*;
import static java.lang.System.*;
 
public class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		boolean P = false;
		boolean W = false;
		boolean G = false;
		boolean Y = false;
		int n = sc.nextInt();
		String s;
		for (int i=0; i<n; i++) {
			s = sc.next();
			if (s.equals("P")) {P=true;}
			else if (s.equals("W")) {W=true;}
			else if (s.equals("G")) {G=true;}
			else {Y=true;}
		}
		int count = 0;
		if (P==true) {count++;}
		if (W==true) {count++;}
		if (G==true) {count++;}
		if (Y==true) {count++;}
		out.println(count==4?"Four":"Three");
	}
}