import java.util.Arrays;
import java.util.Scanner;


public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		char[] c = sc.next().toCharArray();
		int N=c.length;
		long ans=0L;
		for(int i=0; i<(1<<N-1); i++){
			long sub_sum=0;
			int offset = 0;
			for(int j=0; j<N-1; j++){
				if((1 & i>>j) == 1){
					char[] sub = Arrays.copyOfRange(c, offset, j+1);
					sub_sum += deci_sum(sub);
					offset = j+1;
				}
			}
			char[] sub = Arrays.copyOfRange(c, offset, c.length);
			sub_sum += deci_sum(sub);
			ans += sub_sum;
		}
		System.out.println(ans);
		sc.close();
	}
	
	//?????????????long????
	public static long deci_sum(char[] number){
		String str = new String(number);
		return Long.parseLong(str);
	}
}