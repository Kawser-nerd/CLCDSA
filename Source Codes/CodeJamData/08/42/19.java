package com.giolekva.google;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 *
 * @author giolekva
 */
public class Triangle {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("in.txt"));
        PrintWriter out = new PrintWriter(new File("out.txt"));
        
        int c = in.nextInt();
        for(int t = 1; t <= c; t++) {
            out.print("Case #"+t+": ");
            
            int n = in.nextInt();
            int m = in.nextInt();
            int a = in.nextInt();
            
            boolean q = true;
            
            for(int x1 = 0; q && x1 <= n; x1++)
                for(int y1 = 0; q && y1 <= m; y1++)
                    for(int x2 = 0; q && x2 <= n; x2++)
                        for(int y2 = 0; q && y2 <= m; y2++)
                            if(Math.abs(x1*y2-x2*y1) == a) {
                                out.println(" 0 0 "+x1+" "+y1+" "+x2+" "+y2);
                                q = false;
                            }
            
            if(q) out.println("IMPOSSIBLE");
        }
        
        in.close();
        out.close();
    }
}
