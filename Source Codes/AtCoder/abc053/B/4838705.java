import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		String s=sc.next();
		int i=0,j=s.length()-1;
		for(;i<s.length()&&s.charAt(i)!='A';i++);
		for(;j>=0&&s.charAt(j)!='Z';j--);
		System.out.println(j-i+1);
	}
}