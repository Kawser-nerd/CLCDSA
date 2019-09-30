import java.util.Scanner;

public class Main {
	
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        
        String S = sc.nextLine();
        
        if (S.length() == 1) {
        	System.out.println(S);
        	return;
        }
        
        char[] string = S.toCharArray();
       
        long ans = 0;
        for (int i = 0; i < Math.pow(2, S.length()-1); i++) {
        	String binary = Integer.toBinaryString(i);
        	binary = new StringBuffer(binary).reverse().toString();
        	String sub = "";
        	for (int j = 0; j < binary.length(); j++) {
        		if (binary.charAt(j) == '1') {
        			sub = sub + string[j];
        			ans+= Long.parseLong(sub);
        			sub = "";
        		} else {
        			sub = sub + string[j];
        		}
        	}
        	
        	if (binary.length() != S.length()) {
        		sub += new String(string, binary.length(), S.length() - binary.length());
        		ans+= Long.parseLong(sub);
        	}
        	
        }
       
        
        System.out.println(ans);
    }
}