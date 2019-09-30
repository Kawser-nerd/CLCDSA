import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		// ?????
	    int A = sc.nextInt();
	    int B = sc.nextInt();
	    int K = sc.nextInt();
	    int mini=Math.min(A, B);
	    int[] a=new int[mini];
	    for (int i = 1; i < a.length+1; i++) {
			if (A%i==0&&B%i==0) {
				a[i-1]=i;
			}
			else {
				a[i-1]=0;
			}
		}
	    Arrays.sort(a);
	    System.out.println(a[a.length-K]);
	  }
}