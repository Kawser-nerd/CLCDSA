import java.util.Scanner;

public class Main{
    public static void main(String[] arg){
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        int b = in.nextInt();
        int c = in.nextInt();
        
        System.out.println(Math.min(a+b,Math.min(b+c, c+a)));
        
    }
}