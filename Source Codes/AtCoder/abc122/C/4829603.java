import java.util.*;
import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		int q=sc.nextInt();
		String s=sc.next();
		int[]ac=new int[s.length()];
		int cnt=0;
		ac[0]=0;
		for(int i=1;i<s.length();i++) {
			if(s.charAt(i-1)=='A'&&s.charAt(i)=='C') {
				cnt++;
			}
			ac[i]=cnt;
		}
		for(int i=0;i<q;i++) {
			int l=sc.nextInt();
			int r=sc.nextInt();
			System.out.println(ac[r-1]-ac[l-1]);
		}
	}
}