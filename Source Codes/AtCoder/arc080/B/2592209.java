import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int H = sc.nextInt();
        int W = sc.nextInt();
        int N = sc.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }
        System.out.println( solve(H, W, N, A) );
    }

    private static String solve(int H, int W, int N, int[] A) {
        List<Integer> numbers = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            int n = i + 1;
            int a = A[i];
            for (int j = 0; j < a; j++) {
                numbers.add(n);
            }
        }

        StringJoiner j = new StringJoiner("\n");
        for (int h = 0; h < H; h++) {
            int start = h * W;
            int end = h * W + W;
            List<Integer> line = new ArrayList<>(numbers.subList(start, end));
            if( h % 2 == 1 ) {
                Collections.reverse(line);
            }
            StringJoiner j2 = new StringJoiner(" ");
            line.forEach( i -> j2.add(i.toString()) );
            j.add( j2.toString() );
        }
        return j.toString();
    }
}