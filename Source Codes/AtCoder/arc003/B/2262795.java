import java.util.*;

public class Main{
	private static Scanner sc=new Scanner(System.in);
	
	public static void main(String[] args){
		int n=readInt();
		String[] s=new String[n];
		for(int i=0;i<n;i++){
			String x=sc.next();
			s[i]=new StringBuffer(x).reverse().toString();
		}
		Arrays.sort(s);
		for(int i=0;i<n;i++){
			s[i]=new StringBuffer(s[i]).reverse().toString();
			System.out.println(s[i]);
		}
	}
	
	private static int readInt(){
		return Integer.parseInt(sc.next());
	}
}