import java.util.*;
import java.io.*;

public class Main {
	
	public static void ask(String number){
		System.out.println("? "+number);
	}
	public static void ask(long number){
		System.out.println("? "+number);
	}
	public static void answer(String number){
		System.out.println("! "+number);
	}
	public static void answer(long number){
		System.out.println("! "+number);
	}
	
	//10^k
	public static long dec(int k){
		long a =1;
		for(int i=0;i<k;i++)a*=10;
		return a;
	}
	
    public static void main(String[] args) {
    	/*
    	1,10,100,...10^10??????.
		No??????????(10^k?no??k?)
		n=(k?)+"0" ? N???? n>N?????,
		"Yes" <=> "n">"N" <=> (k?)>=N
		BinarySearch????
	
		??Yes??N==10^k
		2?   Y -> 1
		20?  Y -> 10
		...
    	*/
    	
        Scanner sc = new Scanner(System.in);
        
        int digit = -1;
        for(int i=0;i<=10;i++){
        	ask(dec(i));
        	if(sc.nextLine().equals("N")){
        		digit = i;
        		break;
        	}
        }
        
        if(digit == -1){
        	for(int i=0;i<=10;i++){
        		ask(2*dec(i));
        		if(sc.nextLine().equals("Y")){
        			answer(dec(i));
        			System.exit(0);
        		}
        	}
        }
        else{
        	long min = dec(digit-1);
        	long max = dec(digit)-1;
        	while(min<max){
        		long next = (min+max)/2;
        		ask(next*10);
        		if(sc.nextLine().equals("Y")){
        			max = next;
        		}else{
        			min = next+1;
        		}
        	}
        	answer(min);
        	System.exit(0);
        }
    }
}