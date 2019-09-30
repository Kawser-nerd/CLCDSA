import java.util.*;
 
public class Main{
	public static void main(String[] args){
    	Scanner scan = new Scanner(System.in);
      	int K = scan.nextInt();
      	int S = scan.nextInt();
      	int counter = 0;
      	for(int X = 0 ; X <= K; X++){
        	for(int Y = 0; Y <= K; Y++){
            	int Z = S - X - Y;
              	if(Z >= 0 && Z <= K){
                	counter++;
                }
            }	
        }
      	System.out.print(counter);
    }
}