import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc=new Scanner(System.in);
		char[]c=sc.next().toCharArray();
		Arrays.sort(c);
		System.out.println(new String(c).equals("abc")?"Yes":"No");
	}
}