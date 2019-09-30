import java.util.Scanner;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		String s=sc.nextLine();
		s=sc.nextLine();
		String S[]=s.split("");
		int ans=0;
		for(int i=0;i<S.length-1;i++) {
			int sum=0;String used="";
			for(int j=0;j<i;j++) {
				if( used.indexOf(S[j])==-1&&s.indexOf(S[j],i)>0)sum++;
				used+=S[j];
			}
			ans=Math.max(sum,ans);
		}
		System.out.println(ans);
	}
}