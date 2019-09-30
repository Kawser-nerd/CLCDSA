import java.util.Scanner;
import java.util.Arrays;
class Main{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        int K = scan.nextInt();
        double Trate = 0;
        double Vrate = 0;

        int video[] = new int[N];
        for(int i = 0; i < N; i++){
            video[i] = scan.nextInt();
        }
        Arrays.sort(video);
        int len = video.length;
        //System.out.println(len);

        for(int i = 0; i < K; i++){
            Vrate = video[len - K + i];
            Trate = (Trate + Vrate)/2;
        }
        System.out.println(String.format("%.6f", Trate));

    }
}