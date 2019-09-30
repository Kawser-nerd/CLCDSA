import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		long l=2000000000000l;
		long a=sc.nextLong();
		int k=sc.nextInt();
		if(k==0) {
			System.out.println(l-a);
			return;
		}
		int i;
		for(i=0;a<l;i++) {
			a+=1+k*a;
		}
		System.out.println(i);
	}
}