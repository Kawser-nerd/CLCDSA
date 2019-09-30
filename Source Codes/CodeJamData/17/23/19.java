package codejam.post;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.BitSet;
import java.util.LinkedList;

public class Post {
    public static void main(String[] args) throws IOException, CloneNotSupportedException {
        BufferedReader br = new BufferedReader(new FileReader("src/codejam/post/C-large.in"));

        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        for (int t_i = 1; t_i <= T; t_i++) {
            String[] split = br.readLine().split(" ");
            
            int N = Integer.parseInt(split[0]);
            int Q = Integer.parseInt(split[1]);

            int[] E = new int[N]; // km can go
            int[] S = new int[N]; // speed
            
            for (int i = 0; i < N; i++) {
                split = br.readLine().split(" ");

                E[i] = Integer.parseInt(split[0]);
                S[i] = Integer.parseInt(split[1]);
            }

            ArrayList<Path>[] D = new ArrayList[N];

            for (int i = 0; i < N; i++) {
                D[i] = new ArrayList<>();
                split = br.readLine().split(" ");
                for (int j = 0; j < N; j++) {
                    int d = Integer.parseInt(split[j]);
                    if (d != -1) {
                        D[i].add(new Path(j, d));
                    }
                }
            }

            double[] answer = new double[Q];
            
            for (int q_i = 0; q_i < Q; q_i++) {
                split = br.readLine().split(" ");
                int U = Integer.parseInt(split[0]) - 1;
                int V = Integer.parseInt(split[1]) - 1;

                LinkedList<Situation> q = new LinkedList<>();
                Situation initS = new Situation(N, U).saddle(E[U], S[U]);
                
                q.add(initS);
                ArrayList<Situation>[] best = new ArrayList[N];
                for (int i = 0; i < N; i++) best[i] = new ArrayList<>();
                best[U].add(initS);
                
                while (!q.isEmpty()) {
                    Situation s = q.pollFirst();
                    for (Path path : D[s.city]) {
                        if (s.canGo(path)) {
                            Situation s2 = s.go(path);
                            if (!isBetter(s2, best[path.city])) {
                                
//                                for (int i = best[path.city].size() - 1; i >= 0; i--) {
//                                    if (best[path.city].get(i).worse(s2)) {
//                                        best[path.city].remove(i);
//                                    }
//                                }
                                
                                q.add(s2);
                                best[path.city].add(s2);
                            }
                            
                            if (!s.horseUsed.get(path.city)) {
                                Situation s3 = s2.saddle(E[path.city], S[path.city]);
                                if (!isBetter(s3, best[path.city])) {

//                                    for (int i = best[path.city].size() - 1; i >= 0; i--) {
//                                        if (best[path.city].get(i).worse(s3)) {
//                                            best[path.city].remove(i);
//                                        }
//                                    }
                                    
                                    q.add(s3);
                                    best[path.city].add(s3);
                                }
                            }
                        }
                    }
                    s.pending = false;
                }
                
                double fastest = Double.MAX_VALUE;
                for (Situation s : best[V]) {
                    if (s.t < fastest) {
                        fastest = s.t;
                    }
                }
                answer[q_i] = fastest;
            }

            StringBuilder answerString = new StringBuilder();
            for (double anAnswer : answer) {
                answerString.append(" ").append(anAnswer);
            }
            System.err.println(t_i);
            sb.append("Case #").append(t_i).append(":").append(answerString).append("\n");
        }

        Files.write(Paths.get("src/codejam/post/out.out"), sb.toString().getBytes());
        System.out.println(sb.toString());
    }

    private static boolean isBetter(Situation s2, ArrayList<Situation> situations) {
        for (Situation situation : situations) {
            if (s2.worse(situation)) {
                return true;
            }
        }
        return false;
    }

    static class Situation implements Cloneable {
        int city = -1;
        int km = 0;
        int v = 1;
        double t = 0;
        BitSet horseUsed;
        boolean pending = true;

        public Situation(int N, int city) {
            this.city = city;
            this.horseUsed = new BitSet(N);
        }
        
        boolean canGo(Path path) {
            return this.km >= path.km;
        }
        
        Situation go(Path path) throws CloneNotSupportedException {
            Situation s2 = (Situation) this.clone();
            s2.city = path.city;
            s2.km -= path.km;
            s2.t += 1. * path.km / v;
            s2.horseUsed = (BitSet) this.horseUsed.clone();
            s2.pending = true;
            return s2;
        }
        
        Situation saddle(int km, int v) throws CloneNotSupportedException {
            Situation s2 = (Situation) this.clone();
            s2.km = km;
            s2.v = v;
            s2.pending = true;
            s2.horseUsed = (BitSet) this.horseUsed.clone();
            s2.horseUsed.set(city);
            return s2;
        }
        
        boolean worse(Situation that) {
            return this.km <= that.km && this.v <= that.v && this.t >= that.t;
        }
    }
    
    static class Path {
        int city;
        int km;

        public Path(int city, int km) {
            this.city = city;
            this.km = km;
        }
    }
}
