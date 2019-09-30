import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		String o=sc.nextLine();
		String e=sc.nextLine();
		for(int i=0;;i++) {
			if(i<o.length()) {
				System.out.print(o.charAt(i));
			}else {
				break;
			}
			if(i<e.length())
				System.out.print(e.charAt(i));
		}
	}
}