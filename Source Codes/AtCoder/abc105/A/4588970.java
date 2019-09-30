import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main{
    public static void main(String []args)
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        if(n%k==0)
            System.out.println(0);
        else
            System.out.println(1);

    }
}