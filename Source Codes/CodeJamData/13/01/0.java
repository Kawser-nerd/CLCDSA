/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package exo1;

import java.io.BufferedReader;
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
public class TicTacToeTomek {
    private static final String XWON = "X won\n";
    private static final String OWON = "O won\n";
    private static final String DRAW = "Draw\n";
    private static final String NOTCOMPLETE = "Game has not completed\n";
    
    // Possible lines
    private static final int[][] lines =
        {{0,1,2,3},{4,5,6,7},{8,9,10,11},{12,13,14,15}, //Horizontal
        {0,4,8,12},{1,5,9,13},{2,6,10,14},{3,7,11,15}, //Vertical
        {0,5,10,15},{3,6,9,12}}; //Diagonal

    //Possible char sums
    private static final int x1 = 'X' + 'X' + 'X' + 'X';
    private static final int x2 = 'X' + 'X' + 'X' + 'T';
    private static final int y1 = 'O' + 'O' + 'O' + 'O';
    private static final int y2 = 'O' + 'O' + 'O' + 'T';
    
    
    // To store inputs
    private static char[] table = new char[16];
    
    
    public static void main(String[] args) {
        
        String base="/home/jean/gcj2013/tictactoe/";
        String input=base + "b1.in";
        String output=base + "b2.out";
        
        try {
            Scanner sc = new Scanner(new FileReader(input));
            PrintWriter pw = new PrintWriter(output);
            
            int n = sc.nextInt();
            sc.nextLine();
            for (int c=0; c<n; c++) {
                System.out.println("Test case " + (c+1) + "...");
                pw.print("Case #" + (c+1) + ": ");
                test(sc, pw);
            }
            pw.println();
            pw.flush();
            pw.close();
            sc.close();
        } catch (FileNotFoundException ex) {
            Logger.getLogger(TicTacToeTomek.class.getName()).log(Level.SEVERE, null, ex);
        }
        
    }

    private static void test(Scanner sc, PrintWriter pw) {
        int j=0;
        boolean complete = true;
        for(int i=0;i<4;i++) {
            String s = sc.nextLine();
            for(char c:s.toCharArray()) {
                if(c=='.') complete = false;
                table[j] = c;
                j++;
            }
        }
        sc.nextLine();
        
        for(int[] l: lines) {
            int t = table[l[0]] + table[l[1]] + table[l[2]] + table[l[3]];
            if(t == x1 || t == x2) {
                pw.print(XWON);
                return;
            } else if (t == y1 || t == y2) {
                pw.print(OWON);
                return;
            }
        }
        
        if(complete) {
            pw.print(DRAW);
        } else {
            pw.print(NOTCOMPLETE);
        }
    }
}
