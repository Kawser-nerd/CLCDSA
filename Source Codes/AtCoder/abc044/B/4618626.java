import java.util.*;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		// get a integer
		String input = sc.next();
		
		if(distinct_chars(input)) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
		
		
	}
	
	
	public static boolean distinct_chars(String inputStr) {
    	int total_chars = 0;    	
    	int[] alphabet = new int[26];
    	
	    for (int i = 0; i < 26; i++) alphabet[i] = 0;
	    
    	for(int i = 0; i < inputStr.length(); i++) {
    		char aux = inputStr.charAt(i);
    		int char_number = (int)aux;
    		//lowercase letters corresponding numbers goes between 97 and 122
    		alphabet[char_number - 97]++;
    	}
    	
    	for (int i = 0; i < 26; i++) {
    		if(alphabet[i]%2 != 0) {
    			return false;
    		}
    	}
    	
    	return true;
    }
}