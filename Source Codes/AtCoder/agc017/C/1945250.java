import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.IntStream;
class Main{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        int M = scan.nextInt();
        int[] A = IntStream.range(0,N).map(i -> scan.nextInt()).toArray();

        int[] num = new int[N+1];
        int[] line = new int[N+1];
        Arrays.fill(num,0);
        Arrays.fill(line,0);
        for(int i=0;i<N;++i)num[A[i]]++;
        for(int i=1;i<=N;++i){
            for(int j=0;j<num[i];j++){
                if(i>j)line[i-j]++;
            }
        }

        int gap=0;
        for(int i=1;i<=N;++i)if(line[i]<=0)++gap;

        while(M-->0){
            int x = scan.nextInt() -1;
            int y = scan.nextInt();

            int a = A[x];//?????????
            A[x] = y;
            --num[a];
            if(a-num[a]>0){
                --line[a-num[a]];
                if(line[a-num[a]] == 0)++gap;
            }
            ++num[y];
            if(y-num[y] +1 >0){
                if(line[y-num[y]+1] == 0)--gap;
                ++line[y-num[y] +1];
            }
            System.out.println(gap);
//            for(int i=1;i<=N;++i)System.out.print(line[i] + " ");
//            System.out.println();
        }
    }
}