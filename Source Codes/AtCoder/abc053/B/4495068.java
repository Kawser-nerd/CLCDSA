import java.util.*;

public class Main{
	public static void main(String[] args){
    	Scanner scan = new Scanner(System.in);
      	String s = scan.next();
      	int num = s.length();
      	int min = 10;
      	int max = 0;
      	for(int i = 0; i < num; i++){
        	if(s.charAt(i) == 'A'){
            	min = i;	
              	break;
            }
        }
      	for(int i = 0; i < num; i++){
          	if(s.charAt(i) == 'Z'){
            	max = i;
            }
        }
      	System.out.print(max - min + 1);
    }
}