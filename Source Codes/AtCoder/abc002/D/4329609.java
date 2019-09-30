import java.util.Scanner;
import java.util.ArrayList;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int q = sc.nextInt();
		int m = sc.nextInt();
		int[][] n = new int[q][q];
		int ans=0;
		for(int i = 0; i<m; i++){
			int x = sc.nextInt();
			int y = sc.nextInt();
			n[x-1][y-1]=1;
			n[y-1][x-1]=1;
		}
		for(int i=1; i<Math.pow(2,q); i++){
			ArrayList<Integer> list=new ArrayList<Integer>();
			int t=i;
			int count1=0;
			int count=0;
			while(t>0){
				if((t & 1)==1){
					list.add(count);
					count1++;
				}
				count++;
				t>>=1;
			}
			boolean flag=true;
			for(int a:list){
				for(int b:list){
					if(a!=b){
					if(n[a][b]==1){
						continue;
					}else{
						flag=false;
						break;
					}
					}
				}
			}
			if(flag){
				ans=Math.max(ans,count1);
			}
		}
		System.out.println(ans);
	}
}