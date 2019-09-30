package bribetheprisoners;

import java.io.IOException;
import java.util.Arrays;

public class Main extends Base {

    int P, Q;
    int free[];
    int bribe[][];
    
    public static void main(String[] args) throws IOException {
        Main m = new Main();
        m.run("C", "large");        
    }

    @Override
    void init() {
        
    }

    @Override
    void load() throws IOException {
        String s[] = br.readLine().split(" ");
        P = Integer.parseInt(s[0]);
        Q = Integer.parseInt(s[1]);
        
        free = new int[Q+2];
        free[0] = 0;
        free[Q+1] = P+1;
        
        s = br.readLine().split(" ");
        for (int i = 0; i < Q; i++) {
            free[i+1] = Integer.parseInt(s[i]);
        }
        Arrays.sort(free);
        bribe = new int[free.length][free.length];
    }
    
    void compute(int i, int j) {
        if (i == j) {
            bribe[i][j] = 0;
            return;
        }
        int best = -1;
        for (int k = i+1; k < j; k++) {
            int cur = bribe[i][k]+bribe[k][j]+(free[j]-free[i]-2);
            if (best == -1 || cur <= best) best = cur;
        }
        if (best == -1) best = 0;
        bribe[i][j] = best;
    }
    
    @Override
    void solve() {
        for (int iv = 0; iv < free.length; iv++) {
            for (int i = 0; i < free.length; i++) {
                int j = i + iv;
                if (j >= free.length) break;
                compute(i, j);
            }
        }
       /* for (int i = 0; i < free.length; i++) {
            for (int j = 0; j < free.length; j++) {            
                System.out.print(String.format("%1$3d ", bribe[i][j]));
            }
            System.out.println();
        }*/
        printResult(""+bribe[0][Q+1]);
    }

}
