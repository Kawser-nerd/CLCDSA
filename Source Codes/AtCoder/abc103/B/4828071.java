import java.util.*;
import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		String s=sc.next();
		String t=sc.next();
		List<Character>l=new ArrayList<>();
		for(int i=0;i<t.length();i++) {
			l.add(t.charAt(i));
		}
		boolean flg;
		for(int i=0;i<s.length();i++) {
			flg=true;
			for(int j=0;j<s.length();j++) {
				if(s.charAt(j)!=l.get(j)) {
					flg=false;
					break;
				}
			}
			if(flg) {
				System.out.println("Yes");
				return;
			}
			l.add(l.get(0));
			l.remove(0);
		}
		System.out.println("No");
	}
}