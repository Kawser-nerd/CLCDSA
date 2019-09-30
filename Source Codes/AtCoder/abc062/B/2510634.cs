using System;
using System.Collections.Generic;
public class Hello{
    static string MakeEdge(int width){
        string edge = "";
        for(int i = 0;i < width + 2;i++){
            edge += "#";
        }
        return edge;
    }
    public static void Main(){
        string[] input = Console.ReadLine().Split(' ');
        int H = int.Parse(input[0]);
        int W = int.Parse(input[1]);
        
        var answers = new List<string>();
        
        answers.Add(MakeEdge(W));//????
        for(int i = 0;i < H;i++){
            string s = Console.ReadLine();
            answers.Add("#" + s + "#");
        }
        answers.Add(MakeEdge(W));//????
        //?????
        foreach(string ans in answers){
            Console.WriteLine(ans);
        }
    }
}