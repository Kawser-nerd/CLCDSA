import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int h=sc.nextInt();
		int w = sc.nextInt();
		int[][] ar=new int[10][10];
		for(int i = 0; i<10; i++){
			for(int j = 0; j<10; j++){
				ar[i][j] = sc.nextInt();
			}
		}
		for(int i = 0; i<10; i++){
			for(int j = 0; j<10; j++){
				for(int k = 0; k<10; k++){
					if(i!=j && j!=k && i!=k){
						ar[j][k]=Math.min(ar[j][k],ar[j][i]+ar[i][k]);
					}
				}
			}
		}
		int ans=0;
		for(int i = 0; i<h; i++){
			for(int j= 0; j<w; j++){
				int a = sc.nextInt();
				if(a!=1 && a!=-1){
					ans+=ar[a][1];
				}
			}
		}
		System.out.println(ans);
	}
}