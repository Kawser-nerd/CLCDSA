import java.io.BufferedReader;
import java.io.InputStreamReader;
 
public class Main {
	 public static void main(String[] args) throws Exception {
     BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			String input = br.readLine();
			if (input.equals("a") ||input.equals("e")|| input.equals("i") || input.equals("o") || input.equals("u")) {
           	        System.out.println("vowel");
 
            }else{
       	        System.out.println("consonant");
 
            }
       
     
     
     }
}