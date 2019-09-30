import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Scanner;

/**
 * Created by vitalii on 08.04.17.
 */
public class TaskC {

    Scanner in;
    PrintWriter out;


    int bestAns;
    int HD;


    public void solve()
    {
        bestAns = 1000000;
        int hd = in.nextInt();
        int ad = in.nextInt();

        HD = hd;

        int hk = in.nextInt();
        int ak = in.nextInt();

        int b = in.nextInt();
        int d = in.nextInt();

        solveD(hd, ad, hk, ak, b, d, 0);
        out.println(bestAns == 1000000 ? "IMPOSSIBLE" : bestAns);

    }

    private void solveD(int hd, int ad, int hk, int ak, int b, int d, int i) {
        solveB(hd, ad, hk, ak, b, i);

        if (ak == 0 || d == 0)
        {
            return;
        }

        if (hd <= Math.max(0, ak - d))
        {
            if (HD - ak <= Math.max(0, ak - d))
            {
                return;
            }
            solveD(HD - ak, ad, hk, ak, b, d,i+1);
            return;
        }

        solveD(hd-Math.max(0, ak - d), ad, hk, Math.max(0, ak - d), b, d,i+1);
    }

    private void solveB(int hd, int ad, int hk, int ak, int b, int i)
    {
        solveK(hd, ad, hk, ak, i);

        if (ad >= hk || b == 0)
        {
            return;
        }

        if (hd <= ak)
        {
            if (HD - ak <= ak)
            {
                return;
            }
            solveB(HD - ak, ad, hk, ak, b, i+1);
            return;
        }
        solveB(hd-ak, ad+b, hk, ak, b,i+1);

    }

    private void solveK(int hd, int ad, int hk, int ak, int i) {
        if (hk <= ad)
        {
            bestAns = Math.min(bestAns, i+1);
            return;
        }

        if (hd <= ak)
        {
            if (HD - ak <= ak)
            {
                return;
            }
            solveK(HD - ak, ad, hk, ak, i+1);
            return;
        }

        solveK(hd - ak, ad, hk - ad, ak, i+1);
    }



    public void run() throws FileNotFoundException {
        in = new Scanner(new File("C.in"));
        out = new PrintWriter("C.out");
        int n = in.nextInt();
        for (int i = 0; i < n; i++)
        {
            out.print("Case #"+(i+1)+": ");
            solve();
        }
        in.close();
        out.close();
    }

    public static void main(String[] args) throws FileNotFoundException {
        new TaskC().run();
    }

}
