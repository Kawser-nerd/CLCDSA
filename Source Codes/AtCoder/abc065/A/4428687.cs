public class Hello{
    public static void Main(){

        string[] num = System.Console.ReadLine().Split(' ');

        int X = int.Parse(num[0]);
        int A = int.Parse(num[1]);
        int B = int.Parse(num[2]);
        
        if( 0 - A + B <= 0){
            System.Console.WriteLine("delicious");
        }else if(0 - A + B <= X){
            System.Console.WriteLine("safe");
        }else{
            System.Console.WriteLine("dangerous");
        }
    }
}