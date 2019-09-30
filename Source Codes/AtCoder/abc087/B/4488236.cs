public class Hello{
    public static void Main(){

        int A = int.Parse(System.Console.ReadLine());
        int B = int.Parse(System.Console.ReadLine());
        int C = int.Parse(System.Console.ReadLine());
        int X = int.Parse(System.Console.ReadLine());
        int count = 0;

        for(int i = 0; i <= A; i++){
            for(int j = 0; j <= B; j++){
                for(int k = 0; k <= C; k++){
                    int ans = X - i * 500 - j * 100 - k * 50;
                    if(ans == 0) count++;
                }
            }
        }
        System.Console.WriteLine(count);
    }
}