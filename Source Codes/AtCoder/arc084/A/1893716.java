import java.util.Scanner;
import java.util.stream.IntStream;

class Main{

    private static Scanner scan = new Scanner(System.in);

    public static void main(String args[]){
        int N = scan.nextInt();
        int A[] = loading(N),B[] = loading(N), C[] = loading(N);

        long[] BbtC = new long[N];
        int Cindex =0;
        for(int i=0;i<N;++i){
            while(Cindex < N && C[Cindex] <= B[i])++Cindex;
            BbtC[i] = N-Cindex;
        }
        for(int i=N-1;i>0;--i){
            BbtC[i-1] += BbtC[i];
        }

        long ans =0;
        int Bindex =0;
        for(int i=0;i<N;++i){
            while(Bindex < N && B[Bindex] <= A[i])++Bindex;
            ans += (Bindex < N ?BbtC[Bindex] : 0);
        }
        System.out.println(ans);

    }

    private static int[] loading(int N){
        return IntStream.range(0,N)
                .map(i -> scan.nextInt())
                .sorted()
                .toArray();
    }
}