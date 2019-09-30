import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		int k=sc.nextInt();
		int ans=0;
		for(int i=1;i<k;i++) {
			ans+=(k-i+1)/2;
		}
		System.out.println(ans);
	}
}