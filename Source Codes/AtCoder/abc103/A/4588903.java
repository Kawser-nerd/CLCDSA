import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main{
    public static void main(String []args)
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b =sc.nextInt();
        int c =sc.nextInt();
        int x3=Math.abs(a-b);
        int x1= Math.abs(a-c);
        int x2= Math.abs(b-c);
        int total=x1+x2+x3;
        total = Math.abs(total-(Math.max(x3,Math.max(x2,x1))));
        System.out.println(total);

    }
}