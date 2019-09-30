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
public class CodeJam_Qualifier_B
{
    public static int hash(char A, char B)
    {
        int o = A - 'A' ; int s = B - 'A' ;
        return o * 1000 + s ;
    }
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in) ;
        int T = input.nextInt() ;
        for (int t = 1 ; t <= T ; t ++)
        {
            int C = input.nextInt() ;
            String[] combin = new String[C] ;
            for (int i = 0 ; i < C ; i ++) combin[i] = input.next() ;
            int D = input.nextInt() ;
            String[] death = new String[D] ;
            for (int i = 0 ; i < D ; i ++) death[i] = input.next() ;
            input.nextInt() ;
            String s = input.next() ;

            Hashtable X = new Hashtable() ;
            Hashtable Y = new Hashtable() ;
            for (int i = 0 ; i < C ; i ++)
            {
                X.put(hash(combin[i].charAt(0),combin[i].charAt(1)), new zerg(combin[i].charAt(2),false)) ;
                X.put(hash(combin[i].charAt(1),combin[i].charAt(0)), new zerg(combin[i].charAt(2),false)) ;

            }

            for (int i = 0 ; i < D ; i ++)
            {
                Y.put(hash(death[i].charAt(0),death[i].charAt(1)), new zerg('x',true)) ;
                Y.put(hash(death[i].charAt(1),death[i].charAt(0)), new zerg('x',true)) ;
            }
            //System.out.println(X.get(hash('F','Q')));
            StringBuilder S = new StringBuilder() ;

            for (int i = 0 ; i < s.length() ; i ++)
            {
                S = S.append(s.charAt(i)) ;
                // try to combine
                if (S.length() > 1)
                {
                    char one = S.charAt(S.length()-1) ;
                    char two = S.charAt(S.length()-2) ;
                    int three = hash(one,two) ;
                    if (X.containsKey(three))
                    {
                        S.delete(S.length()-2, S.length()) ;
                        zerg Z = (zerg)X.get(three) ;
                        if (!Z.lol)
                            S.append(Z.res) ;
                        else
                            S = new StringBuilder() ;
                    }
                }
                // try to PWN!
                for (int j = 0 ; j < S.length() - 1 ; j ++)
                {
                    char one = S.charAt(j) ;
                    char two = S.charAt(S.length() - 1) ;
                    int three = hash(one,two) ;
                    if (Y.containsKey(three))
                    {
                        S.delete(S.length()-2, S.length()) ;
                        zerg Z = (zerg)Y.get(three) ;
                        if (Z.lol)
                        {
                            S = new StringBuilder();
                            break ;
                        }
                    }
                }

            }

            System.out.print("Case #" + t + ": ");
            System.out.print("[");
            for (int i = 0 ; i < S.length() ; i ++)
            {
                if (i > 0) System.out.print(", ");
                System.out.print(S.charAt(i));
            }
            System.out.println("]");
        }
    }
}
class zerg
{
    char res ; boolean lol ;
    public zerg(char r,boolean lolx) {res = r ; lol = lolx;}
}
class cPair
{
    char A ; char B ;
    public cPair(char a, char b) {A = a ; B = b ;}

}
