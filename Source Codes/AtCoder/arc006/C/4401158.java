import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] box=new int[n];
		int ans=0;
		for(int i = 0; i<n; i++){
			int w = sc.nextInt();
			box[i]=100001;
			for(int j=0; j<n; j++){
				if(box[j]>=w){
					ans=Math.max(ans,j);
					box[j]=w;
					break;
				}
			}
		}
		System.out.println(ans+1);
	}
}