import java.util.Scanner;
import java.util.Arrays;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[] box=new int[n];
		int[] can=new int[n];
		can[0]=1;
		Arrays.fill(box,1);
		for(int i = 0; i<m; i++){
			int x=sc.nextInt()-1;
			int y=sc.nextInt()-1;
			if(can[x]==1 && box[x]>1){
				can[y]=1;
			}
			if(can[x]==1 && box[x]==1){
				can[x]=0;
				can[y]=1;
			}
			box[x]--;
			box[y]++;
		}
		int ans=0;
		for(int i = 0; i<n; i++){
			if(can[i]==1){
				ans++;
			}
		}
		System.out.println(ans);
	}
}