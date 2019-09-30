using System;
class Program
{    
    static void Main(String[] args){
    int count = 0;
    int i = 0;
   String cha = Console.ReadLine();
  for(i=0;i<4;i++){
    if (cha[i]=='+'){
      count++;
    }else{
        count--;
    }
  }
   Console.WriteLine(count);
}
}