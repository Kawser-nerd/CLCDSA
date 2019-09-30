import java.io.File;
import java.io.IOException;
import java.lang.reflect.Array;
import java.util.*;
import java.util.Map.Entry;
 
public class Main{
	
	public static void main(String[] args) throws IOException{
		//File file = new File("input.txt");
		//Scanner in = new Scanner(file);
		Scanner in = new Scanner(System.in);
		
		int N = in.nextInt();
		long[] march = new long[5];
		String marchS = "MARCH";
		
		for(int i = 0; i < N; i++){
			String S = in.next().substring(0, 1);
			for(int j = 0; j < 5; j++){
				if(S.equals(String.valueOf(marchS.charAt(j)))){
					march[j]++;
					break;
				}
			}
		}
		
		long ans = 0;
		for(int i = 0; i < 5 - 2; i++){
			for(int j = i + 1; j < 5 - 1; j++){
				for(int k = j + 1; k < 5; k++){
					ans += march[i] * march[j] * march[k];
				}
			}
		}
		
		System.out.println(ans);
	}
}