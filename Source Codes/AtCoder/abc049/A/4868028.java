import java.util.*;
 
public class Main{
	public static void main(String[] args){
    	Scanner scan = new Scanner(System.in);
      	String s = scan.next();
      	if(s.contains("a")||s.contains("i")||
          s.contains("u")||
          s.contains("e")||s.contains("o")){
        	System.out.print("vowel");
        }
      	else{
        	System.out.print("consonant");
        }
    }
 
}