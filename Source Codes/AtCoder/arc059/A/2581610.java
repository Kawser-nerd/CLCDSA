import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		int N=in.nextInt();
		int[] arr=new int[N];
		for (int i=0;i<N;i++){
			arr[i]=in.nextInt();
		}
		int change=200*200*100;
		for (int i=-100;i<=100;i++){
			int temp=0;
			for (int j=0;j<N;j++){
				temp+=(i-arr[j])*(i-arr[j]);
			}
			if (temp<change){
				change=temp;
			}
		}
		System.out.print(change);
	}
}