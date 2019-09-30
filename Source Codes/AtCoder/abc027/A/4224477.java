import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int bucket[] = new int[15];
		for(int i = 0; i < 3; i ++) {
			bucket[sc.nextInt()] ++;
		}
		for(int i = 0; i < bucket.length; i ++) {
			if(bucket[i] % 2 == 1) {
				System.out.println(i);
			}
		}
	}
}