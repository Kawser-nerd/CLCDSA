package de.kleberhoff.googlecodejam.quali_2015;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


/**
 * 
 * positive: nijk, negative: NIJK
 * solution only if product = -1;
 * @author ralf
 *
 */
public class C_Dijkstra {
    
    static final String ORDERING = "nijkNIJK";
    
    static final String[] MULT_TABLE = {
        "nijkNIJK",
        "iNkJInKj",
        "jKNiJknI",
        "kjINKJin",
        "NIJKnijk",
        "InKjiNkJ",
        "JknIjKNi",
        "KJinkjIN"
    };
    
    static final int[] CYCLES = { 1, 4, 4, 4, 2, 4, 4, 4 };
    
    int len;
    long repeater;
    String element;
    char elementProduct;
    
    public C_Dijkstra(Scanner input) {
        len = input.nextInt();
        repeater = input.nextLong();
        element = input.next();
        elementProduct = 'n';
        for (int i=0; i<len; i++) {
            elementProduct = multiply(elementProduct, element.charAt(i));
        }
    }
    
    static char multiply(char q1, char q2) {
        int n1 = ORDERING.indexOf(q1);
        int n2 = ORDERING.indexOf(q2);
        return MULT_TABLE[n1].charAt(n2);
    }
    
    static char power(char q, long exp) {
        int n = ORDERING.indexOf(q);
        int cy = CYCLES[n];
        exp = exp % cy;
        char result = 'n';
        for (int i=0; i<exp; i++) {
            result = multiply(result, q);
        }
        return result;
    }
    
    public String solve() {
        char product = power(elementProduct, repeater);
        if (product != 'N') {
            return "NO";
        }
        long s1 = firstSplit();
        long s2 = secondSplit();
        if (s2 > s1) {
            return "YES";
        } else {
            return "NO";
        }
    }
    
    long firstSplit() {
        int nElements = (int) Math.min(repeater, 4);
        char prod = 'n';
        for (long i=0; i<nElements; i++) {
            for (int j=0; j<len; j++) {
                prod = multiply(prod, element.charAt(j));
                if (prod == 'i') {
                    return j + i*len + 1;
                }
            }
        }
        return Long.MAX_VALUE;
    }

    long secondSplit() {
        long end = repeater * len;
        int nElements = (int) Math.min(repeater, 4);
        char prod = 'n';
        for (long i=1; i<=nElements; i++) {
            for (int j=len-1; j>=0; j--) {
                prod = multiply(element.charAt(j), prod);
                if (prod == 'k') {
                    return end - i*len + j;
                }
            }
        }
        return Long.MIN_VALUE;
    }

    public static void main(String[] args) throws IOException {
        long start = System.currentTimeMillis();
        Scanner scanner = new Scanner(new File("D:/Codejam/2015-Q/C.in"));
        PrintWriter writer = new PrintWriter("D:/Codejam/2015-Q/C.out");
        int nTests = scanner.nextInt();
        for (int i=1; i<=nTests; i++) {
            C_Dijkstra task = new C_Dijkstra(scanner);
            StringBuilder builder = new StringBuilder();
            String result = task.solve();
            builder.append("Case #" + i + ": ").append(result);
            
            writer.println(builder);
            System.out.println(builder);
        }
        scanner.close();
        writer.close();
        long finish = System.currentTimeMillis();
        System.out.println("Time=" + (finish - start) + "ms");
    }
    
}
