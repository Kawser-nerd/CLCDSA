import java.util.*;
 
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int sum = 0;
        for(int i=0; i<n; i++){
            int a = sc.nextInt();
            sum += a-1;
        }
        System.out.println(sum);
    }
}