import java.util.*;
public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		String str1 = sc.next();
		String str2 = sc.next();
		for(int i = 0; i < str1.length(); i++){
			if(!str1.substring(i, i + 1).equals(str2.substring(2 - i, 3 - i))) {
				System.out.println("NO");
				return;
			}
		}
		System.out.println("YES");
	}
}