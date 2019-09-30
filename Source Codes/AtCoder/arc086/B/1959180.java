import java.util.Scanner;
import java.util.stream.IntStream;

class Main{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        int[] a = IntStream.range(0,N).map(i -> scan.nextInt()).toArray();
        int index = 0;
        for(int i=0;i<N;++i)if(Math.abs(a[index]) < Math.abs(a[i]))index = i;
        System.out.println(2*N-1);
        for(int i=0;i<N;++i)System.out.println((index+1)+" "+(i+1));
        if(a[index]>0){
            for(int i=2;i<=N;++i)System.out.println((i-1)+" "+i);
        }else{
            for(int i=N-1;i>=1;--i)System.out.println((i+1)+" "+i);
        }
    }
}