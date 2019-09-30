import java.util.Arrays;
import java.util.Scanner;

/**
 * http://abc027.contest.atcoder.jp/tasks/abc027_d
 */
public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		final String S = sc.next();
		sc.close();
		
		int mNum = 0;
		for(char c: S.toCharArray()){
			if(c=='M') mNum++;
		}
		
		int[] m = new int[mNum];
		int at = S.length()-1;
		int current = 0;
		int mIndex = mNum-1;
		while(mIndex>=0){
			char c = S.charAt(at);
			if(c=='M'){
				m[mIndex]=current;
				mIndex--;
			}else if(c=='+'){
				current++;
			}else if(c=='-'){
				current--;
			}
			at--;
		}
		
		Arrays.sort(m);
		int ans = 0;
		for(int i=0; i<mNum/2; i++) ans -= m[i];
		for(int i=mNum/2; i<mNum; i++) ans += m[i];

		System.out.println(ans);
		
	}

}