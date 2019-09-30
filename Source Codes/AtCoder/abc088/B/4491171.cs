public class Hello{
    public static void Main(){

        int N = int.Parse(System.Console.ReadLine());
        string[] str = System.Console.ReadLine().Split(' ');
        int[] a = new int[N];
        for(int i = 0; i < N; i++){
            a[i] = int.Parse(str[i]);
        }
        
        System.Array.Sort(a);
        
        int Alice = 0;
        int Bob = 0;
        for(int i = N - 1; i >= 0; i -= 2){
            Alice += a[i];
        }
        for(int i = N - 2; i >= 0; i -= 2){
            Bob += a[i];
        }
        System.Console.WriteLine(Alice - Bob);
    }
}