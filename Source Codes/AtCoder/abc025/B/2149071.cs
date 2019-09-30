using System;
public class Hello{
    static int dist(int step,int a,int b){
        if(step < a){
            return a;
        }else if(b < step){
            return b;
        }else{
            return step;
        }
    }
    public static void Main(){
        int[] a = Array.ConvertAll(Console.ReadLine().Split(' '),int.Parse);
        int N = a[0];
        int A = a[1];
        int B = a[2];
        int pos = 0;
        for(int i = 0;i < N;i++){
            string[] s = Console.ReadLine().Split(' ');
            int step = int.Parse(s[1]);
            switch(s[0]){
                case "East":
                    pos += dist(step,A,B);
                break;
                case "West":
                    pos -= dist(step,A,B);
                break;
                default:
                break;
            }
        }
        if(pos < 0){
            Console.WriteLine($"West {Math.Abs(pos)}");
        }else if(0 < pos){
            Console.WriteLine($"East {pos}");
        }else{
            Console.WriteLine("0");
        }
    }
}