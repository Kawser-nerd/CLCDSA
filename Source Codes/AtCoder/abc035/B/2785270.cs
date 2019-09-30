using System;
using System.Collections.Generic;
using System.Linq;
public class Hello{
    public static void Main(){
        var s = Console.ReadLine();
        var t = int.Parse(Console.ReadLine());
        var x = Math.Abs(s.Count(i => i == 'R') - s.Count(i => i == 'L'));
        var y = Math.Abs(s.Count(i => i == 'U') - s.Count(i => i == 'D'));
        var q = s.Count(i => i == '?');
        if(t == 1){
            Console.WriteLine(x + y + q);
        }else{
            if(x + y >= q){
                Console.WriteLine(x + y - q);
            }else{
                if((x + y - q) % 2 == 0){
                    Console.WriteLine(0);
                }else{
                    Console.WriteLine(1);
                }
            }
        }
    }
}