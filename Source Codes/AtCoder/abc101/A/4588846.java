import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
    public static void main(String []args)
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        int sum=0;
        for(char x:str.toCharArray())
        {
            if(x=='+')
                sum++;
            else if(x=='-')
                sum--;
        }
        System.out.println(sum);

    }
}