import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;


public class B {
    private static final int MAX_THREADS = 8;

    static class Solver extends Thread {
        Object result;
        private int N;
        private int P;
        private int[] R;
        private int[][] Q;

        void read(Scanner sc) {
            N = sc.nextInt();
            P = sc.nextInt();
            R = new int[N];
            Q = new int[N][P];
            for (int i = 0; i < N; i++)
                R[i] = sc.nextInt();
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < P; j++) {
                    Q[i][j] = sc.nextInt();
                }
                Arrays.sort(Q[i]);
            }
        }

        Object solve() {
            int cnt = 0;
            boolean[][] used = new boolean[N][P];

            List<LinkedList<Integer>> QQ = new ArrayList<>();
            for (int i = 0; i < N; i++) {
                QQ.add(new LinkedList<>());
                for (int j = 0; j < P; j++) {
                    QQ.get(i).add(Q[i][j]);
                }
            }

            for (int m = 1; m <= 1000000; m++) {
                int[] min = new int[N];
                int[] max = new int[N];
                for (int i = 0; i < N; i++) {
                    int amount = R[i]*m;
                    min[i] = (amount*9);
                    max[i] = (amount*11);
                }

                while (possible(QQ, min, max)) {
                    for (int i = 0; i < N; i++) {
                        int amount = QQ.get(i).poll();
                        assert amount >= 0.9*R[i]*m - 1e-9 && amount <= 1.1*R[i]*m + 1e-9;
                    }
                    cnt++;
                }
            }

            return cnt;
        }

        private boolean possible(List<LinkedList<Integer>> qq, int[] min, int[] max) {
            for (int i = 0; i < N; i++) {
                LinkedList<Integer> qqq = qq.get(i);
                while (!qqq.isEmpty() && qqq.peekFirst()*10 < min[i])
                    qqq.poll();
                if (qqq.isEmpty())
                    return false;

                if (qqq.peek()*10 > max[i])
                    return false;
            }
            return true;
        }

        public void run() {
            result = solve();
            synchronized (sync) {
                remaining--; running--;
                startNextCase();
                System.out.println("Remaining: " + remaining + ", Running: " + running);
                if (finished())
                    sync.notifyAll();
            }
        }
    }


    private static Object sync = new Object(); static int running, remaining, next;
    private static ArrayList<Solver> cases = new ArrayList<Solver>(); 

    public static void main(String[] args) throws Exception {
        Scanner sc; PrintWriter fw; 
        String inFile = "input.txt", outFile = "output.txt";
        if (args.length == 0) {
            sc = new Scanner(System.in);
    //        sc = new Scanner(new FileInputStream(inFile));
        } else {
            inFile = args[0];
            sc = new Scanner(new FileInputStream(inFile));
            if (args.length > 1)
                outFile = args[1];
            else if (inFile.endsWith(".in"))
                outFile = inFile.substring(0, inFile.length() - 2) + "out";
            System.out.println(inFile + " -> " + outFile);
        }
        
        fw = new PrintWriter(new FileWriter(outFile, false));
        
        int N = sc.nextInt();
        sc.nextLine();
        
        for (int cas = 1; cas <= N; cas++) {
            Solver solver = new Solver();
            solver.read(sc);
            remaining++;
            cases.add(solver);
        }
        
        for (int i = 0; i < Math.min(N, MAX_THREADS); i++)
            startNextCase();
        System.out.println("Remaining: " + remaining + ", Running: " + running);
        
        while (!finished()) {
            synchronized (sync) {
                sync.wait(1000);
            }
        }
        
        for (int cas = 1; cas <= N; cas++) {
            fw.print("Case #" + cas + ": ");
            Object res = cases.get(cas-1).result;
            if (res instanceof Double) 
                fw.printf("%.10f\n", res);
            else
                fw.printf("%s\n", res);
            fw.flush();
        }
        fw.close();
        sc.close();
    }

    static boolean finished() {
        synchronized (sync) {
            return remaining == 0;
        }
    }
    
    static void startNextCase() {
        synchronized (sync) {
            if (remaining > running) {
                cases.get(next++).start();
                running++;
            }
        }
    }
}
