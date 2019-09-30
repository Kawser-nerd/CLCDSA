import java.util.*;
 
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[][] chars = new int[n][26];
		for(int i=0; i<n; i++){
			String s = sc.next();
			for(int j=0; j<s.length(); j++){
				chars[i][ (int)(s.charAt(j)-'a') ]++;
			}
		}
		
		String ans="";
		for(int i=0; i<26; i++){
			int min = Integer.MAX_VALUE;
			for(int j=0; j<n; j++){
				min = Math.min(min,chars[j][i]);
			}
			
			for(int j=0; j<min; j++){
				ans += (char)(i+'a');
			}
		}
		System.out.println(ans);
		return;
	}
}