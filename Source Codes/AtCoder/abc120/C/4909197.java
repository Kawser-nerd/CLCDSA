import java.util.Scanner;
import java.util.stream.Stream;


public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		// String?int?????
		int[] S = Stream.of(sc.nextLine().split("")).mapToInt(Integer::parseInt).toArray();

		// 0????1??????
		int zero_cnt=0;
		int one_cnt=0;
		for(int i=0;i<S.length;i++) {
			if(S[i]==0) zero_cnt++;
			else one_cnt++;
		}
		
		// 0or1????????
		// ?????????
		int result = Math.min(zero_cnt, one_cnt);
		
		// 1??2?????×2????
		System.out.println(result*2);
	}
}