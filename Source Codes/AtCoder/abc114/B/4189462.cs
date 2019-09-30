using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;


namespace AtCoder{

class Program{

static void Main(string[] args){

//int x = int.Parse(Console.ReadLine());
var s = Console.ReadLine().ToCharArray().Select(x => int.Parse(x.ToString())).ToArray();
int abs = 753;
for(int i = 0;i < s.Length - 2;i++){

int num = s[i]*100 + s[i+1]*10 + s[i+2];

if(abs > Math.Abs(753 - num)){

abs = Math.Abs(753 - num);

}

}
Console.WriteLine(abs);
}
}
}