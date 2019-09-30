import java.util.*;
public class Main
{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int l=sc.nextInt();
		String ar[]=new String[n];
		for(int i=0;i<n;i++)
		ar[i]=sc.next();
		Arrays.sort(ar);
		StringBuilder sb=new StringBuilder();
		for(String s:ar)
		sb.append(s);
		System.out.println(sb.toString());
	}
}