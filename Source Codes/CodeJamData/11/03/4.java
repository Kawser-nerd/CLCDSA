/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */


import java.util.* ;
import java.io.* ;
import java.math.* ;
/************************
 *                      *
 *    Lord Klotski      *
 *                      *
 ***********************/
public class CodeJam_Qualifier_C
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in) ;
        int T = input.nextInt() ;
        for (int t = 1 ; t <= T ; t ++)
        {
            int N = input.nextInt() ;
            int min = 99999999 ; int cur = 0 ; int tot = 0 ;
            for (int i = 0 ; i < N ; i ++)
            {
                int X = input.nextInt() ; tot += X ;
                min = Math.min(min,X) ;
                cur = cur ^ X ;
            }
            System.out.print("Case #" + t + ": ");

            if (cur != 0)
                System.out.println("NO");
            else
                System.out.println(tot - min);

        }
    }
}
