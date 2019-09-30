import java.util.Scanner;
 
public class Main {
 
	public static void main(String[] args) {
		// TODO ???????????????
		Scanner sc =new Scanner(System.in);
		int n=sc.nextInt();
		String S=sc.next();
		int e[]=new int[n];
		char[] c=S.toCharArray();
		for(int i=1;i<n;i++) {
			if(c[i]=='E')e[0]++;
		}
		int ans=e[0];
		for(int i=1;i<n;i++) {
			e[i]=e[i-1];
			if(c[i]=='E')e[i]--;
			if(c[i-1]=='W')e[i]++;
			if(ans>e[i])ans=e[i];
		}
		System.out.println(ans);
 
	}
 
}