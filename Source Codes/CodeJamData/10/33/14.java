import java.util.*;
import java.io.*;

public class MainAza{
    public static int A[][], N, M, D[][];
    public static void main(String args[]) throws Exception{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        
        int T = Integer.parseInt(in.readLine());
        for (int t = 0; t < T; t++){
            ArrayList<Pair> X = new ArrayList<Pair>();
            String s[] = in.readLine().split(" ");
            N = Integer.parseInt(s[0]);
            M = Integer.parseInt(s[1]);
            A = new int[N][M];
            D = new int[N][M];
            for (int i = 0; i < N; i++){
                char ts[] = in.readLine().toCharArray();
                for (int j = 0; j < M/4; j++){
                    int[] G = getBytes(ts[j]);
                    for (int k = 0; k < 4; k++)
                        A[i][j*4+k] = G[k];
                }
            }
            int a = Math.min(N,M);
            int all = N*M; int found = 0;
            for (;a > 1;){
                 boolean flag = search(a);
                 if (flag) found++;
                 else {
                      if (found > 0){
                           X.add(new Pair(a,found)); all -= a*a*found;
                      }
                      a--;
                      found = 0;
                 }
            }
            if (all > 0) X.add(new Pair(1,all));
            System.out.println("Case #"+(t+1)+": "+X.size());
            for (int i = 0; i < X.size(); i++)
                System.out.printf("%d %d\n",X.get(i).a,X.get(i).n);
        }
    }
    public static void count(){
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                if (j > 0 && D[i][j-1] > 2){
                    D[i][j] = D[i][j-1]-1;
                }else{
                    int k = 0;
                    while (j + k +1 < M && D[i][j+k] != D[i][j+k+1])k++;
                    D[i][j] = k;
                }
                System.out.print(D[i][j] + " ");
            
            }
            System.out.println();
        }
        
    }
    public static int[] getBytes(char C){
        int T[] = new int[4];
        int h = 0;
        if (C <= '9') h = C - '0';
        else h = C - 'A' + 10;
        for (int i = 3; i >= 0; i--){
            T[i] = h%2; h/=2;
        }
        return T;   
    }
    public static boolean search(int a){
        for (int i = 0; i < N-a+1; i++)
            for (int j = 0; j < M-a+1; j++)
                if (A[i][j] < 2 && check(i,j,a)) return true;
        return false;
    }
    public static boolean check(int x, int y, int a){
        for (int i = 0; i < a; i++)
            for (int j = 0; j < a; j++)
                if (A[i+x][j+y] != (A[x][y] ^ ((i+j)%2))) return false;
//        System.out.printf("%d %d %d\n",x,y,a);        
        for (int i = x; i < x+a; i++)
            for (int j = y; j < y+a; j++) A[i][j] = 2;
        return true;
    }
}

class Pair{
    public int a, n;
    public Pair(int A, int N){
        a = A; n = N;
    }
}
