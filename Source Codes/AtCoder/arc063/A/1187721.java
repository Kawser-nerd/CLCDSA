import java.util.*;
public class Main {
	static Scanner s = new Scanner(System.in);
	public static void main(String __[]){
		solve(s.next());
	}
	private static final void solve(String s) {
		int count=0;
		for(int i=1;i<s.length();i++)
			if(s.charAt(i)!=s.charAt(i-1))
				count++;
		System.out.println(count);
	}
}