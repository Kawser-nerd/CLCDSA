import java.io.PrintWriter;
import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		//String S = sc.next();
		//int N = Integer.parseInt(sc.next());
		//out.println();
		int N = Integer.parseInt(sc.next());
		String S = sc.next();
		int[] cntnum = new int[N];
		int cnt = 0;
		for(int i=1;i<S.length();i++){
			int ans =0;
			String s1 = S.substring(0,i);
			String s2 = S.substring(i,N);
			for(char c='a';c<='z';c++){
				String d =String.valueOf(c);
				if(s1.indexOf(d)!=-1 && s2.indexOf(d)!=-1){
					ans++;
				}
			}
			if(cnt<ans){
				cnt = ans;
			}
		}
		out.print(cnt);
		out.flush();	
	}
}