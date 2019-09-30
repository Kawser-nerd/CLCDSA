using System;
using System.Linq;
using System.Collections.Generic;
using static System.Console;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var n = int.Parse(ReadLine());
        var input = new string[n];
        for(var i = 0; i < n; i++)
        {
            input[i] = ReadLine();
        }
        Array.Sort(input);

        var pairArr = input
            .Distinct()
            .Select(s => s.Split('-')
                .Select(a => int.Parse(a)).ToArray()).ToArray();
        var pairLinkList = new LinkedList<int[]>(pairArr);
        foreach(var nod in pairLinkList)
        {
            nod[0] -= nod[0] % 5;
            if(nod[1]%5 != 0){
                nod[1] += 5 - nod[1] % 5;
                if(nod[1]%100 >= 60){
                    nod[1] -= 60;
                    nod[1] += 100;
                }
                if(nod[1] > 2400)
                {
                    nod[1] = 2400;
                }
            }
        }
        
        LinkedListNode<int[]> lastNode = pairLinkList.Last;
        for(LinkedListNode<int[]> node = pairLinkList.First; node != lastNode; node = node.Next)
        {
            var nextNode = node.Next;
            while (node.Value[1] >= nextNode.Value[0])
            {
                node.Value[1] = Max(node.Value[1], nextNode.Value[1]);
                pairLinkList.Remove(nextNode);
                if(node.Next == null)
                {
                    goto exit;
                }
                else
                {
                    nextNode = node.Next;
                }
            }
        }
        exit:

        foreach (var i in pairLinkList)
        {
            WriteLine($"{i[0]:0000}-{i[1]:0000}");
        }
    }
}