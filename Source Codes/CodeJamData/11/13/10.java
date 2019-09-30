/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package gcj2011.r1A;

import gcj2009.*;
import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import javax.swing.JOptionPane;

/**
 *
 * @author scbit
 */
public class PC {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        new PC().run();
    }
    PrintWriter pw;
    int curs = 0;
    int curt = 1;
int tmps=0;
    void run() throws Exception {
        File infile = new File("C-small-attempt1.in");
        String outfile = "C-small-attempt1.out";
        pw = new PrintWriter(outfile);
        int T = 0;
        //BufferedReader br=new BufferedReader(new FileReader(infile));
        //N=Integer.parseInt(br.readLine());
        Scanner sc = new Scanner(infile);
        T = sc.nextInt();

        for (int case_i = 1; case_i <= T; case_i++) {
            int result = 0;
            int N = sc.nextInt();
            int c, s, t;
            curs = 0;
            curt = 1;
            List<card> hands = new ArrayList<card>();
            for (int i = 0; i < N; i++) {
                c = sc.nextInt();
                s = sc.nextInt();
                t = sc.nextInt();
                hands.add(new card(c, s, t));
            }
            int M = sc.nextInt();
            List<card> deck = new ArrayList<card>();
            for (int i = 0; i < M; i++) {
                c = sc.nextInt();
                s = sc.nextInt();
                t = sc.nextInt();
                deck.add(new card(c, s, t));
            }


int oldmax=0;
int oldcurs=0;

tt:         while (true) {
                if(curt>0){
                    int ci=checkt(hands);
                    if(ci>=0){
                        playacard(hands, deck, ci);
                        continue;
                    }
                    Collections.sort(hands);
                    int ai=Math.min(curt, hands.size());
                    for(int i=0;i<ai;i++){
                        if(hands.get(i).getC()>0){
                            playacard(hands, deck, i);
                            continue tt;
                        }
                    }
                    oldcurs=curs;
                    tmps=curs;
                    for(int i=0;i<ai;i++){
                        playacardex(hands, deck, i);
                    }
                    oldmax=Math.max(oldmax, tmps);
                    int cc=checkc(hands);
                    if(cc==-1){
                        break;
                    }else{
                        playacard(hands, deck, cc);
                        continue tt;
                    }
                    
                }

                break tt;
            }
            pw.printf("Case #%d: %d\n", case_i, Math.max(oldmax, curs));
            System.out.printf("Case #%d: %d\n", case_i, Math.max(oldmax, curs));
        }
        pw.close();
    }

    private int checkt(List<card> h) {
        for (int i = 0; i < h.size(); i++) {
            if (h.get(i).getT() > 0) {
                return i;
            }
        }
        return -1;
    }
private int checkc(List<card> h){
    for (int i = 0; i < h.size(); i++) {
            if (h.get(i).getC() > 0) {
                return i;
            }
        }
        return -1;
}
    private void playacard(List<card> h, List<card> d, int i) {
        card c = h.remove(i);
        curs += c.getS();
        curt = curt + c.getT() - 1;
        for (int ii = 0; ii < c.getC(); ii++) {
            if(d.size()<=0) break;
            card cd = d.remove(0);
            h.add(cd);

        }
    }
    private void playacardex(List<card> h, List<card> d, int i) {
        card c = h.get(i);
        tmps += c.getS();
        assert(c.getT()==0);
        assert(c.getC()==0);
    }
}

class card implements Comparable<card> {

    private int c;

    public int getC() {
        return c;
    }

    public void setC(int c) {
        this.c = c;
    }
    private int s;

    /**
     * Get the value of s
     *
     * @return the value of s
     */
    public int getS() {
        return s;
    }

    /**
     * Set the value of s
     *
     * @param s new value of s
     */
    public void setS(int s) {
        this.s = s;
    }
    private int t;

    public int getT() {
        return t;
    }

    public void setT(int t) {
        this.t = t;
    }

    public int compareTo(card o) {
        return o.s - this.s;
    }

    public card(int c, int s, int t) {
        this.c = c;
        this.s = s;
        this.t = t;
    }
}
