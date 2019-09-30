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
public class CodeJam_Qualifier_A
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in) ;
        int T = input.nextInt() ;

        for (int i = 1 ; i <= T ; i ++)
        {
            int X = input.nextInt() ;
            int[] a = new int[X] ;
            for (int j = 0 ; j < X ; j ++)
            {
                char t = input.next().charAt(0) ;
                int n = input.nextInt() ;
                if (t == 'B') n += 200 ;
                a[j] = n ;
            }
            int O = 1 ;
            int B = 1 ;
            int cur = a[0] < 200 ? 0 : 1 ;
            int idx = 0 ;
            int free = 0 ;
            int cost = 0 ;
            while (idx < a.length)
            {
                //System.out.println(free);
                int tmp = a[idx] ;
                int nxt = tmp < 200 ? 0 : 1 ;
                if (cur == nxt)
                {
                    
                    // continue with this d00d:
                    tmp = tmp > 200 ? tmp - 200 : tmp ;
                    if (nxt == 0)
                    {
                        // using O
                        cost += Math.abs(O-tmp) + 1 ;
                        free += Math.abs(O-tmp) + 1 ;
                        O = tmp ;
                    }
                    else if(nxt == 1)
                    {
                        // using O
                        cost += Math.abs(B-tmp) + 1 ;
                        free += Math.abs(B-tmp) + 1 ;
                        B = tmp ;
                    }
                }
                else
                {
                    // free money! :D
                    tmp = tmp > 200 ? tmp - 200 : tmp ;
                    if (nxt == 0)
                    {
                        // using O
                        int y ;
                        cost += (y=Math.max(1,Math.abs(O-tmp) + 1 - free)) ;
                        free = y ;
                        O = tmp ;
                    }
                    else if(nxt == 1)
                    {
                        // using B
                        int y ;
                        cost += (y=Math.max(1,Math.abs(B-tmp) + 1 - free)) ;
                        free = y ;
                        B = tmp ;
                    }
                }
                idx ++ ; cur = nxt ;
            }
            System.out.println("Case #" + i + ": " + cost);
        }
    }
}
