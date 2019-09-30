import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int t = sc.nextInt();
		int[] a = new int[n];
		int time = 0;
		for(int i=0; i<n; i++){
			a[i] = sc.nextInt();
			time += t;
		}
		for(int i=1; i<n; i++){
			 if(a[i-1]+t>=a[i])time += a[i]-a[i-1]-t;
		}
		System.out.println(time);
    }
}