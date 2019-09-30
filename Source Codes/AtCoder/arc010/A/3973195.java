import java.util.*;

public class Main {
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		int M = scanner.nextInt();
		int A = scanner.nextInt();
		int B = scanner.nextInt();
		int[] c = new int[M+1];
		for(int i = 1; i <= M; i++){
			c[i] = scanner.nextInt();
		}
		int cards = N;
		int index = -1;
		boolean flag = true;
		for(int i = 1; i <= M; i++){
			if(cards <= A){
				cards += B;
			}
			if(cards < c[i]){
				index = i;
				flag = false;
				break;
			}
			cards -= c[i];
		}
		if(flag){
			System.out.println("complete");
		}else{
			System.out.println(index);
		}
	}
}