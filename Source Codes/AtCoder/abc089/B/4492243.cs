public class Hello{
    public static void Main(){
        
        int N = int.Parse(System.Console.ReadLine());
        string[] str = System.Console.ReadLine().Split(' ');

        bool state = true;
        for(int i = 0; i < N; i++){
            if(str[i].Equals("Y")) state = false;
        }
        System.Console.WriteLine(state ? "Three" : "Four");
    }
}