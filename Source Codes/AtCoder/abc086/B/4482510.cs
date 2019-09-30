public class Hello{
    public static void Main(){

        string[] num = System.Console.ReadLine().Split(' ');
        int ab = int.Parse(num[0] + num[1]);

        bool state = false;
        for(int i = 0; i <= ab; i++){
            if(i*i == ab){
                state = true;
                break;
            }
        }
        System.Console.WriteLine( state ? "Yes" : "No");
    }
}