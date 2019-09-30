import java.util.Arrays;
import java.util.Scanner;

public class Main{
	
	static Scanner s=new Scanner(System.in);
	
	public static void main(String[] __){
		int[] from,to;
		{
			String buf=s.next();
			from=new int[buf.length()+1];
			for(int i=0;i<buf.length();i++)
				from[i+1]=buf.charAt(i)=='A'?1:2;
			buf=s.next();
			to=new int[buf.length()+1];
			for(int i=0;i<buf.length();i++)
				to[i+1]=buf.charAt(i)=='A'?1:2;
			
			Arrays.parallelPrefix(from,(a,b)->a+b);
			Arrays.parallelPrefix(  to,(a,b)->a+b);
		}
		
		for(int q=s.nextInt();q>0;q--) {
			int f=-from[s.nextInt()-1]+from[s.nextInt()],
				t=-  to[s.nextInt()-1]+  to[s.nextInt()];
			System.out.println(f%3==t%3?"YES":"NO");
		}
	}
}