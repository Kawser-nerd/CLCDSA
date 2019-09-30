import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int ans=200;
		int[] a1=new int[n];
		int sum=0;
		for(int i = 0; i<n; i++){
			int a = sc.nextInt();
			sum+=a;
			a1[i]=a;
		}
		for(int i=0; i<Math.pow(2,n-1); i++){
			int t = i;
			int count=0;
			int sum0=sum;
			int sum1=0;
			while(t>0){
				if((t & 1)==1){
					sum1+=a1[count];
					sum0-=a1[count];
				}
				count++;
				t>>=1;
			}
			if(ans>Math.max(sum0,sum1)){
				ans=Math.max(sum0,sum1);
			}
		}
		System.out.println(ans);
	}
}