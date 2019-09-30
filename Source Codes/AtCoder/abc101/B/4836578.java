import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		String str=String.valueOf(n);
		int sum=0;
		for(int i=0;i<str.length();i++) {
			sum+=Character.getNumericValue(str.charAt(i));
		}
		System.out.println(n%sum==0?"Yes":"No");
	}
}