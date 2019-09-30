import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int D[] = new int[N];
		for(int i=0; i<N; i++) {
			D[i] = sc.nextInt();
		}
		Arrays.sort(D);
		int count = 1;
		for(int i=0; i<N-1; i++) {
			if(D[i]<D[i+1])count++;
		}
		System.out.println(count);
		sc.close();
	}

}