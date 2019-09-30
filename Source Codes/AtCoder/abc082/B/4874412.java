import java.util.Arrays;
import java.util.Scanner;
public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		String s = sc.next();

		String t = sc.next();

		char[] ss = new char[s.length()];

		char[] tt = new char[t.length()];

		for(int i=0;i<s.length();i++) {

			ss[i]= s.charAt(i);
		}

		for(int i=0;i<t.length();i++) {

			tt[i]= t.charAt(i);
		}

		Arrays.sort(ss);

		Arrays.sort(tt);

		boolean ans = false;

		boolean flag = false;

		int len = Math.min(s.length(), t.length());

		for(int i=0;i<len;i++) {

			if(ss[i]<tt[tt.length-1-i]) {

				ans = true;

				break;
			}

			if(ss[i]!=tt[tt.length-1-i]) flag = true;

			if(i==len-1 && ss.length>tt.length) ans = false;
		}

		if(!flag && ss.length<tt.length) ans = true;

		if(s.equals(t)) ans = false;

		if(ans)System.out.println("Yes");

		else System.out.println("No");
	}

}