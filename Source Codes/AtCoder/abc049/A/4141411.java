//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		char c = sc.next().charAt(0);
		
		
		System.out.println(c=='a'||c=='o'||c=='e'||c=='u'||c=='i'?"vowel":"consonant");
	}
}