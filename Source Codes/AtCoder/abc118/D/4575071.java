import java.util.Scanner;
import java.util.ArrayList;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		ArrayList<Integer> list=new ArrayList<>();
		int[] set={0,2,5,5,4,5,6,3,7,6};
		int[] a=new int[m];
		String[] dp=new String[n+1];
		dp[0]="";
		for(int i = 0; i<m; i++){
			a[i]= sc.nextInt();
		}
		for(int i = 0; i<=n; i++){
			for(int j = 0; j<m; j++){
				if(i>=set[a[j]] && dp[i-set[a[j]]]!=null){
					if(check(dp[i-set[a[j]]]+a[j],dp[i])){
						dp[i]=dp[i-set[a[j]]]+a[j];
					}
				}
			}
		}
		System.out.println(dp[n]);
	}
	static boolean check(String a,String b){
		if(b==null || a.length()>b.length()){
			return true;
		}
		if(a.length()<b.length()){
			return false;
		}
		return a.compareTo(b)>0;
	}
}