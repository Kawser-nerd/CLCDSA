import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in); 
		int n = sc.nextInt();
		boolean flg = true;
		String[] s = new String[n];
		for(int i = 0;i < n;i++) {
			String S = sc.next();
			if(Arrays.asList(s).contains(S)) flg = false;
			s[i] = S;
		}
		for(int i = 1;i < n;i++) {
			if(!(s[i-1].substring(s[i-1].length()-1).equals(s[i].substring(0,1)))) flg = false;
		}
		System.out.println(flg ? "Yes" : "No");
        sc.close();
	}
}