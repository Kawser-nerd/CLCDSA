import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int h = sc.nextInt();
		int w = sc.nextInt();
		int k1 = sc.nextInt();
		long[][] dp = new long[h+1][w];
		long mod=1000000007;
		dp[0][0]=1;
		for(int i=1; i<=h; i++){
			for(int j=w-1; j>=0; j--){
				for(int k=0; k<Math.pow(2,w-1); k++){
					boolean a=false;
					boolean b=false;
					boolean jud=false;
					int count=0;
					int y=k;
					while(y>0){
						if((y&1)==1){
							if(jud){
								break;
							}
							if(w-1-count==j){
								a=true;
							}else if(w-1-count==j+1){
								b=true;
							}
							jud=true;
						}else{
							jud=false;
						}
						count++;
						y>>=1;
						if(y<=0){
							jud=false;
						}
					}
					if(jud){
						continue;
					}
					if(j>0 && a){
						dp[i][j]+=dp[i-1][j-1];
					}else if(j<w-1 && b){
						dp[i][j]+=dp[i-1][j+1];
					}else{
						dp[i][j]+=dp[i-1][j];
					}
					dp[i][j]%=mod;
				}
			}
		}
		System.out.println(dp[h][k1-1]);
	}
}