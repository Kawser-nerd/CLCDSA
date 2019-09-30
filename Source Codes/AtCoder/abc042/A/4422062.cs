public class Hello{
    public static void Main(){

        string[] input = System.Console.ReadLine().Split(' ');
        int A = int.Parse(input[0]);
        int B = int.Parse(input[1]);
        int C = int.Parse(input[2]);
        
        if((A == 5 && B == 5 && C == 7) || (A == 5 && B == 7 && C == 5) || (A == 7 && B == 5 && C == 5)){
            System.Console.WriteLine("YES");
        }else{
            System.Console.WriteLine("NO");
        }
    }
}