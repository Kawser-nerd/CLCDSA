using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;


namespace AtCoder{

class Program{

static void Main(string[] args){

var answer = "War";

var line = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
var lineX = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
var lineY = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();


int z = lineY.Min();
foreach(int x in lineX){

if(line[2] >= z){break;}
if(line[3] < z){break;}

if(z > x){
answer = "No War";
}
else{
answer = "War";
break;
}
}

Console.WriteLine(answer);
}

}

}