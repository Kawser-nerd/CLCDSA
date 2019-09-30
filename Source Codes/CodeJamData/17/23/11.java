

import java.io.*;
import java.util.*;

public class Pony {
    public static final PrintStream out = System.out;
    public static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    public int numCases;
    
    int N;
    int Q;
    long[] maxDist; //E
    long[] speed; //S
    double[][] dist; //D
    int[] start; //U
    int[] end; //V
    
    public void doCase(int caseNumber) throws Exception {
        getInput();
        double[][] shortestMultiCityDist = shortestPaths(dist);
        see(shortestMultiCityDist);
        double[][] shortestOneHorseTime = new double[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (shortestMultiCityDist[i][j] < 0) {
                    shortestOneHorseTime[i][j] = -1;
                } else if (shortestMultiCityDist[i][j] > maxDist[i]) {
                    shortestOneHorseTime[i][j] = -1;
                } else {
                    shortestOneHorseTime[i][j] = shortestMultiCityDist[i][j] / speed[i];
                }
            }
        }
        see(shortestOneHorseTime);
        double[][] shortestMultiHorseTime = shortestPaths(shortestOneHorseTime);
        see(shortestMultiHorseTime);
        for (int i = 0; i < Q; i++) {
            System.out.print(" ");
            System.out.print(shortestMultiHorseTime[start[i] - 1][end[i] - 1]);
        }
        System.out.println();
    }

    void see(double[][] input) {
        if (true) return;
        System.out.println("------");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                System.out.print(input[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println("------");
    }
    
    void getInput() throws IOException {
        String line = in.readLine();
        Scanner scan = new Scanner(line);
        N = scan.nextInt();
        Q = scan.nextInt();
        maxDist = new long[N];
        speed = new long[N];
        dist = new double[N][N];
        start = new int[Q];
        end = new int[Q];
        for (int i = 0; i < N; i++) {
            line = in.readLine();
            scan = new Scanner(line);
            maxDist[i] = scan.nextLong();
            speed[i] = scan.nextLong();
        }
        for (int i = 0; i < N; i++) {
            line = in.readLine();
            scan = new Scanner(line);
            for (int j = 0; j < N; j++) {
                dist[i][j] = scan.nextLong();
            }
        }
        for (int i = 0; i < Q; i++) {
            line = in.readLine();
            scan = new Scanner(line);
            start[i] = scan.nextInt();
            end[i] = scan.nextInt();
        }
    }
    
    double[][] shortestPaths(double[][] input) {
        double[][] path = new double[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                path[i][j] = input[i][j];
            }
        }
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                if (i == k) continue; // no negatives
                for (int j = 0; j < N; j++) {
                    if (i == j || j == k) continue; // no negatives
                    if (path[i][j] < 0 && path[i][k] >= 0 && path[k][j] >= 0) {
                        path[i][j] = path[i][k] + path[k][j];
                    } else if (path[i][j] >= 0 && path[i][k] >= 0 && path[k][j] >= 0) {
                        if (path[i][j] > path[i][k] + path[k][j]) {
                            path[i][j] = path[i][k] + path[k][j];
                        }
                    }
                }
            }
        }
        return path;
    }
    
    public void run() throws Exception {
        numCases = Integer.parseInt(in.readLine().trim());
        for (int i = 1; i <= numCases; i++) {
            out.print("Case #" + i + ":");
            doCase(i);
        }
    }
    
    public static void main(String[] args) throws Exception {
        new Pony().run();
    }

}
