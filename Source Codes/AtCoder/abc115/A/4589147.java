import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
    public static void main(String []args)
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        int d = sc.nextInt();
        if(d==25)
            System.out.println("Christmas");
        else if(d==24)
            System.out.println("Christmas Eve");
        else if(d==23)
            System.out.println("Christmas Eve Eve");
        else if(d==22)
            System.out.println("Christmas Eve Eve Eve");

    }
}