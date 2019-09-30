import java.util.Scanner;

public class Main {

    static int N, A, B, C;
	static int[] l;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        A = sc.nextInt();
        B = sc.nextInt();
        C = sc.nextInt();
        l = new int[N];
        for(int i = 0; i < N; i++) {
            l[i] = sc.nextInt();
            // System.out.println("input sc >> " + l[i]);
        }
        System.out.println(cost(0,0,0,0));
        sc.close();
    }

    static int cost(int depth, int a, int b, int c){
        int INF = (int) 10e8;
        int pattern0, pattern1, pattern2, pattern3;
        if(depth == N){
            if(a>0 && b>0 && c>0){
                return Math.abs(a-A) + Math.abs(b-B) + Math.abs(c-C) - 30;
            } else {
                return INF;
            }
        }
        pattern0 = cost(depth+1, a, b, c);
        pattern1 = cost(depth+1, a+l[depth], b, c) + 10;
        pattern2 = cost(depth+1, a, b+l[depth], c) + 10;
        pattern3 = cost(depth+1, a, b, c+l[depth]) + 10;

        return Math.min(Math.min(pattern0, pattern1), Math.min(pattern2, pattern3));
    }

    Main() {

    }
}