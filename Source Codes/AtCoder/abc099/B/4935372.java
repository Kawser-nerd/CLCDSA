import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc=new Scanner(System.in);
		int a=sc.nextInt();
		int b=sc.nextInt();
		int c=rec(b-a);
		System.out.println(c-b);
	}
	static int rec(int i) {
		return(i==1?1:i+rec(i-1));
	}
}