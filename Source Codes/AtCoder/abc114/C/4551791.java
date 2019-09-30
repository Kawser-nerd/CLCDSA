import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		long sgs=357;
		int ans=0;
		while(sgs<=n) {
			ans++;
			sgs=nextSgs(sgs,1);
			String str=Long.toString(sgs);
			while(!(str.contains("7")&&str.contains("5")&&str.contains("3"))) {
				sgs=nextSgs(sgs,1);
				str=Long.toString(sgs);
			}
		}
		System.out.println(ans);
	}
	static long nextSgs(long sgs,long kurai) {
		sgs+=kurai*2;
		long temp=(sgs%(kurai*10))/kurai;
		if(temp>=9) {
			sgs-=6*kurai;
			sgs=nextSgs(sgs,kurai*10);
		}else if(temp==2) {
			sgs+=kurai;
		}
		return sgs;
	}
}