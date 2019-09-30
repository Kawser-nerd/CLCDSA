import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		String x=sc.next();
		int ans=x.length();
		int scnt=0;
		for(int i=0;i<x.length();i++) {
			if(x.charAt(i)=='S') {
				scnt++;
			}else {
				if(scnt!=0) {
					scnt--;
					ans-=2;
				}
			}
		}
		System.out.println(ans);
	}
}