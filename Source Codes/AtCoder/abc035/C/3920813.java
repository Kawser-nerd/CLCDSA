import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n =sc.nextInt();
		int q =sc.nextInt();
		int[] re=new int[n+1];
		re[0]=0;
		for(int i = 0; i<q; i++){
			re[sc.nextInt()-1]+=1;
			re[sc.nextInt()]+=-1;
		}
		for(int i=0; i<n; i++){
			re[i+1]+=re[i];
			if(re[i]%2==0){
				System.out.print("0");
			}else{
				System.out.print("1");
			}
		}
		System.out.println();
	}
}