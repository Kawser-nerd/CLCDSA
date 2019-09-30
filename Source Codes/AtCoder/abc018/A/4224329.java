import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num = 3;
		long a[] = new long[num];
		for(int i = 0; i < num; i ++) {
			a[i] = sc.nextLong();
		}
		long max = 0;
		int index = 0;
		for(int i = 0; i < num; i ++) {
			if(max < a[i]) {
				max = a[i];
				index = i;
			}
		}
		long min = a[0];
		int index2 = 0;
		for(int i = 0; i < num; i ++) {
			if(min > a[i]) {
				min = a[i];
				index2 = i;
			}
		}
		int rank[] = {2, 2, 2};
		rank[index] = 1;
		rank[index2] = 3;
		for(int i = 0; i < num; i ++) {
			System.out.println(rank[i]);
		}
	}
}