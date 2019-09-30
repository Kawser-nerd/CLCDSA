import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		long a=sc.nextLong();
		long b=sc.nextLong();
		long k=sc.nextLong();
		long l=sc.nextLong();
		long ans=k/l*b;
		k-=k/l*l;
		System.out.println(ans+(k==0?0:Math.min(k*a,b)));
	}
}