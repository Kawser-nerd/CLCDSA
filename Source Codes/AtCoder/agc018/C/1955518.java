import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

class ABC{
    long A,B,C;
    public ABC(long a,long b,long c){
        A=a;
        B=b;
        C=c;
    }
}

class Main{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int X = scan.nextInt();
        int Y = scan.nextInt();
        int Z = scan.nextInt();
        int N = X+Y+Z;

        ABC[] abc = new ABC[N];
        for(int i=0;i<N;++i){
            abc[i] = new ABC(scan.nextLong(),scan.nextLong(),scan.nextLong());
        }

        Arrays.sort(abc,(a,b)->(int)((b.A-b.B) - (a.A-a.B)));

        PriorityQueue<ABC> CA = new PriorityQueue<>((a,b) -> (int)((b.C-b.A) - (a.C-a.A)));
        PriorityQueue<ABC> CB = new PriorityQueue<>((a,b) -> (int)((b.C-b.B) - (a.C-a.B)));
        for(int i=0;i<X;++i)CA.add(abc[i]);
        for(int i=0;i<Y;++i)CB.add(abc[N-1-i]);

        long[] sumA = new long[N];
        long[] sumB = new long[N];
        sumA[0] = abc[0].A;
        for(int i=1;i<N;++i)sumA[i] = sumA[i-1]+abc[i].A;
        sumB[N-1] = abc[N-1].B;
        for(int i=N-2;i>=0;--i)sumB[i] = sumB[i+1]+abc[i].B;

        long[] maxAk = new long[N];
        long[] maxBk = new long[N];
        maxAk[X-1] = sumA[X-1];
        for(int i=X;i<X+Z;++i){
            CA.add(abc[i]);
            ABC maxca = CA.poll();
            maxAk[i] = maxAk[i-1] + abc[i].A + maxca.C - maxca.A;
        }
        maxBk[N-Y] = sumB[N-Y];
        for(int i=N-1-Y; i>=N-Y-Z;--i){
            CB.add(abc[i]);
            ABC maxcb = CB.poll();
            maxBk[i] = maxBk[i+1] + abc[i].B + maxcb.C - maxcb.B;
        }
        long ans = 0;
        for(int i=X-1;i<N-Y;++i){
            ans = Math.max(ans, maxAk[i] + maxBk[i+1]);
        }
        System.out.println(ans);
    }
}