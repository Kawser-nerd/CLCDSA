import java.util.*;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] r = new int[n];
		for(int i=0; i<n; i++){
			r[i] = sc.nextInt();
		}
		Arrays.sort(r);
		int sum = 0;
		for(int i=n-1; i>=0; i--){
			if(i%2==(n-1)%2)sum += r[i]*r[i];
			else sum -= r[i]*r[i];
		}
		System.out.println(sum*Math.PI);
	}
}