import java.io.*;
import java.util.Scanner;

public class Main{
    public static boolean Odd(int a, int b)
    {
        for(int i=1;i<=3;i++)
        {
            if((a*b*i)%2!=0)
                return true;
        }
        return false;
    }
    public static void main(String []args) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        if(Odd(a,b)==true)
            System.out.println("Yes");
        else
            System.out.println("No");

    }
}