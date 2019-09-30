import java.io.*;
import java.util.Scanner;

public class Main{
    public static void main(String []args) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        for(int i=0;i<str.length();i++)
        {
            if(str.charAt(i)=='1')
                System.out.print('9');
            else if(str.charAt(i)=='9')
                System.out.print('1');
            else
                System.out.print(str.charAt(i));

        }
        System.out.println();

    }
}