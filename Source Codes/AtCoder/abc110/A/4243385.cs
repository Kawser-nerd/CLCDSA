using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;


namespace AtCoder{

class Program{

static void Main(string[] args){

//int n = int.Parse(Console.ReadLine());
var line = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
Array.Sort(line);

int a = line[2];
int b = line[1];
int c = line[0];

int answer = a*10+b+c;

Console.WriteLine(answer);
}

}

}