public class Hello{
    public static void Main(){

        int N = int.Parse(System.Console.ReadLine());
        int[] d = new int[N];
        for(int i = 0; i < N; i++) d[i] = int.Parse(System.Console.ReadLine());

        //??????????
        System.Array.Sort(d);

        //???????????????(??1???)
        int count = 1;
        for(int i = 0; i < N - 1; i++){
            if(d[i] != d[i+1]) count++;
        }
        System.Console.WriteLine(count);
    }
}