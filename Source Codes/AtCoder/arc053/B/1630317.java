import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		new Main().solve();
	}
	
	void solve() {
		Scanner sc=new Scanner(System.in);
		String s=sc.next();
		int[]count=new int[26];
		for(int i=0;i<s.length();i++) {
			count[s.charAt(i)-'a']++;
		}
		int divnum=0;
		for(int i=0;i<26;i++) {
			if(count[i]%2!=0) {
				divnum++;
				count[i]--;
			}
		}
		int sum=0;
		for(int i=0;i<26;i++) {
			sum+=count[i];
		}
		if(divnum==0) {
			divnum=1;
			System.out.println(2*(sum/2/divnum));
			return;
		}else{
			System.out.println(2*(sum/2/divnum)+1);
		}
	}
}