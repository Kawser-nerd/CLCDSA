public class Hello{
    public static void Main(){

        string[] num = System.Console.ReadLine().Split(' ');
        int[] group ={1,3,1,2,1,2,1,1,2,1,2,1};
        int x = int.Parse(num[0]);
        int y = int.Parse(num[1]);

        if(group[x - 1] == group[y - 1]){
            System.Console.WriteLine("Yes");
        }else{
            System.Console.WriteLine("No");
        }
    }
}