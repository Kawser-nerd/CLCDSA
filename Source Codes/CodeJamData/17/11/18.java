import sun.awt.Symbol;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;

/**
 * Created by vitalii on 08.04.17.
 */
public class TaskA {

    Scanner in;
    PrintWriter out;

    public void solve()
    {
        int r = in.nextInt();
        int c = in.nextInt();
        char[][] a = new char[r][];
        for (int i = 0; i < r; i++)
        {
            a[i] = in.next().toCharArray();
        }

        boolean[][] was = new boolean[r][c];
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (was[i][j])
                {
                    continue;
                }

                int max = 0;
                int maxSquare = 0;
                int nx = i, ny = j;
                char cBest = '?';

                for (int ci = i; ci < r; ci++)
                {
                    for (int cj = j; cj < c; cj++)
                    {
                        HashSet<Character> usedCharacters  = new HashSet<>();
                        int total = 0;
                        char cCur = '?';


                        for (int t = i; t <= ci; t++)
                        {
                            for (int k = j; k <= cj; k++)
                            {
                                if (a[t][k] != '?')
                                {
                                    usedCharacters.add(a[t][k]);
                                    total++;
                                    cCur = a[t][k];
                                }
                                if (was[t][k])
                                {
                                    usedCharacters.add('a');
                                    usedCharacters.add('b');
                                }

                            }
                        }
                        if (usedCharacters.size() != 1)
                        {
                            continue;
                        }
                        if (total > max || total == max && maxSquare < (ci - i + 1) * (cj - j + 1))
                        {
                            maxSquare = (ci - i+1) * (cj - j+1);
                            max = total;
                            nx = ci;
                            ny = cj;
                            cBest = cCur;
                        }
                    }
                }
                if (max == 0)
                {
                    throw new AssertionError();
                }
                for (int t = i; t <= nx; t++)
                {
                    for (int k = j; k <= ny; k++)
                    {
                        a[t][k] = cBest;
                        was[t][k] = true;
                    }
                }
            }
        }

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                out.print(a[i][j]);
            }
            out.println();
        }
    }

    public void run() throws FileNotFoundException {
        in = new Scanner(new File("A.in"));
        out = new PrintWriter("A.out");
        int n = in.nextInt();
        for (int i = 0; i < n; i++)
        {
            out.println("Case #"+(i+1)+":");
            solve();
        }
        in.close();
        out.close();
    }

    public static void main(String[] args) throws FileNotFoundException {
        new TaskA().run();
    }

}
