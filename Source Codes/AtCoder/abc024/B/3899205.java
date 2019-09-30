import java.util.*;
public class Main{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int t = scan.nextInt();
		int[] a = new int[n];
		int time = 0;
		for(int i=0; i<n; i++){
			a[i] = scan.nextInt();
			time += t;
		}
		for(int i=1; i<n; i++){
			 if(a[i-1]+t>=a[i])time += a[i]-a[i-1]-t;
		}
		System.out.println(time);
	}
}