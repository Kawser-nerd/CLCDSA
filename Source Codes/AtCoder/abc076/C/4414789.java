import java.util.Scanner;
import java.util.regex.Pattern;

public class Main {

    public static void main(String[] args) throws Exception {

//    	File file = new File("test.txt");
//    	Scanner sc = new Scanner(file);
    	Scanner sc = new Scanner(System.in);
    	String S = sc.next();
    	String T = sc.next();
    	sc.close();
    	StringBuilder sb = new StringBuilder(S);
    	int len_T = T.length();
    	for(int i = sb.length(); i >= len_T; i--){
    		int cnt = 0;
    		for(int j = len_T; j > 0; j--){
    			int K = i-cnt;
    			if(sb.substring(K-1, K).equals(T.substring(j-1, j)) || sb.substring(K-1, K).equals("?")){
    				cnt++;
    				continue;
    			}else{
    				cnt = 0;
    				break;
    			}
    		}
			if(cnt >= len_T){
				sb.replace(i-len_T, i, T);
				String str = sb.toString();
				str = str.replaceAll(Pattern.quote("?"), "a");
				System.out.println(str);
				System.exit(0);
			}
    	}
    	System.out.println("UNRESTORABLE");
    }
}