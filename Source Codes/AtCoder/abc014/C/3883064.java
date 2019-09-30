import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int max = 0;
		int[] q =new int[1000002];
		for(int i = 0; i < a; i++){
			int b = sc.nextInt();
			int c = sc.nextInt();
			q[b]++;
			q[c+1]--;
		}
		for(int i= 0; i <= 1000000; i++){
			q[i+1] += q[i];
			if(max<q[i]){
				max=q[i];
			}
		}
		System.out.println(max);
	}
}