import java.util.*;
public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		String s = sc.next();
		boolean flag = true;
		for(int i=0 ; i<a+b ; i++) {
			if(i == a) {
				flag &= s.charAt(i) == '-';
			}else {
				flag &= Character.isDigit(s.charAt(i));
			}
		}
		System.out.println(flag ? "Yes":"No");
		
	}
}