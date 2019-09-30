package exoC;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author jean
 */
public class ExoC {

    public static void main(String[] args) {


        String base = "/home/jean/gcj2014/q/ExoC/";
        String input = base + "b1.in";
        String output = base + "b1.out";

        try {
            Scanner sc = new Scanner(new FileReader(input));
            PrintWriter pw = new PrintWriter(output);

            int n = sc.nextInt();
            sc.nextLine();
            for (int c = 0; c < n; c++) {
                System.out.println("Test case " + (c + 1) + "...");
                pw.print("Case #" + (c + 1) + ": ");
                test(sc, pw);
                pw.println();
            }
            pw.println();
            pw.flush();
            pw.close();
            sc.close();
        } catch (FileNotFoundException ex) {
            Logger.getLogger(ExoC.class.getName()).log(Level.SEVERE, null, ex);
        }

    }

    private static void test(Scanner sc, PrintWriter pw) {
        int R = sc.nextInt();
        int C = sc.nextInt();
        int M = sc.nextInt();
        sc.nextLine();
        
        //empty squares
        int l = C*R - M;
        
        // 1 column
        if(C == 1) {
            pw.println();
            pw.print('c');
            for(int i=1;i<R-M;i++) {
                pw.println();
                pw.print('.');
            }
            for(int i=R-M;i<R;i++) {
                pw.println();
                pw.print('*');
            }
            return;
        }
        
        // 1 row
        else if(R == 1) {
            pw.println();
            pw.print('c');
            for(int i=1;i<C-M;i++) {
                pw.print('.');
            }
            for(int i=C-M;i<C;i++) {
                pw.print('*');
            }
            return;
        }   
        
        // 2 row
        else if (R == 2) {
//            if(l%2 == 1 && l==1) {
//                    System.out.println("DEBUG 1");
//            }
            if(l%2 == 1 && l!=1) {
                pw.println();
                pw.print("Impossible");
                return;
            }
        } else if (C == 2) {
//            if(l%2 == 1 && l==1) {
//                    System.out.println("DEBUG 1");
//            }
            if(l%2 == 1 && l!=1) {
                pw.println();
                pw.print("Impossible");
                return;
            }            
        }
        
        
        //General case
        if(l == 2  || l == 3 || l == 5 || l == 7) {
                pw.println();
                pw.print("Impossible");
        } else {
            char[][] t = new char[C][R];
            for(int i=0;i<R;i++) {
                for(int j=0;j<C;j++) {
                   t[j][i]='.';
                }
            }
            int m = M;
            int c = C;
            int r = R;
            while(m > 0) {
                int p = Math.min(c,r);
                if(m >= p) {
                    if(p == c) {
                        for(int i=0;i<c;i++) {
                            t[i][r-1] =  '*';
                        }
                        r--;
                        m-= c;
                    } else {
                         for(int i=0;i<r;i++) {
                            t[c-1][i] =  '*';
                        }
                        c--;
                        m-= r;                       
                    }
                } else {
                    if(c == r && m == p-1) {
//                        if(p == r) {
                            for(int i=c-1;i>1;i--) {
                                t[i][r-1] =  '*';
                            }
                            t[c-1][r-2] = '*';
                            if(r-2 == 0) {
                                System.err.println("ERREUR 0");
                            }
                            r--;
                            m=0;
//                        } else {
//                            for(int i=r-1;i>1;i--) {
//                                t[c-1][i] =  '*';
//                            }
//                            t[c-2][r-1] = '*';
//                            if(c-2 == 0) {
//                                System.err.println("ERREUR 1");
//                            }
//                            c--;
//                            m=0;                       
//                        }                                       
                    } else {
                        if(p == r) {
                            for(int i=c-1;i>=c-m;i--) {
                                t[i][r-1] =  '*';
                            }
                            r--;
                            m=0;
                        } else {
                            for(int i=r-1;i>=r-m;i--) {
                                t[c-1][i] =  '*';
                            }
                            c--;
                            m=0;                       
                        }                        
                    }
                }
            }
            t[0][0]='c';
            
            
            //check
            if((t[0][1]=='*' || t[1][1]=='*' || t[1][0]=='*') && (t[0][1]=='.' || t[1][1]=='.' || t[1][0]=='.')) {
                System.err.println("ERREUR 2");
            }
            
            for(int i=0;i<R;i++) {
                pw.println();
                for(int j=0;j<C;j++) {
                    pw.print(t[j][i]);
                }
            }
        }
    }


}
