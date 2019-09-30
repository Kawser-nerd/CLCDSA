import java.io.BufferedReader;
        import java.io.InputStreamReader;
        import java.util.Scanner;

public class Main {
    public static void main(String []args)
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        System.out.println((a*b)/2);


    }
}