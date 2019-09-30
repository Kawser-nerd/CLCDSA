import java.util.Scanner;
public class Main{
	static long[] size;
	static long[] patty;
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long x = sc.nextLong();
		size=new long[n+1];
		patty=new long[n+1];
		size[0]=patty[0]=1;
		for(int i = 1; i<=n; i++){
			size[i]=size[i-1]*2+3;
			patty[i]=patty[i-1]*2+1;
		}
		System.out.println(dfs(n,x));
	}
	static long dfs(int lay,long number){
		if(lay==0){
			return 1;
		}
		if(number==1){
			return 0;
		}
		if(number<=size[lay]/2){
			return dfs(lay-1,number-1);
		}else if(number==(size[lay]/2+1)){
			return patty[lay-1]+1;
		}else{
			return patty[lay-1]+1+dfs(lay-1,number-size[lay-1]-2);
		}
	}
}