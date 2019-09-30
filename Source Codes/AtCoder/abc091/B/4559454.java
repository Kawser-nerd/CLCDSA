import java.io.PrintWriter;
import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int N = Integer.parseInt(sc.next());
		String s[] = new String[N];
		for(int i=0;i<N;i++){
			s[i] = sc.next();
		}
		int M = Integer.parseInt(sc.next());
		String t[] = new String[M];
		for(int i=0;i<M;i++){
			t[i] = sc.next();
		}
		int ans = 0;
		for(int i=0;i<N;i++){
			int cnt = 0;
			for(int j=0;j<N;j++){
				if(s[i].equals(s[j])){
					cnt++;
				}
			}
			for(int j=0;j<M;j++){
				if(s[i].equals(t[j])){
					cnt--;
				}
			}
			if(cnt>0 && cnt> ans){
				ans = cnt;
			}
		}
		out.println(ans);
		out.flush();	
	}
}