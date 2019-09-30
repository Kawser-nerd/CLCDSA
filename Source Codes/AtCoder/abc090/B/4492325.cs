public class Hello{
    public static void Main(){

        string[] str = System.Console.ReadLine().Split(' ');
        int A = int.Parse(str[0]);
        int B = int.Parse(str[1]);
        int count = 0;
        
        for(int i = A; i <= B; i++){
            string num = i.ToString();
            if(num[0] == num[4] && num[1] == num[3]) count++;
        }
        System.Console.WriteLine(count);
    }
}