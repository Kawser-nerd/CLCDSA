import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
    public static void main(String []args)
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        int a =sc.nextInt();
        int b =sc.nextInt();
        //int c=sc.nextInt();
        int x1=a+b;
        int x2=a-b;
        int x3=a*b;
        System.out.println(Math.max(Math.max(x1,x2),x3));

    }
}