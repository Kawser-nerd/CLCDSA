import java.util.*;
import java.io.*;

/*
   AtCoder contest code
   coder : yoichidon
 */

public class Main {
    public static void main(String[] args) {
        //whenever Tak hold, Aok can hold and end the game.
        //Therefore, Tak's best strategy is "Always move"!

        Scanner sc = new Scanner(System.in);
        int H = sc.nextInt();
        int W = sc.nextInt();
        int N = sc.nextInt();
        LinkedList<Integer>[] block = new LinkedList[W];
        for(int w=0; w<W; w++) {
            block[w] = new LinkedList<>();
            block[w].add(H);
        }
        for(int n=0; n<N; n++) {
            int x = sc.nextInt()-1;
            int y = sc.nextInt()-1;
            block[y].add(x);
        }
        for(int w=0; w<W; w++) Collections.sort(block[w]);

        int ans = 1000000;
        int curX = 0;
        for(int w=0; w<W; w++){
            curX++;
            //System.err.println(curX+" "+w);
            while(block[w].peek()<curX) block[w].poll();
            //System.err.println(block[w].peek());
            ans = Math.min(ans, block[w].peek());

            while(w<W-1 && block[w+1].contains(curX)) curX++;
            if(curX >= block[w].peek()) break;
        }

        System.out.println(ans);


    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.