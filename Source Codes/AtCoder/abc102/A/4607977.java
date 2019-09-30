import java.io.*;
        import java.util.Scanner;

public class Main{
    public static void main(String []args) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        long  num = sc.nextLong();
        if(num%2==0 && num%num==0)
            System.out.println(num);
        else
            System.out.println(num*2);
    }
}