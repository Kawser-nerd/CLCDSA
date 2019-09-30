import java.util.*;
public class Main{
	public static void main(String args[]){
    	Scanner scan = new Scanner(System.in);
      	int num = scan.nextInt();
      	int cnt = 0;
        boolean a = num > 99;
      	if(a){
          	cnt++;
        	num = num - 100;
        }
      	boolean b = num > 9;
	    if(b){
      		num = num - 10;
        	cnt++;
      	}
      	boolean c = num == 1;
      	if(c){ cnt ++;}
        System.out.println(cnt);
    }
}