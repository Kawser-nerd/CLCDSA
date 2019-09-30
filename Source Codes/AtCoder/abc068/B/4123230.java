import java.util.*;
public class Main{
	public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int num = 1;
    int ans = 1;
    while(true){
        if(n<num){
        	break;
        }else{
            ans = num;
        	num*=2;
        }
    }
    System.out.println(ans);
    }
}