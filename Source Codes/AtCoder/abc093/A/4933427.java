import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc=new Scanner(System.in);
		String s=sc.next();
		char c0=s.charAt(0);
		char c1=s.charAt(1);
		char c2=s.charAt(2);
		System.out.println(c0==c1||c1==c2||c2==c0?"No":"Yes");
	}
}