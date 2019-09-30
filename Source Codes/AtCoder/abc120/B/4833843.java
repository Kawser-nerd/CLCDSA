import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
        int min;
        int count = 0;
        int result = 0;
        if(a < b) min = a;
        else min = b;
        for(int i=min; i>=1; i--){
         	if(a % i == 0 && b % i == 0){
             	count++;
                if(count == c){
                  result = i;
                  break;
                }
            }
        }
		System.out.println(result);
	}
}