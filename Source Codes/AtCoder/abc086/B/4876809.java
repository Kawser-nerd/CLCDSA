import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		String a=sc.next();
		String b=sc.next();
		System.out.println(Math.sqrt(Integer.parseInt(a+b))%1==0?"Yes":"No");
	}
}