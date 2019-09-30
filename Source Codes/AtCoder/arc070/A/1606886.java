import java.io.IOException;
import java.util.Scanner;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        Scanner input = new Scanner(System.in);
        
        int x = input.nextInt(); // 12
        
        int count = 0;
        
        for (int i = 1; i <= x; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                count += 1;
                //System.out.println(i);
                if (count == x)
                {
                    System.out.println(i);
                    System.exit(0);
                }
            }
        }
    }
}