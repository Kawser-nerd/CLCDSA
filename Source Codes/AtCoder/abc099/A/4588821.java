import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
    public static void main(String []args)
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        int n =sc.nextInt();
        if(n>=1 && n<=999)
            System.out.println("ABC");
        else if(n>999 )
            System.out.println("ABD");

    }
}