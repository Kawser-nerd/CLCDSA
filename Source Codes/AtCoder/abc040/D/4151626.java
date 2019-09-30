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

    int Q = scanner.nextInt();
    Yearly[] edgeAndQuery = new Yearly[Q + M];
    System.arraycopy(edges, 0, edgeAndQuery, 0, M);

    Query[] queries = new Query[Q];
    for (int i = 0; i < Q; i++) queries[i] = new Query(i, scanner.nextInt() - 1, scanner.nextInt());
    System.arraycopy(queries, 0, edgeAndQuery, M, Q);

    Arrays.sort(edgeAndQuery, (y1, y2) -> {
      if (y2.getYear() != y1.getYear()) return y2.getYear() - y1.getYear();
      if (y1 instanceof Query) return y2 instanceof Query ? 0 : -1;
      return y2 instanceof Edge ? 0 : 1;
    });

    UnionFind uf = new UnionFind(N);
    for (int i = 0; i < Q + M; i++) {
      Yearly obj = edgeAndQuery[i];
      if (obj instanceof Edge) {
        Edge e = (Edge) obj;
        uf.union(e.city1, e.city2);
      } else {
        Query q = (Query) obj;
        q.answer = uf.size(uf.find(q.city));
      }
    }

    Arrays.sort(queries, Comparator.comparingInt(q -> q.id));
    StringBuilder sb = new StringBuilder();
    for (int i = 0; i < Q; i++) sb.append(queries[i].answer).append('\n');
    sb.setLength(sb.length() - 1);
    System.out.println(sb.toString());
  }

  private interface Yearly {
    int getYear();
  }

  private static class Edge implements Yearly {
    final int city1;
    final int city2;
    final int year;

    private Edge(int city1, int city2, int year) {
      this.city1 = city1;
      this.city2 = city2;
      this.year = year;
    }

    @Override public int getYear() {
      return year;
    }
  }

  private static class Query implements Yearly {
    final int id;
    final int city;
    final int year;
    int answer = 1;

    private Query(int id, int city, int year) {
      this.id = id;
      this.city = city;
      this.year = year;
    }

    @Override public int getYear() {
      return year;
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