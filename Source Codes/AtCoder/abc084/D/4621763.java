import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int[] a=new int[100001];
		int[] b=new int[100001];
		a[1]=0;
		b[0]=b[1]=-1;
		for(int i = 2; i<100001; i++){
			a[i]+=a[i-1];
			if(b[i]!=-1){
				int k=i;
				k+=i;
				while(k<100001){
					b[k]=-1;
					k+=i;
				}
				if(b[(i+1)/2]!=-1){
					a[i]++;
				}
			}
		}
		int q = sc.nextInt();
		int[] ans=new int[q];
		for(int i = 0; i<q; i++){
			int l = sc.nextInt();
			int r = sc.nextInt();
			ans[i]=a[r]-a[l-1];
		}
		for(int i = 0; i<q; i++){
			System.out.println(ans[i]);
		}
	}
}