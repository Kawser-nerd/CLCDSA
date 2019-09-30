import java.util.ArrayDeque;
import java.util.HashSet;
import java.util.Queue;
import java.util.Scanner;

	
public class Main{
	
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		int L = S.length();
		int[] B = new int[26];
		
		if(L!=26){
			for(int i=0;i<L;i++){
				B[S.charAt(i)-'a']=1;
			}
			for(char i='a';i<='z';i++){
				if(B[i-'a']==0){
					System.out.println(S + i);
					break;
				}
			}
		}else{
			int min = 1000000000;
			HashSet<Character> set = new HashSet<Character>();
			for(int i=25;i>0;i--){
				set.add(S.charAt(i));
		
				if(S.charAt(i-1)<S.charAt(i)){
					set.add(S.charAt(i));
					for(char c:set){
						if(c>S.charAt(i-1)){
							min = Math.min(min, c);
						}
					}
					System.out.println(S.substring(0,i-1) + (char)min);																
					return;
				}
			}
			System.out.println(-1);
		}
		
	}
	
}