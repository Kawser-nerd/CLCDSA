import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * @author Igor Kirov
 */
public class A
{
    Scanner in;
    PrintWriter out;

    private void run() throws Exception
    {
        in = new Scanner(new FileInputStream(new File("A.in")));
        out = new PrintWriter(new FileOutputStream(new File("A.out")));

        int t = in.nextInt();

        for (int i=0; i<t; i++)
        {
            int n = in.nextInt();
            int k = in.nextInt();
            boolean ON = (k % (1 << n)) == ((1 << n) - 1);
            out.println("Case #" + (i + 1) + ":" + (ON ? " ON" : " OFF"));
        }

        out.close();
    }

    public static void main(String[] args) throws Exception
    {
        new A().run();
    }
}