import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		int[] e=new int[55556];
		int count=0;
		for(int i=2; i<55556; i++){
			if(e[i]!=-1){
				if(i%5==1){
					count++;
					System.out.print(i+" ");
				}
				if(count==n){
					return;
				}
				int k=i;
				k+=i;
				while(k<55556){
					e[k]=-1;
					k+=i;
				}
			}
		}
	}
}