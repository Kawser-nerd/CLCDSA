import java.util.*;
public class Main{
	static int BridNum(int n, int[] p, int sum){
		if(sum%n!=0)return -1;
		int pisl = sum / n;
		int num = 0;
		for(int i=0; i<n-1; i++){
			if(p[i]!=pisl){
				int part = p[i];
				for(int j=1; j<n-i; j++){
					part += p[i+j];
					if(part==pisl*(j+1)){
						num += j;
						i += j;
						break;
					}
				}
			}
		} 
		return num;
	}

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] a = new int [N];
		int asum = 0;
		for(int i=0; i<N; i++){
			a[i] = sc.nextInt();
			asum += a[i];
		}
		System.out.println(BridNum(N, a, asum));
	}
}