import java.util.*;
public class Main{
    public static void main(String[]args){
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int a = sc.nextInt();
        int b = sc.nextInt();
        
        if(a>=b) System.out.println("delicious");
        else if(a<b && a+x+1>b) System.out.println("safe");
        else System.out.println("dangerous");
    }
}