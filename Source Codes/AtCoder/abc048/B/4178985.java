//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		Long a = sc.nextLong();
		Long b = sc.nextLong();
		Long x = sc.nextLong();
		
		System.out.println(a==0?b/x+1:b/x-(a-1)/x);
		
	}
}