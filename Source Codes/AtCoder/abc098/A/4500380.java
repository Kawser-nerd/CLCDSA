import java.util.*;
public class Main {
	public static void main(String[] args){
      	//???????
		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();
      	int M = sc.nextInt();
      	int a[] = new int[3];
      	a[0] = N + M;
      	a[1] = N - M;
      	a[2] = N * M;
      	Arrays.sort(a);
		System.out.println(a[2]);      
    }
}