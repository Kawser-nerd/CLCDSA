//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		String s = sc.next();
		System.out.println(
				s.charAt(0)==s.charAt(1)&&s.charAt(1)==s.charAt(2)||s.charAt(1)==s.charAt(2)&&s.charAt(2)==s.charAt(3)?"Yes":"No");
	}
	
}