import java.io.*;
        import java.util.Scanner;

public class Main{
    public static void main(String []args) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        int  a = sc.nextInt();
        switch(a)
        {
            case 7:
            case 5:
            case 3:
                System.out.println("YES");
                break;
            default:
                System.out.println("NO");
                break;
        }

    }
}