import java.util.*;

public class B
{
    public static void main(String args[])
    {
        Scanner scan = new Scanner(System.in);

        int T = scan.nextInt();

        for(int ca=1;ca <= T;ca++)
        {
            int m = scan.nextInt();
            int n = scan.nextInt();

            int[][] a = new int[m][n];
            for(int i=0;i < m;i++)
            for(int j=0;j < n;j++)
                a[i][j] = scan.nextInt();

            boolean good = true;
            boolean[] gr = new boolean[m];
            boolean[] gc = new boolean[n];

            for(int k=1;k <= 100;k++)
            {
                Arrays.fill(gr, true);
                Arrays.fill(gc, true);

                for(int i=0;i < m;i++)
                for(int j=0;j < n;j++)
                    if(a[i][j] > k)
                        gr[i] = gc[j] = false;

                for(int i=0;i < m;i++)
                for(int j=0;j < n;j++)
                    if(a[i][j] == k && !gr[i] && !gc[j])
                        good = false;
            }

            System.out.println("Case #" + ca + ": " + (good? "YES" : "NO"));
        }
    }
}