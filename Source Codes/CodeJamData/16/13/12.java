package year2016.round1a;

import java.io.File;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class BFFs {
    
    public static void main(String[] args) throws Exception {
        File inputFile = new File("C-large.in");
        Scanner in = new Scanner(inputFile);
        File outputFile = new File("output.txt");
        PrintWriter out = new PrintWriter(outputFile);

        int T = in.nextInt();
        for (int t=0; t<T; t++) {
            int N = in.nextInt();
            int[] F = new int[N];
            for (int n=0; n<N; n++) {
                F[n] = in.nextInt()-1;
            }
            Set<Integer>[] C = new Set[N];
            int[] D = new int[N];
            int[] DD = new int[N];
            for (int n=0; n<N; n++) {
                int pos = n;
                for (int i=0; i<N; i++) {
                    pos = F[pos];
                }
                // we are in the circle
                int min = pos;
                for (int i=0; i<N; i++) {
                    pos = F[pos];
                    min = Math.min(min, pos);
                }
                Set<Integer> circle;
                if (C[min] == null) {
                    // the circle is new
                    circle = new HashSet<Integer>();
                    int start = pos;
                    do {
                        circle.add(pos);
                        pos = F[pos];
                    } while (pos != start);
                    C[min] = circle;
                }
                circle = C[min];
                C[n] = circle;
                int dist = 0;
                pos = n;
                while (!circle.contains(pos)) {
                    pos = F[pos];
                    dist++;
                }
                D[n] = dist;
                DD[n] = pos;
            }
            int pairs = 0;
            int maxCircle = 0;
            for (Set circle : C) {
                if (circle.isEmpty()) continue; // processed circle
                maxCircle = Math.max(maxCircle, circle.size());
                if (circle.size() == 2) {
                    int maxDist = -1;
                    int nMaxDist = 0;
                    int neighbour = 0;
                    for (int n=0; n<N; n++) {
                        if (C[n] == circle) {
                            if (maxDist < D[n]) {
                                maxDist = D[n];
                                nMaxDist = n;
                                neighbour = DD[n];
                            }
                        }
                    }
                    pairs += 2 + maxDist;
                    Set<Integer> seen = new HashSet<Integer>();
                    int pos = nMaxDist;
                    while (!circle.contains(pos)) {
                        seen.add(pos);
                        pos = F[pos];
                    }
                    maxDist = 0;
                    for (int n=0; n<N; n++) {
                        if (C[n] == circle) {
                            pos = n;
                            int dist = 0;
                            boolean ok = true;
                            while (!circle.contains(pos)) {
                                dist++;
                                if (seen.contains(pos)) {
                                    ok = false;
                                    break;
                                }
                                pos = F[pos];
                            }
                            if (ok && pos != neighbour) {
                                maxDist = Math.max(maxDist, dist);
                            }
                        }
                    }
                    pairs += maxDist;
                }
                circle.clear();
            }
            int answer = Math.max(pairs, maxCircle);
            
            out.println("Case #"+(t+1)+": " + answer);
        }

        out.close();
    }
    
}
