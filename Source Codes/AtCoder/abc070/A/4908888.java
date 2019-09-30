import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc=new Scanner(System.in);
		String n=sc.next();
		for(int i=0;i<n.length()/2;i++) {
			if(n.charAt(i)!=n.charAt(n.length()-i-1)) {
				System.out.println("No");
				return;
			}
		}
		System.out.println("Yes");
	}
}