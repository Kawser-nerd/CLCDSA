using System;

class Program{
    static void Main(string[] args){
        string str = Console.ReadLine();
        int N = str.Length;
        for(int i=0;i<N-1;i++){
            if(str[i]==str[i+1]){
                Console.WriteLine("{0} {1}",i+1,i+2);
                return;
            }
        }
        for(int i=0;i<N-2;i++){
            if(str[i]==str[i+2]){
                Console.WriteLine("{0} {1}",i+1,i+3);
                return;
            }
        }
        Console.WriteLine("-1 -1");
    }
}