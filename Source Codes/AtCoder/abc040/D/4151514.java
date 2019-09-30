import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int N = scanner.nextInt();
    int M = scanner.nextInt();
    Edge[] edges = new Edge[M];
    for (int i = 0; i < M; i++)
      edges[i] = new Edge(scanner.nextInt() - 1, scanner.nextInt() - 1, scanner.nextInt());
    Arrays.sort(edges, (e1, e2) -> e2.year - e1.year);

    int Q = scanner.nextInt();
    Query[] queries = new Query[Q];
    for (int i = 0; i < Q; i++) queries[i] = new Query(i, scanner.nextInt() - 1, scanner.nextInt());
    Arrays.sort(queries, (q1, q2) -> q2.year - q1.year);

    UnionFind uf = new UnionFind(N);
    int j = 0;
    while (j < Q && queries[j].year >= edges[0].year) j++;
    for (int i = 0; i < M; i++) {
      uf.union(edges[i].city1, edges[i].city2);
      for (; j < Q && (i == M - 1 || queries[j].year >= edges[i + 1].year); j++) {
        queries[j].answer = uf.size(uf.find(queries[j].city));
      }
    }

    Arrays.sort(queries, Comparator.comparingInt(q -> q.id));
    StringBuilder sb = new StringBuilder();
    for (int i = 0; i < Q; i++) sb.append(queries[i].answer).append('\n');
    System.out.println(sb.toString());
  }

  private static class Edge {
    final int city1;
    final int city2;
    final int year;

    private Edge(int city1, int city2, int year) {
      this.city1 = city1;
      this.city2 = city2;
      this.year = year;
    }
  }

  private static class Query {
    final int id;
    final int city;
    final int year;
    int answer = 1;

    private Query(int id, int city, int year) {
      this.id = id;
      this.city = city;
      this.year = year;
    }
  }

  private static class UnionFind {
    private final int[] table;
    private final int[] ranks;
    private final int[] sizes;

    UnionFind(int size) {
      this.table = new int[size];
      this.ranks = new int[size];
      this.sizes = new int[size];
      for (int i = 0; i < size; i++) {
        table[i] = i;
        sizes[i] = 1;
      }
    }

    public int size(int x) {
      return sizes[x];
    }

    int find(int x) {
      if (table[x] != x) {
        table[x] = find(table[x]);
      }
      return table[x];
    }

    void union(int x, int y) {
      int xRoot = find(x);
      int yRoot = find(y);
      if (xRoot == yRoot) return;

      if (ranks[xRoot] < ranks[yRoot]) {
        int tmp = xRoot;
        xRoot = yRoot;
        yRoot = tmp;
      }

      table[yRoot] = xRoot;
      sizes[xRoot] += sizes[yRoot];
      if (ranks[xRoot] == ranks[yRoot]) ranks[xRoot]++;
    }
  }
}