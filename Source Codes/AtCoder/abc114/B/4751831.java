import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		int a = 0;
		int min = 753;
		
		for(int i = 0 ; i < s.length() - 2; i++) {
			a = Math.abs(753 - Integer.parseInt(s.substring(i , i + 3)));
			if(a < min) {
				min = a;
			}
		}
		
		System.out.println(min);
	}

}