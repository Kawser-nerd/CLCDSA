public class Hello{
    public static void Main(){

        string[] num = System.Console.ReadLine().Split(' ');
        int A = int.Parse(num[0]);
        int B = int.Parse(num[1]);
        int C = int.Parse(num[2]);
        
        if(C >= A && C <= B){
            System.Console.WriteLine("Yes");
        }else{
            System.Console.WriteLine("No");
        }
    }
}