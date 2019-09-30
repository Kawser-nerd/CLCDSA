import java.util.*;

/**
 * Created by michael on 4/22/17.
 */
public class Express {

    static double min(double a, double b) {
        if(a == -1 && b == -1) {
            return -1;
        }
        if(a == -1) {
            return b;
        }
        if(b == -1) {
            return a;
        }
        return Math.min(a, b);

    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();

        for(int loop = 1; loop <= numCases; loop++) {
            int nCities = in.nextInt();
            int nPairs = in.nextInt();
            int[] horsedist = new int[nCities];
            int[] horsespeed = new int[nCities];
            for (int i = 0; i < nCities; i++) {
                horsedist[i] = in.nextInt();
                horsespeed[i] = in.nextInt();
            }
            int[][] routes = new int[nCities][nCities];
            for(int i = 0; i < nCities; i++) {
                for (int j = 0; j < nCities; j++) {
                    routes[i][j] = in.nextInt();
                }
            }

            double[][] legs = new double[nCities][nCities];
            for (int i = 0; i < nCities; i++) {
                for (int j = 0; j < nCities; j++) {
                    legs[i][j] = -1;
                }
            }

            for(int i = 0; i < nCities; i++) {
                PriorityQueue<Pair> frontier = new PriorityQueue<>();
                frontier.add(new Pair(0, i));
                Set<Integer> seen = new HashSet<>();
                while(!frontier.isEmpty()) {
                    Pair p = frontier.remove();
                    int dist = p.a;
                    int at = p.b;
                    if(seen.contains(at))
                        continue;
                    seen.add(at);

                    if(dist > horsedist[i])
                        continue;

                    legs[i][at] = min(legs[i][at], dist/(double)(horsespeed[i]));
                    for (int j = 0; j < nCities; j++) {
                        if(routes[at][j] != -1) {
                            frontier.add(new Pair(dist + routes[at][j], j));
                        }
                    }

                }

            }


            for(int k = 0; k < nCities; k++) {
                for (int i = 0; i < nCities; i++) {
                    for (int j = 0; j < nCities; j++) {
                        if(legs[i][k] != -1 && legs[k][j] != -1) {
                            legs[i][j] = min(legs[i][j], legs[i][k] + legs[k][j]);
                        }
                    }
                }
            }


            System.out.printf("Case #%d:", loop);
            for (int q = 0; q < nPairs; q++) {
                int start = in.nextInt();
                int end = in.nextInt();
                System.out.printf(" %.9f", legs[start-1][end-1]);
            }
            System.out.println();
        }
    }
}

class Pair implements Comparable<Pair> {
    int a;
    int b;

    public Pair(int a, int b) {
        this.a = a;
        this.b = b;
    }


    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        Pair pair = (Pair) o;

        if (a != pair.a) return false;
        return b == pair.b;
    }

    @Override
    public int hashCode() {
        int result = a;
        result = 31 * result + b;
        return result;
    }

    @Override
    public int compareTo(Pair pair) {
        if (a < pair.a || (a == pair.a && b < pair.b))
            return -1;
        if(a == pair.a && b == pair.b)
            return 0;
        return 1;
    }
}
