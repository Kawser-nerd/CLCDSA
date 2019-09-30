import java.util.*;

public class A
{
    public static void main(String args[])
    {
        Scanner scan = new Scanner(System.in);

        int T = scan.nextInt();

        for(int ca=1;ca <= T;ca++)
        {
            char[][] a = new char[4][4];

            boolean blank = false;
            boolean O = false;
            boolean X = false;

            for(int i=0;i < 4;i++)
            {
                String str = scan.next();
                for(int j=0;j < 4;j++)
                {
                    a[i][j] = str.charAt(j);
                    blank |= a[i][j] == '.';
                }
            }

            boolean sO, sX;

            //H
            for(int i=0;i < 4;i++)
            {
                sO = sX = true;
                for(int j=0;j < 4;j++)
                {
                    if(a[i][j] == '.' || a[i][j] == 'O')
                        sX = false;
                    if(a[i][j] == '.' || a[i][j] == 'X')
                        sO = false;
                }
                O |= sO;
                X |= sX;
            }

            //V
            for(int i=0;i < 4;i++)
            {
                sO = sX = true;
                for(int j=0;j < 4;j++)
                {
                    if(a[j][i] == '.' || a[j][i] == 'O')
                        sX = false;
                    if(a[j][i] == '.' || a[j][i] == 'X')
                        sO = false;
                }
                O |= sO;
                X |= sX;
            }

            //D
            sO = sX = true;
            for(int i=0;i < 4;i++)
            {
                if(a[i][i] == '.' || a[i][i] == 'O')
                    sX = false;
                if(a[i][i] == '.' || a[i][i] == 'X')
                    sO = false;
            }
            O |= sO;
            X |= sX;

            //A
            sO = sX = true;
            for(int i=0;i < 4;i++)
            {
                if(a[i][3-i] == '.' || a[i][3-i] == 'O')
                    sX = false;
                if(a[i][3-i] == '.' || a[i][3-i] == 'X')
                    sO = false;
            }
            O |= sO;
            X |= sX;

            System.out.print("Case #" + ca + ": ");

            if(X)
                System.out.println("X won");
            else if(O)
                System.out.println("O won");
            else if(blank)
                System.out.println("Game has not completed");
            else
                System.out.println("Draw");
        }
    }
}