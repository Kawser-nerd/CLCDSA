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
public class CodeJam_Qualifier_D
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in) ;
        int N = input.nextInt() ;
        for (int i = 1 ; i <= N ; i ++)
        {
            int T = input.nextInt() ; int[] a = new int[T] ;
            for (int j = 0 ; j < T ; j ++) a[j] = input.nextInt() ;
            int c = 0 ;
            for (int j = 0 ; j < T ; j ++) if (a[j] == j+1) c ++ ;
            System.out.println("Case #" + i + ": " + ((double)T-(double)c));
        }
    }
}
