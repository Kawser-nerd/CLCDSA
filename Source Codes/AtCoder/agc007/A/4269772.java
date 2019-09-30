import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		int h = sc.nextInt(); int w = sc.nextInt();
		int ans = 0;
		for (int i=0; i<h; i++) {
			ans += sc.next().replace(".","").length();
		}
		System.out.println(ans==h+w-1?"Possible":"Impossible");
		
	}
}