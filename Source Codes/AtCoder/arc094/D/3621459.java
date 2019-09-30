import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		String s=sc.next();
		long mod=998244353;
		if(s.length()<=4) System.out.println(brute(s));
		else{
			int sum=0;
			for(int i=0;i<s.length();i++) sum+=s.charAt(i)-67;
			sum%=3;
			boolean bo=false;
			boolean bo2=true;
			for(int i=0;i<s.length()-1;i++){
				if(s.charAt(i)!=s.charAt(i+1)) bo=true;
				if(s.charAt(i)==s.charAt(i+1)) bo2=false;
			}
			if(!bo){
				System.out.println(1);
				return;
			}
			long[][][][] dp=new long[s.length()][2][3][3];
			dp[0][0][0][0]=1;
			dp[0][0][1][1]=1;
			dp[0][0][2][2]=1;
			for(int i=1;i<s.length();i++){
				for(int j=0;j<3;j++){
					for(int k=0;k<3;k++){
						dp[i][0][j][k]=(dp[i-1][0][(j+1)%3][(k-j+3)%3]+dp[i-1][0][(j+2)%3][(k-j+3)%3])%mod;
						dp[i][1][j][k]=(dp[i-1][1][j][(k-j+3)%3]+dp[i-1][1][(j+1)%3][(k-j+3)%3]+dp[i-1][1][(j+2)%3][(k-j+3)%3]+dp[i-1][0][j][(k-j+3)%3])%mod;
					}
				}
			}
			System.out.println((dp[s.length()-1][1][0][sum]+dp[s.length()-1][1][1][sum]+dp[s.length()-1][1][2][sum]+(bo2?1:0))%mod);
		}
	}
	static long brute(String s){
		HashSet<String> set=new HashSet<>();
		String[] stack=new String[1000];
		int size=0;
		stack[size++]=s;
		set.add(s);
		while(size>0){
			String cur=stack[--size];
			for(int i=0;i<cur.length()-1;i++){
				if(cur.charAt(i)!=cur.charAt(i+1)){
					char ch=(char)(294-cur.charAt(i)-cur.charAt(i+1));
					String ns="";
					for(int j=0;j<cur.length();j++){
						if(j==i||j==(i+1))ns+=ch;
						else ns+=cur.charAt(j);
					}
					if(set.contains(ns))continue;
					stack[size++]=ns;
					set.add(ns);
				}
			}
		}
		return set.size();
	}
}