public class Hello{
    public static void Main(){

        int N = int.Parse(System.Console.ReadLine());
        int K = int.Parse(System.Console.ReadLine());
        int X = int.Parse(System.Console.ReadLine());
        int Y = int.Parse(System.Console.ReadLine());

        if(N <= K){
            System.Console.WriteLine(N * X);
        }else{
            System.Console.WriteLine(K * X + (N - K) * Y);
        }
    }
}