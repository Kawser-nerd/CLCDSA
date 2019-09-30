import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		int i;
		for(i=0;i*i<=n;i++);
		i--;
		System.out.println(i*i);
	}
}