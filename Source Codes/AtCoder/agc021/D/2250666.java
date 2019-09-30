public class Main{
	static int dp[][][];
	static String s;
	public static int solve(int i,int j,int k) {
		if(dp[i][j][k]>=0)
			return dp[i][j][k];
		else {
			int ans;
			if(i>j)
				ans=0;
			else if(i==j)
				ans=1;
			else if(s.charAt(i)==s.charAt(j))
				ans=solve(i+1,j-1,k)+2;
			else {
				ans=solve(i+1,j,k);
				ans=Math.max(ans, solve(i,j-1,k));
				if(k>0)
				ans=Math.max(ans, solve(i+1,j-1,k-1)+2);
			}
			dp[i][j][k]=ans;
			return ans;
		}
	}
	public static void main(String[] args) {
		java.util.Scanner scan=new java.util.Scanner(System.in);
		s=scan.next();
		int t=scan.nextInt();
		dp=new int[s.length()][s.length()][t+1];
		for(int i=0;i<s.length();i++) {
			for(int j=0;j<s.length();j++) {
				for(int k=0;k<=t;k++)
					dp[i][j][k]=-1;
			}
		}
		System.out.println(solve(0,s.length()-1,t));
	}
}