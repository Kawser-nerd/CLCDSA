import java.util.*;
public class Main {

	public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
		int n = sc.nextInt() , d = sc.nextInt() , x = sc.nextInt();
		int[] A = new int[n];
		for(int i=0;i<n;i++){
			A[i]=sc.nextInt();
		}
		int answer=x;
		for(int i=0;i<n;i++){
			answer=answer+(d-1)/A[i]+1;
		}
		System.out.println(answer);
	}

}