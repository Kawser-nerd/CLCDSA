import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.io.PrintWriter;

class Main{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        long N = scan.nextLong();
        long A = scan.nextLong();
        long B = scan.nextLong();

        if(A+B-1>N || A*B<N){
            System.out.println(-1);
            return;
        }

        List<Long> ansList = new ArrayList<>();
        long n=0,m=0,l=0;
        for(int i=1;i<=N;++i){
            if(N-i*B <= (A-i-1)+B){
                n=i;
                m=A-i-1;
                l=N-n*B-m;
                break;
            }
        }



        for(long i=0;i<n;++i){
            for(long j=B;j>0;--j)ansList.add(i*B+j);
        }
        for(long i=n*B+l;i>n*B;--i)ansList.add(i);
        for(long i=n*B+l+1;i<=N;++i)ansList.add(i);
        PrintWriter pw = new PrintWriter(System.out);
        for(int i=0;i<N;++i)pw.print(ansList.get(i)+(i==N-1 ? "\n":" "));
        pw.flush();pw.close();
    }
}