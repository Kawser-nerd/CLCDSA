import java.util.Scanner;
public class Main{
	static int n;
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		n =sc.nextInt();
		int[] num = new int[101];
		for(int i=2; i<=n; i++){
			int tmp = i;
			for(int j=2; j<=i;j++){
				while(tmp%j==0){
					num[j]++;
					tmp/=j;
				}
			}
		}
		int ans=0;
		ans+=count(74,num);
		ans+=count(24,num)*(count(2,num)-1);
		ans+=count(14,num)*(count(4,num)-1);
		ans+=count(4,num)*(count(4,num)-1)*(count(2,num)-2)/2;
		System.out.println(ans);
	}
	public static int count(int a,int[] num){
		int count=0;
		for(int i=2; i<=n; i++){
			if(num[i]>=a){
				count++;
			}
		}
		return count;
	}
}