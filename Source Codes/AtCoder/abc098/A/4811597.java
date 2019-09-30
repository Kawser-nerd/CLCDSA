import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		int a=sc.nextInt();
		int b=sc.nextInt();
		int pm=Math.max(a+b,a-b);
		System.out.println(Math.max(pm, a*b));
	}
}