/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package exo3;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;
import java.util.TreeSet;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author jean
 */
public class FairSquare {
    // max number of digits

    private static final int N = 100;
    // Collection to store computed numbers
    private static final TreeSet<BigInteger> ts = new TreeSet<BigInteger>();

    public static void main(String[] args) {
        prepare();
        System.out.println("Found " + ts.size() + " palindromes");

        String base = "/home/jean/gcj2013/fairsquare/";
        String input = base + "b2.in";
        String output = base + "b2.out";

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
            Logger.getLogger(FairSquare.class.getName()).log(Level.SEVERE, null, ex);
        }

    }

    private static void test(Scanner sc, PrintWriter pw) {
        BigInteger low = sc.nextBigInteger();
        BigInteger up = sc.nextBigInteger();
        int n = ts.subSet(low, true, up, true).size();
        pw.print(n);
    }

    private static void prepare() {
        //First, we'll compute every palindrome whose square is a palindrome.

        //Method inspired by http://web.archive.org/web/20020614225321/http://www.geocities.com/williamrexmarshall/math/palsq.html

        //Small ones.
        add("1");
        add("2");
        add("3");

        StringBuilder s = new StringBuilder(N + 1);
        String s1, s2;

        //We'll compute numbers by increasing number of digits
        for (int n = 2; n <= N / 2; n++) {

            //For even numbers of digits
            if (n % 2 == 0) {
                // A)Binary root
                //Root is of the form 1[x][x]'1, with x a string of 0 and 1, with at most three 1s.

                // a) no 1.
                s.setLength(0);
                s.append("1");
                for (int k = 0; k < n / 2 - 1; k++) {
                    s.append("0");
                }
                s1 = s.toString();
                s2 = s.reverse().toString();
                add(s1 + s2);

                // b) one 1.
                // it will be at offset p
                for (int p = 0; p < n / 2 - 1; p++) {
                    s.setLength(0);
                    s.append("1");
                    for (int k = 0; k < n / 2 - 1; k++) {
                        if (k == p) {
                            s.append(("1"));
                        } else {
                            s.append("0");
                        }
                    }
                    s1 = s.toString();
                    s2 = s.reverse().toString();
                    add(s1 + s2);
                }

                // b) two 1.
                // it will be at offset p1 and p2
                for (int p1 = 0; p1 < n / 2 - 1; p1++) {
                    for (int p2 = p1 + 1; p2 < n / 2 - 1; p2++) {
                        s.setLength(0);
                        s.append("1");
                        for (int k = 0; k < n / 2 - 1; k++) {
                            if (k == p1 || k == p2) {
                                s.append(("1"));
                            } else {
                                s.append("0");
                            }
                        }
                        s1 = s.toString();
                        s2 = s.reverse().toString();
                        add(s1 + s2);
                    }
                }

                // c) three 1.
                // it will be at offset p1 and p2 and p3
                for (int p1 = 0; p1 < n / 2 - 1; p1++) {
                    for (int p2 = p1 + 1; p2 < n / 2 - 1; p2++) {
                        for (int p3 = p2 + 1; p3 < n / 2 - 1; p3++) {
                            s.setLength(0);
                            s.append("1");
                            for (int k = 0; k < n / 2 - 1; k++) {
                                if (k == p1 || k == p2 || k == p3) {
                                    s.append(("1"));
                                } else {
                                    s.append("0");
                                }
                            }
                            s1 = s.toString();
                            s2 = s.reverse().toString();
                            add(s1 + s2);
                        }
                    }
                }

                //C) Even roots
                //Root is of the form 2[0]2
                s.setLength(0);
                s.append("2");
                for (int k = 0; k < n / 2 - 1; k++) {
                    s.append("0");
                }
                s1 = s.toString();
                s2 = s.reverse().toString();
                add(s1 + s2);
                
            } else {
                //Odd number of digits
                // B)Ternary root
                //Root is of the form 1[x]y[x]'1, with x a string of 0 and 1, with at most three 1s.
                //y is 0, 1 or 2. if y is 2, at most one 1 in x.

                // a) no 1.
                s.setLength(0);
                s.append("1");
                for (int k = 0; k < n / 2 - 1; k++) {
                    s.append("0");
                }
                s1 = s.toString();
                s2 = s.reverse().toString();
                add(s1 + "0" + s2);
                add(s1 + "1" + s2);
                add(s1 + "2" + s2);


                // b) one 1.
                // it will be at offset p
                for (int p = 0; p < n / 2 - 1; p++) {
                    s.setLength(0);
                    s.append("1");
                    for (int k = 0; k < n / 2 - 1; k++) {
                        if (k == p) {
                            s.append(("1"));
                        } else {
                            s.append("0");
                        }
                    }
                    s1 = s.toString();
                    s2 = s.reverse().toString();
                    add(s1 + "0" + s2);
                    add(s1 + "1" + s2);
                    add(s1 + "2" + s2);
                }

                // b) two 1.
                // it will be at offset p1 and p2
                for (int p1 = 0; p1 < n / 2 - 1; p1++) {
                    for (int p2 = p1 + 1; p2 < n / 2 - 1; p2++) {
                        s.setLength(0);
                        s.append("1");
                        for (int k = 0; k < n / 2 - 1; k++) {
                            if (k == p1 || k == p2) {
                                s.append(("1"));
                            } else {
                                s.append("0");
                            }
                        }
                        s1 = s.toString();
                        s2 = s.reverse().toString();
                        add(s1 + "0" + s2);
                        add(s1 + "1" + s2);
                    }
                }

                // c) three 1.
                // it will be at offset p1 and p2 and p3
                for (int p1 = 0; p1 < n / 2 - 1; p1++) {
                    for (int p2 = p1 + 1; p2 < n / 2 - 1; p2++) {
                        for (int p3 = p2 + 1; p3 < n / 2 - 1; p3++) {
                            s.setLength(0);
                            s.append("1");
                            for (int k = 0; k < n / 2 - 1; k++) {
                                if (k == p1 || k == p2 || k == p3) {
                                    s.append(("1"));
                                } else {
                                    s.append("0");
                                }
                            }
                            s1 = s.toString();
                            s2 = s.reverse().toString();
                            add(s1 + "0" + s2);
                            add(s1 + "1" + s2);
                        }
                    }
                }
                
                //C) Even roots
                //Root is of the form 2[0]x[0]2
                s.setLength(0);
                s.append("2");
                for (int k = 0; k < n / 2 - 1; k++) {
                    s.append("0");
                }
                s1 = s.toString();
                s2 = s.reverse().toString();
                add(s1 + "0" + s2);
                add(s1 + "1" + s2);
            }

        }


    }

    private static void add(String i) {
        BigInteger b = new BigInteger(i);
        BigInteger bs = b.multiply(b);
        StringBuilder s = new StringBuilder(bs.toString());
        String s1 = s.toString();
        String s2 = s.reverse().toString();
        if (s1.compareTo(s2) != 0) {
            System.out.println("Not a palindrome ! " + i + " to the square is " + s1);
            return;
        }
        //System.out.println(i);
        ts.add(bs);
    }
}
