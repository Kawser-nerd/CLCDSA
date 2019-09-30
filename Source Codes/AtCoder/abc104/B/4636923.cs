using System;
class Program{
    static void Main(string[] args){
        string str = Console.ReadLine();
        char[] cha = new char[str.Length];
        for(int i=0;i<str.Length;i++){
            cha[i] = str[i];
        }
        int cCount = 0;
        int cNumber = 0;
        for(int i=2;i<cha.Length-1;i++){
            if(cha[i].ToString() == "C"){cCount++; cNumber = i;}
        }
        bool isLow = true;
        for(int i=1;i<cha.Length;i++){
            if(i==cNumber){
                continue;
            }
            if(cha[i].ToString().CompareTo(cha[i].ToString().ToLower()) != 0){
                isLow = false;
            }
        }
        if(cCount == 1 && isLow && cha[0].ToString() == "A"){
            Console.WriteLine("AC");
        }else{
            Console.WriteLine("WA");
            
        }
    }
}